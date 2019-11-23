#include <iostream>
#include <vector>
#include <map>
using  namespace std;

#include "Elevators.h"

int Elevators::count=0;


Elevators::Elevators():elevatorWeightCounter{0}
{
    string uniqueId =  "ELEV";
    string unique = uniqueId + std::to_string(count);
    ElevatorId = unique;
    count = count + 1;

    // Initialize all  DEST Floor to bool False

    //cout << "HIGEST " << higestFloor << endl;



}
Elevators::~Elevators()
{

}

void Elevators::elevatorIntroduce()
{

    cout << "\t\tElevator ID:\t"<<ElevatorId<< endl;
    cout << "\t\tElevator Going : \t"<<elevatorDirection<< endl;
    cout << "\t\tMax Capacity :\t"<< maxCapacity<< endl;
	cout << "\t\tHightest Floor:\t" << higestFloor << endl;
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

bool Elevators::checkDoor() {
	return door;
}

void Elevators::toggleDoor() {
	door = !door;
}