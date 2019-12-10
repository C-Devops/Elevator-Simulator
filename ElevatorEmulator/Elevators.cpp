#include <iostream>
#include <vector>
#include <map>
#include <deque>
#include <iterator>
using  namespace std;

#include "Elevators.h"
#include "ElevatorDirection.h"
int Elevators::count=0;


Elevators::Elevators(int highestFloor, int maxCap):elevatorWeightCounter{0}
{
    string uniqueId =  "ELEV";
    string unique = uniqueId + std::to_string(count);
    ElevatorId = unique;
    count = count + 1;
	higestFloor = highestFloor;
	maxCapacity = maxCap;
	currentCapacity = 0;
	passengerfloorflags = new bool[higestFloor];
	currentDirection = 'N';
	currentTask = 'N';

	Dest = new map<int, vector<Passenger*>>;
	for (int i = 0; i < higestFloor+1; i++) {
		deque<Passenger*>* tmp = new deque<Passenger*>;
		Boarded.insert(pair<int, deque<Passenger *>> (i,*tmp));
		vector<Passenger*>* vtmp = new vector<Passenger*>;
		(*Dest).insert(pair<int, vector<Passenger*>>(i, *vtmp));
	}
}
Elevators::~Elevators()
{

}

void Elevators::elevatorIntroduce()
{

    cout << "\t\tElevator ID:\t"<<ElevatorId<< endl;
	cout << "\t\tElevator current floor\t" << currentFloor << endl; ////////////////////// 11/30
    //cout << "\t\tElevator Going : \t"<<elevatorDirection<< endl;
    cout << "\t\tMax Capacity :\t"<< maxCapacity<< endl;
	cout << "\t\tCurrent Capacity: \t" << currentCapacity << endl;
    cout << "\t\tHightest Floor:\t" << higestFloor << endl;
	cout << "\t\tCurrent Direction:\t" << currentDirection << endl;
	cout << "\t\tNext destination:\t" << currentDestination << endl;
    cout <<"\n";

}

