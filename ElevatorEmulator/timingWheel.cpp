#include "timingWheel.h"
#include "partitions.h"
#include "Elevators.h"
#include "ElevatorDirection.h"
#include "Passenger.h"
#include "StringHelper.h"
#include <queue>
#include <vector>
#include <map>
#include <cstdlib>
#include <algorithm>
using namespace std;


timingWheel::timingWheel(int floors, int delay, map<int, vector<vector<std::string>>> &PData, Elevators ** elevator) {

    //constructor
    // why +1 because
    // we have higest floor as 8
    // 0 to 7
    // hence + 1

    currentSlot = 0;
    numFloors = floors + 1;
    delaySize = delay;
    maxDelay = numFloors * delay;
    slots = new partitions * [maxDelay + 1]{ nullptr };

    int numElevators = StringHelper::string_to_int(PData.at(0).at(0).at(1));
	cout << "Total number of Elevators: " << numElevators << endl;
	cout << "Total number of Floors: " << numFloors << endl;

    //Create a partition for each elevator and place them in the starting slot
	for (int i =0; i <numElevators ; i++)
    {
		timingWheel::insertAt(0, elevator[i], 'N');//new Elevators()); //not needed
        //slots[0]->elevator->higestFloor = numFloors-1;
		//slots[0]->elevator->maxCapacity = stoi(PData.at(0).at(0).at(2));
    }

	//To introduce each elevator created
   // slots[0]->elevator->elevatorIntroduce();
	partitions* hasNext = slots[0];// ->getNextPartitions();
	cout << "============= Elevators =============" << endl;
    while (hasNext != nullptr)
    {
        //Introduce elevator at that partition
        hasNext->elevator->elevatorIntroduce();

		//get next partition pointer in list
        hasNext = hasNext->getNextPartitions();
    }

	//setup for level call type map;
	map<char, char>none;
	none.insert(pair<char, char>('U', 'N'));
	none.insert(pair<char, char>('D', 'N'));

	vector<Passenger*>* tmp;
	Dest = new map<int, vector<Passenger*>>;
	for (int i = 0; i < numFloors; i++) {
		//levelCall.insert(pair<int, char[2]>(i,));
		tmp = new vector<Passenger*>;
		(*Dest).insert(pair<int, vector<Passenger*>>(i, *tmp));
		levelCall[i] = none;

	}
}

timingWheel::~timingWheel() {
    //deconstructor
    for (int i = 0; i < maxDelay+1; i++)
    {
        //delete all partitions in time slot
        clearSlot(i);
    }

    delete slots;
}

void timingWheel::insertAt(int time, Elevators* e, char type) {
	int nextSlot = time % maxDelay;
	partitions* tmp = slots[nextSlot];
	slots[nextSlot] = new partitions(e, tmp, type);
}

void timingWheel::insert(int travelFloors, Elevators* e, char type) {
	int nextSlot;
	if (travelFloors != 0) {
		nextSlot = (currentSlot + (travelFloors * delaySize)) % maxDelay;
	}
	else {
		nextSlot = (currentSlot + 1) % maxDelay;
	}
	partitions* tmp = slots[nextSlot];
    slots[nextSlot] = new partitions(e, tmp, type);
}

