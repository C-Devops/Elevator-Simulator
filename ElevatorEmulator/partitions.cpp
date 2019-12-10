#include <map>
#include <vector>
#include "partitions.h"
#include "Elevators.h"
#include "Passenger.h"

partitions::partitions(Elevators* e, partitions* n, char callType) {
    //partition constructor
    elevator = e;
    next = n;
	callRespondType = callType;
}

partitions::~partitions() {
    //partition deconstructor
}

map<int, vector<Passenger*>> *partitions::elevatorTask(map<int, vector<Passenger *>> * Levels) {
	map<int, vector<Passenger*>> *d = new map<int , vector<Passenger*>>;
	for (int i = 0; i < elevator->higestFloor+1; i++) {
		vector<Passenger*>* tmp = new vector<Passenger*>;
		(*d).insert(pair<int, vector<Passenger*>>(i, *tmp));
	}
	//check if door is open
    if (!elevator->checkDoor()) {
        // Elevator open door
        elevator->toggleDoor();
        cout <<  "Elevator: " << elevator->ElevatorId << ", Door Open!" << " Floor : "<<  elevator->currentFloor << endl;
    }
    else {

    }
	/*
         * Passenger should Board Here
         * Check Levels
         *
         */

	if (elevator->currentTask == 'R') {
		//Regular call type
		d = elevator->normalOperation(Levels);
	}
	else if (elevator->currentTask == 'P') {
		//Emergercy pick up priority call type 
		d = elevator->priorityOperation(Levels);
	}
	else if (elevator->currentTask == 'E') {
		//Evac all
		d = elevator->evacOperation(Levels);
	}
	else {
		cout << "Elevator " << elevator->ElevatorId << " is waiting to be called" << endl;
	}

    // Elevator drop off passengers
    // collect waiting passengers from floor
    // check nearest destination in directions of travel
    // Elevator close door
    elevator->toggleDoor();
	cout << "Elevator: " << elevator->ElevatorId << ", Door Close!" << " Floor : " << elevator->currentFloor << endl;
	//cout << endl;
	return d;
}

void partitions::setNextPartition(partitions * n) {
    next = n;
}

partitions* partitions::getNextPartitions() {
	if (next != nullptr) {
		return next;
	}
	else {
		return nullptr;
	}
}