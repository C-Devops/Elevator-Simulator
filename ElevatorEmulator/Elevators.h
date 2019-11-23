#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <deque>


using namespace std;


#ifndef ELEVATORTESTSIMULATION_ELEVATORS_H
#define ELEVATORTESTSIMULATION_ELEVATORS_H

#include "Passenger.h"

class Elevators {

public:
    /*
     * Const and Dest
     */
    Elevators();
    ~Elevators();


public:

    /*
     * Methods
     */
    void elevatorIntroduce();

	//increament or decreament depending on the direction it is moving
	void increamentFloor();

	//return if door is close or open
	bool checkDoor();

	//open or close door
	void toggleDoor();


public:
    /*
     * Attributes
     */
    int maxCapacity;            // Max capacity
    char elevatorDirection;     // Direction of Elevator
    int currentFloor;           // Floor where Elevator is
    int lowestFloor;           // Lowest Floor it can go is
    int higestFloor;            // Higest Floor it can Go
	bool door = false;					//true door open, false door closed

    int static  count;          // Elevator ID
    string ElevatorId;          // Elevator ID
    int elevatorWeightCounter;

    deque <Passenger *> Up;
    deque <Passenger *> Down;
	deque <Passenger*> Boarded;
    bool * DestFlag;

};


#endif //ELEVATORTESTSIMULATION_ELEVATORS_H