map<int, vector<Passenger *>> *timingWheel::schedule(map<int, vector<Passenger *>> * Levels) {
    //results map of passengers at each destination
	map<int, vector<Passenger*>> *temp;
	map<int, vector<Passenger*>> *temp2;
	
	//get first partition in current slot
    partitions* currentPartition = slots[currentSlot];

	if (currentPartition == nullptr) {
		cout << "no partitions" << endl;
	}
	else {
		//next time slot is pointing to a partition
		//check levels for call types
		elevatorRequestStop(Levels);
		while (currentPartition != nullptr) {
			//Do work for current partition in that time slot.

			//For each partition:
			//Open elevator door.
			//Disembark passengers from elevator.
			//Fill elevator with waiting passengers at the floor going in the same direction or change direction if the elevator has no next destination.
			//Close elevator door.
			temp2 = currentPartition->elevatorTask(Levels);
			addToMap(*Dest, *temp2);

			
			
			//Create new partition to next corresponding time slot depending on distance of next destination floor.
			if (!evacCall) {
				if (currentPartition->elevator->currentTask != 'P') {
					//not priority call
					if (currentPartition->elevator->currentDirection == 'U') {
						//when elevator is going up
						int f = currentPartition->elevator->currentFloor;
						int count = 0;
						bool direction = false;//false = down, true = up

						//for each floor between current floor and destination floor
						while (f <= currentPartition->elevator->currentDestination) {
							if (levelCall[f]['U'] != 'N') {
								currentPartition->elevator->currentTask = levelCall[f]['U'];
								//currentPartition->elevator->currentDirection = 'U';
								insert(abs(f - currentPartition->elevator->currentFloor), currentPartition->elevator);
								cout << "elevator " << currentPartition->elevator->ElevatorId << "next destination " << f << endl;

								//elevator going pick up floor
								levelCall[f]['U'] = 'N';
								break;
							}
							else if (f == currentPartition->elevator->currentDestination) {
								insert(abs(currentPartition->elevator->currentDestination - currentPartition->elevator->currentFloor), currentPartition->elevator);
								cout << "elevator " << currentPartition->elevator->ElevatorId << "next destination " << f << endl;
								break;
							}
							else {
								//check next floor
							}
							f = f + 1;
						}
					}
					else if (currentPartition->elevator->currentDirection == 'D') {
						//when elevator is going down
						int f = currentPartition->elevator->currentFloor;
						int count = 0;
						bool direction = false;//false = down, true = up

						//for each floor between current floor and destination floor
						while (f >= currentPartition->elevator->currentDestination) {
							if (levelCall[f]['D'] != 'N') {
								currentPartition->elevator->currentTask = levelCall[f]['D'];
								//currentPartition->elevator->currentDirection = 'U';
								insert(abs(f - currentPartition->elevator->currentFloor), currentPartition->elevator);
								cout << "elevator " << currentPartition->elevator->ElevatorId << "next destination " << f << endl;
								levelCall[f]['D'] = 'N';
								break;
							}
							else if (f == currentPartition->elevator->currentDestination) {
								insert(abs(currentPartition->elevator->currentDestination - currentPartition->elevator->currentFloor), currentPartition->elevator);
								cout << "elevator " << currentPartition->elevator->ElevatorId << "next destination " << f << endl;
								break;
							}
							else {
								//check next floor
							}
							f = f - 1;
						}
					}
					else {
						//when elevator is not moving
						int f = currentPartition->elevator->currentFloor;
						int count = 0;
						bool direction = true;//false = down, true = up

						//for each floor
						while (f < numFloors and f >= 0) {
							if (direction) {
								//check floor for calls by increamenting floor number
								if (levelCall[f]['U'] != 'N') {
									currentPartition->elevator->currentTask = levelCall[f]['U'];
									currentPartition->elevator->currentDirection = 'U';
									insert(abs(f - currentPartition->elevator->currentFloor), currentPartition->elevator);
									cout << "elevator " << currentPartition->elevator->ElevatorId << "next destination " << f << endl;
									levelCall[f]['U'] = 'N';
									break;
								}
								else if (levelCall[f]['D'] != 'N') {
									currentPartition->elevator->currentTask = levelCall[f]['D'];
									currentPartition->elevator->currentDirection = 'D';
									insert(abs(f - currentPartition->elevator->currentFloor), currentPartition->elevator);
									cout << "elevator " << currentPartition->elevator->ElevatorId << "next destination " << f << endl;
									levelCall[f]['D'] = 'N';
									break;
								}
								else {
									//on one to pick at this floor
								}

								//increament floor number
								f = f + 1;
								if (f == numFloors - 1) {
									//reached limit change direction
									direction == false;
								}
							}
							else {
								//check floor for calls by decreamenting floor number
								if (levelCall[f]['U'] != 'N') {
									currentPartition->elevator->currentTask = levelCall[f]['U'];
									currentPartition->elevator->currentDirection = 'U';
									insert(abs(f - currentPartition->elevator->currentFloor), currentPartition->elevator);
									cout << "elevator " << currentPartition->elevator->ElevatorId << "next destination " << f << endl;
									levelCall[f]['U'] = 'N';
									break;
								}
								else if (levelCall[f]['D'] != 'N') {
									currentPartition->elevator->currentTask = levelCall[f]['D'];
									currentPartition->elevator->currentDirection = 'D';
									insert(abs(f - currentPartition->elevator->currentFloor), currentPartition->elevator);
									cout << "elevator " << currentPartition->elevator->ElevatorId << "next destination " << f << endl;
									levelCall[f]['D'] = 'N';
									break;
								}
								else {
									//on one to pick at this floor
								}

								//decreament floor number
								f = f - 1;
								if (f == 0) {
									//reached limit change direction
									direction == true;
								}
							}

							//after two check the levels for calls
							if (count == numFloors * 2) {
								//no new calls
								insert(0, currentPartition->elevator, 'N');
								cout << "elevator " << currentPartition->elevator->ElevatorId << "next destination " << currentPartition->elevator->currentFloor << endl;
								break;
							}
							count = count + 1;
						}
					}
				}
				else if (currentPartition->elevator->currentTask == 'P') {
					//elevator picking up a emergency call
					insert(abs(currentPartition->elevator->currentFloor - currentPartition->elevator->currentDestination), currentPartition->elevator);
					cout << "elevator " << currentPartition->elevator->ElevatorId << "next destination " << currentPartition->elevator->currentDestination << endl;
				}
				else {
					//try again at next timeslot
					insert(0, currentPartition->elevator);
					cout << "elevator " << currentPartition->elevator->ElevatorId << "next destination " << currentPartition->elevator->currentDestination << endl;
				}
				cout << endl;
			}
			else {
				//evac operatation
				insert(abs(currentPartition->elevator->currentFloor - currentPartition->elevator->currentDestination), currentPartition->elevator);
			}

			//Get next partition pointer in time slot if there more.
			currentPartition = currentPartition->next;//getNextPartitions();
		}
	}
    //delete all partitions in current time slot after
	return Dest;
}