void Elevators::increamentFloor() {
	if (currentDirection == 'U' and currentFloor < higestFloor) {
		currentFloor++;
	}
	else if (currentDirection == 'D' and currentFloor > 0) {
		currentFloor--;
	}
	else {
		cout << "Elevator is not moving. " << currentDirection << " != " << currentFloor << endl;
	}
	/*switch (currentDirection) {
        case 'U':
            currentFloor++;
            break;
        case 'D':
            currentFloor--;
            break;
        default:
            cout << "Elevator is not moving." << endl;
    }*/
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

map<int, vector<Passenger*>> *Elevators::normalOperation(map<int, vector<Passenger*>>* Levels) {
	vector<Passenger*>::iterator it_v;
	vector<Passenger*>* newvec;
	//map<int, vector<Passenger*>> *tempDest;
	for (int i = 0; i <= higestFloor; i++) {
		newvec = new vector<Passenger*>;
		(*Dest).insert(pair<int, vector<Passenger*>>(i, *newvec));
	}
	cout << "Elevator "<< ElevatorId <<" stop at this floor" << currentFloor << endl;

	//dorp off passengers
	if (!Boarded[currentFloor].empty()) {
		for (int q = 0; q < Boarded[currentFloor].size(); q++) {
			(*Dest)[currentFloor].push_back(Boarded[currentFloor].at(q));
			currentCapacity = currentCapacity - Boarded[currentFloor].at(q)->Weight;
		}
		Boarded[currentFloor].clear();
	}
	else {
		cout << "No passengers are getting off at this floor" << endl;
	}


	//pick up passengers
	if (!(*Levels).at(currentFloor).empty()) {
		int totalBoarded = 0;
		cout << "Floor: " << currentFloor << ", Number of passengers waiting: " << (*Levels).at(currentFloor).size() << endl;
		for (int i = 0; i < (*Levels).at(currentFloor).size(); i++) {//it_v = (*Levels).at(currentFloor).begin(); it_v < (*Levels).at(currentDirection).end(); it_v++) {
			//(*Levels).at(currentFloor).at(i)->introduce();

			//if passenger want to go in the same direction of the elevator
			if ((*Levels).at(currentFloor).at(i)->DirectionPassenger == currentDirection and (*Levels).at(currentFloor).at(i)->Weight+currentCapacity <= maxCapacity) {
				//add passenger to elevator stop queue also acts like destination list
				Boarded[(*Levels).at(currentFloor).at(i)->DestinationFloor].push_back((*Levels).at(currentFloor).at(i));

				//add weight to currentCapacity
				currentCapacity = (*Levels).at(currentFloor).at(i)->Weight + currentCapacity;
				
				//to count the number of passengers boarded the elevator
				totalBoarded = totalBoarded + 1;
				
				//remmove passegner from level
				it_v = (*Levels).at(currentFloor).begin();
				((*Levels).at(currentFloor)).erase(it_v);
			}
			else {
				cout << "No passengers are boarding at this floor. Current weigth: " << currentCapacity << endl;
			}
		}
		cout << "Total number of passengers boarded at this floor: " << totalBoarded << endl;
	}
	else {
		cout << "Floor is empty" << endl;
	}

	int total = 0;
	for (int i = 0; i < Boarded.size(); i++) {
		total = total + Boarded[i].size();
	}
	cout << "Total passengers on board: " << total << endl;

	//set next destination from internal passengers
	int countLoop = 0;
	findNextDest(currentDirection, countLoop);

	return Dest;
}

void Elevators::findNextDest(char direction, int count) {
	if (count < 2) {
		if (direction == 'U' and currentFloor < higestFloor) {
			for (int i = currentFloor + 1; i <= higestFloor; i++) {
				if (!Boarded[i].empty()) {
					currentDestination = i;
					break;
				}
			}
		}
		else if (direction == 'D' and currentFloor > 0) {
			for (int i = currentFloor - 1; i >= 0; i--) {
				if (!Boarded[i].empty()) {
					currentDestination = i;
					break;
				}
			}
		}
		else {
			if (currentFloor == higestFloor) {
				currentDirection = 'D';
				findNextDest('D', count+1);
			}
			else if (currentFloor == 0) {
				currentDirection = 'U';
				findNextDest('U', count+1);
			}
			else {
				cout << "Error findNextDest elevator has no direction" << endl;
			}
		}
	}
}

map<int, vector<Passenger*>> *Elevators::priorityOperation(map<int, vector<Passenger*>>* Levels) {
	map<int, vector<Passenger*>> *tempDest;
	cout << "Priority" << endl;
	//drop off all passengers
	for (int i = 0; i < Boarded.size(); i++) {
		if (!Boarded[i].empty()) {
			for (int j = 0; j < Boarded[i].size(); j++) {
				//drop off passenger at the elevator current floor
				Boarded[i].at(j)->CurrentFloor = currentFloor;

				//reset passenger direction
				Boarded[i].at(j)->DirectionPassenger = ElevatorDirection::checkDirection(currentFloor, Boarded[i].at(j)->DestinationFloor);
				
				//push passenger back to the levels at current level
				(*Levels)[currentFloor].push_back(Boarded[i].at(j));
			}
			Boarded[i].clear();
		}
	}
	currentCapacity = 0;

	//find priority caller
	int totalBoard = 0;
	for (int i = 0; i < Levels[currentFloor].size(); i++) {
		if ((*Levels)[currentFloor][i]->callType == 'P') {
			totalBoard++;
			//pick up priority call
			Boarded[(*Levels)[currentFloor][i]->DestinationFloor].push_back((*Levels)[currentFloor][i]);

			//add weight
			currentCapacity = currentCapacity + (*Levels)[currentFloor][i]->Weight;
			
			//change direction to match passengers
			currentDirection = (*Levels)[currentFloor][i]->DirectionPassenger;
			
			//change destination to the passengers destination
			currentDestination = (*Levels)[currentFloor][i]->DestinationFloor;
			break;
		}
	}
	cout << "Total on board: " << totalBoard << endl;
	
	return Dest;
}

map<int, vector<Passenger*>> *Elevators::evacOperation(map<int, vector<Passenger*>>* Levels){
	//map<int, vector<Passenger*>> *tempDest;
	cout << "EVAC!!" << endl;
	return Dest;
}
