#include <iostream>
#include <vector>
#include <map>
#include <deque>
#include <iterator>
using  namespace std;

#include "Elevators.h"
int Elevators::count=0;


Elevators::Elevators(int highestFloor, int maxCap):elevatorWeightCounter{0}
{
    string uniqueId =  "ELEV";
    string unique = uniqueId + std::to_string(count);
    ElevatorId = unique;
    count = count + 1;
	higestFloor = highestFloor;
	maxCapacity = maxCap;
	passengerfloorflags = new bool[higestFloor];
	currentDirection = 'N';
	for (int i = 0; i < higestFloor+1; i++) {
		deque<Passenger*>* tmp = new deque<Passenger*>;
		Boarded.insert(pair<int, deque<Passenger *>> (i,*tmp));
	}
}
Elevators::~Elevators()
{

}

void Elevators::elevatorIntroduce()
{

    cout << "\t\tElevator ID:\t"<<ElevatorId<< endl;
	cout << "\t\tElevator current floor\t" << currentFloor << endl; ////////////////////// 11/30
    cout << "\t\tElevator Going : \t"<<elevatorDirection<< endl;
    cout << "\t\tMax Capacity :\t"<< maxCapacity<< endl;
    cout << "\t\tHightest Floor:\t" << higestFloor << endl;
	cout << "\t\tCurrent Direction:\t" << currentDirection << endl;
    cout <<"\n";

}

void Elevators::increamentFloor() {
    switch (elevatorDirection) {
        case 'U':
            currentFloor++;
            break;
        case 'D':
            currentFloor--;
            break;
        default:
            cout << "Elevator is not moving." << endl;
    }
}

bool Elevators::checkDoor()
{
    return door;
}

void Elevators::toggleDoor() {
    door = !door;
}

void Elevators::listPassDest() {

}

void Elevators::elevatorOperator(map<int, vector<Passenger*>>* Levels) {
	vector<Passenger*>::iterator it_v;
	cout << "Passengers at this floor" << currentFloor << endl;

	//drop off passengers
	if (!Boarded[currentFloor].empty()) {
		//take out passengers from the map(floor, deque<passengers>) 
		Boarded[currentFloor].clear(); // should populate destination levels?
	}
	else {
		cout << "No passengers are getting off at this floor" << endl;
	}

	//pick up passengers
	if (!(*Levels).at(currentFloor).empty()) {
		cout << "Floor: " << currentFloor << ", Number of passengers waiting: " << (*Levels).at(currentFloor).size() << endl;
		for (int i = 0; i < (*Levels).at(currentFloor).size(); i++) {//it_v = (*Levels).at(currentFloor).begin(); it_v < (*Levels).at(currentDirection).end(); it_v++) {
			//(*Levels).at(currentFloor).at(i)->introduce();

			//if passenger want to go in the same direction of the elevator
			if ((*Levels).at(currentFloor).at(i)->DirectionPassenger == currentDirection) {
				Boarded[(*Levels).at(currentFloor).at(i)->DestinationFloor].push_back((*Levels).at(currentFloor).at(i));
				it_v = (*Levels).at(currentFloor).begin() + i;
				((*Levels).at(currentFloor)).erase(it_v);
			}
			else {
				cout << "No passengers are boarding at this floor" << endl;
			}
		}
	}
	else {
		cout << "Floor is empty" << endl;
	}
}