void timingWheel::clearCurrentSlot() {
    //queue to hold all partitions in slot
    queue <partitions*> partToDel;

    //get next partition in the start of the list
	partitions* hasNext = slots[currentSlot];// ->getNextPartitions();

    //if the hasNext pointer is not a null pointer
    while (hasNext != nullptr) {
        //push pointer in queue
        partToDel.push(hasNext);

        //get next partition pointer in list
		hasNext = hasNext->getNextPartitions();
    }

    while (!partToDel.empty()) {
        //delete the partitions that the next in queue is pointing to
        delete partToDel.front();

        //pop from queue
        partToDel.pop();
    }

    /*//delete partiiton where pointer is pointing
	if (slots[currentSlot] != nullptr) {
		delete slots[currentSlot];
		slots[currentSlot] = nullptr;
	}
	else {
		//continue
	}*/
	slots[currentSlot] = nullptr;
}

void timingWheel::clearSlot(int s) {
    queue <partitions*> partToDel;

    //get next partition in the start of the list
	partitions* hasNext = slots[s];// ->getNextPartitions();

    //if the hasNext pointer is not a null pointer
    while (hasNext != nullptr) {
        //push pointer in queue
        partToDel.push(hasNext);

        //get next partition pointer in list
        hasNext = hasNext->getNextPartitions();
    }

    while (!partToDel.empty()) {
        //delete the partitions that the next in queue is pointing to
        delete partToDel.front();

        //pop from queue
        partToDel.pop();
    }

    /*//delete pointer in slot
	if(slots[s] != nullptr){
		delete slots[s];
		slots[s] = nullptr;
	}*/
	slots[s] = nullptr;
    
}

//list call for each floor also take care of evac calls
void timingWheel::elevatorRequestStop(map<int, vector<Passenger *>> * Levels) {
	//check the levels for elevators calls
	for (int i = 0; i < numFloors; i++) {
		cout << "Check for call at floor " << i << endl;
		//check if level is empty
		if (!(*Levels)[i].empty()) {
			//loop thur the passengers waiting at this level
			for (int j = 0; j < (*Levels)[i].size(); j++) {
				//check for evac calls
				if ((*Levels)[i][j]->callType != 'E' or evacCall) {
					//check if passengers have a directions of travel
					if ((*Levels)[i][j]->DirectionPassenger == 'U' or (*Levels)[i][j]->DirectionPassenger == 'D') {
						//check off the level call
						if (levelCall[i][(*Levels)[i][j]->DirectionPassenger] == 'N') {//if the call
							levelCall[i][(*Levels)[i][j]->DirectionPassenger] = (*Levels)[i][j]->callType;
							cout << "Passenger " << (*Levels)[i][j]->PassengerId << " call elevator going " << (*Levels)[i][j]->DirectionPassenger << endl;
						}
						else if ((*Levels)[i][j]->callType == 'P') {
							levelCall[i][(*Levels)[i][j]->DirectionPassenger] = (*Levels)[i][j]->callType;
						}
						/*else if (levelCall[i][(*Levels)[i][j]->DirectionPassenger] == 'R') {
							levelCall[i][(*Levels)[i][j]->DirectionPassenger] = (*Levels)[i][j]->callType;
						}*/
						else
						{
							cout << "Passenger " << (*Levels)[i][j]->PassengerId << " dont need to call elevator, Elevator already been called to that level" << endl;
							//cout << "Passenger " << (*Levels)[i][j]->PassengerId << " didnt call elevator" << endl;
						}
					}
					else {
						cout << "Passenger " << (*Levels)[i][j]->PassengerId << " does have direction set" << endl;
					}
				}
				else {
					//evac call was made
					evacCall = true;
				}
			}
		}
		else {
			//no one called for elevator
			levelCall[i]['U'] = 'N';
			levelCall[i]['D'] = 'N';
		}
		
	}
	cout << endl;
	//stops least filled elevator that is on the current floor where the call was made
	//if normal call
		//normal pickup if they fit
	//if emergency call
		//drop off all current passengers and pick up caller
		//the elevator should become dedicated to the emergency caller
	//if evacuate??
}

void timingWheel::addToMap(map<int, vector<Passenger*>>& target, map<int, vector<Passenger*>>& input) {
	//append each vector from input to target map
	//cout << "Appending two map together" << endl;
	//cout << "target:" << target.size() << ", input: " << input.size() << endl;
	vector<Passenger*>::iterator it;
	map<int, vector<Passenger*>>::iterator mit;
	for (int i = 0; i < (input).size(); i++) {
		//each key
		//target[i].insert(input[i].begin(), input[i].end(), input[i].begin());
		for (int j = 0; j < (input).at(i).size(); j++) {
			//each value in vector
			(target)[i].push_back((input).at(i).at(j));
		}
	}
	//return target map
}
