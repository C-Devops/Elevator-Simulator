#include <map>
#include <vector>
#include "partitions.h"
#include "Elevators.h"
#include "Passenger.h"

partitions::partitions(Elevators* e, partitions* n) {
    //partition constructor
    elevator = e;
    next = n;
}

partitions::~partitions() {
    //partition deconstructor
}

void partitions::elevatorTask(map<int, vector<Passenger *>> * Levels) {
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
	elevator->elevatorOperator(Levels);
    // Elevator drop off passengers
    // collect waiting passengers from floor
    // check nearest destination in directions of travel
    // Elevator close door
    elevator->toggleDoor();
	cout << "Elevator: " << elevator->ElevatorId << ", Door Close!" << " Floor : " << elevator->currentFloor << endl;
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