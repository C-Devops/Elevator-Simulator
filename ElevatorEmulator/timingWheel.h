//
// Created by Soumil Shah on 11/26/19.
//

#ifndef ELEVATORSIMULATIONSSOFTWARE_TIMINGWHEEL_H
#define ELEVATORSIMULATIONSSOFTWARE_TIMINGWHEEL_H

#include <vector>
#include <map>
#include <queue>

#include "partitions.h"
#include "Elevators.h"
#include "Passenger.h"


class timingWheel {

public:
    partitions ** slots;
    int currentSlot;
    int delaySize;
    int maxDelay;
    int numFloors;
	map <int, map<char, char>> levelCall;
	map <int, vector<Passenger*>>* Dest;
	/*
	1://floor
		{U: R, //direction: call type
		D: R}
	*/


	bool evacCall = false;

    timingWheel(int floors, int delay, map<int, vector<vector<std::string>>> &PData, Elevators ** elevator);

    ~timingWheel();

	//insert at time slot
	void insertAt(int time, Elevators* e, char type);

	//insert a new partition in a differetn timing slot
    void insert(int travelFloors, Elevators* e, char type = 'R');
    
	//run basic functions of elevator from a partition: open and close door, drop off, pick up, and set next destination 
	map<int, vector<Passenger*>> *schedule(map<int, vector<Passenger *>> * Levels);
    
	//clears current timing slot
	void clearCurrentSlot();

	//clear a timing slot by index
    void clearSlot(int s);

	//find stops for elevator on each floor that a passenger request to go in the same direction
	void elevatorRequestStop(map<int, vector<Passenger*>>* Levels);

	//get elevator next stop
	

	//append two map<int, vector<Passenger*>> together
	void addToMap(map<int, vector<Passenger*>>& target, map<int, vector<Passenger*>>& input);
};


#endif //ELEVATORSIMULATIONSSOFTWARE_TIMINGWHEEL_H
