#include "timingWheel.h"
#include "partitions.h"
#include "Elevators.h"
#include "ElevatorDirection.h"
#include "Passenger.h"
#include "StringHelper.h"
#include <queue>
#include <vector>
#include <map>


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
		timingWheel::insert(0, elevator[i]);//new Elevators()); //not needed
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

void timingWheel::insert(int travelFloors, Elevators* e) {
    int nextSlot = (currentSlot + (travelFloors * delaySize))%maxDelay;
    partitions* tmp = slots[nextSlot];
    slots[nextSlot] = new partitions(e, tmp);
}

void timingWheel::schedule(map<int, vector<Passenger *>> * Levels) {
    //get first partition in current slot
    partitions* currentPartition = slots[currentSlot];

	if (currentPartition == nullptr) {
		cout << "no partitions" << endl;
	}
	else {
		//next time slot is pointing to a partition
		while (currentPartition != nullptr) {
			//Do work for current partition in that time slot.

			//For each partition:
			//Open elevator door.
			//Disembark passengers from elevator.
			//Fill elevator with waiting passengers at the floor going in the same direction or change direction if the elevator has no next destination.
			//Close elevator door.
			currentPartition->elevatorTask(Levels);

			//Create new partition to next corresponding time slot depending on distance of next destination floor.
			//insert(currentPartition->elevator->destination, currentPartition->elevator);

			//Get next partition pointer in time slot if there more.
			currentPartition = currentPartition->next;//getNextPartitions();
			cout << endl;
		}
	}
    //delete all partitions in current time slot after
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

void timingWheel::elevatorRequestStop(map<int, vector<Passenger *>> * Levels) {
	//check the levels for elevators calls
	//stops least filled elevator that is on the current floor where the call was made
	//if normal call
		//normal pickup if they fit
	//if emergency call
		//drop off all current passengers and pick up caller
		//the elevator should become dedicated to the emergency caller
	//if evacuate??
}
