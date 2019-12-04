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
    Elevators(int highestFloor = 8, int maxCapacity = 10);
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

	//check and mark passengers in elevator destinations in passengers floor flags
	void listPassDest();

	//pick up passengers at stop
	void elevatorOperator(map<int, vector<Passenger*>>* Levels);


public:
    /*
     * Attributes
     */
    int maxCapacity;            // Max capacity
    char elevatorDirection;     // Direction of Elevator
    int currentFloor;           // Floor where Elevator is
    int lowestFloor;           // Lowest Floor it can go is
    int higestFloor;            // Higest Floor it can Go
	int currentDestination;		//the next stop for the elevator
    bool door = false;			//true door open, false door closed
	char currentDirection;

    int static  count;          // Elevator ID
    string ElevatorId;          // Elevator ID
    int elevatorWeightCounter;

    //deque <Passenger*> Boarded;
    bool *passengerfloorflags;
	map<int, deque<Passenger*>> Boarded;


};


#endif //ELEVATORTESTSIMULATION_ELEVATORS_H
