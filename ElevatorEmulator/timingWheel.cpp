#include "timingWheel.h"
#include "partitions.h"
#include "Elevators.h"
#include "ElevatorDirection.h"

#include <queue>

timingWheel::timingWheel(int floors, int delay) {
	//constructor
	numFloors = floors;
	delaySize = delay;
	maxDelay = floors * delay;
	slots = new partitions * [maxDelay + 1]{ nullptr };

	currentSlot = 0;
}

timingWheel::~timingWheel() {
	//deconstructor
	for (int i = 0; i < maxDelay+1; i++) {
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

void timingWheel::schedule() {
	//get first partition in current slot
	partitions* currentPartition = slots[currentSlot];

	//next time slot is pointing to a partition
	while (currentPartition != nullptr) {
		//Do work for current partition in that time slot.

		//For each partition:
			//Open elevator door.
			//Disembark passengers from elevator.
			//Fill elevator with waiting passengers at the floor going in the same direction or change direction if the elevator has no next destination.
			//Close elevator door.	
		currentPartition->elevatorTask();
		
		//Create new partition to next corresponding time slot depending on distance of next destination floor.

		//Get next partition pointer in time slot if there more.
		currentPartition = currentPartition->getNextPartitions();
	}
	//delete all partitions in current time slot
}

void timingWheel::clearCurrentSlot() {
	//queue to hold all partitions in slot
	queue <partitions*> partToDel;

	//get next partition in the start of the list
	partitions* hasNext = slots[currentSlot]->getNextPartitions();
	
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

	//delete partiiton where pointer is pointing
	delete slots[currentSlot];
}

void timingWheel::clearSlot(int s) {
	queue <partitions*> partToDel;

	//get next partition in the start of the list
	partitions* hasNext = slots[s]->getNextPartitions();

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

	//delete pointer in slot
	delete slots[s];
}