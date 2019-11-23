#include "partitions.h"
#include "Elevators.h"

partitions::partitions(Elevators* e, partitions* n) {
	//partition constructor 
	elevator = e;
	next = n;
}

partitions::~partitions() {
	//partition deconstructor
}

void partitions::elevatorTask() {
	//check if door is open
	if (!elevator->checkDoor()) {
		// Elevator open door
		elevator->toggleDoor();
	}
	else {

	}
	// Elevator drop off passengers
	// collect waiting passengers from floor
	// check nearest destination in directions of travel
	// Elevator close door
	elevator->toggleDoor();
}

void partitions::setNextPartition(partitions * n) {
	next = n;
}

partitions* partitions::getNextPartitions() {
	return next;
}
