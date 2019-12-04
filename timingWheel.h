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

    timingWheel(int floors, int delay, map<int, vector<vector<std::string>>> &PData, Elevators ** elevator);

    ~timingWheel();

	//insert a new partition in a differetn timing slot
    void insert(int travelFloors, Elevators* p);
    
	//run basic functions of elevator from a partition: open and close door, drop off, pick up, and set next destination 
	void schedule(map<int, vector<Passenger *>> * Levels);
    
	//clears current timing slot
	void clearCurrentSlot();

	//clear a timing slot by index
    void clearSlot(int s);

	//stop elevator on a floor that a passenger request to go in the same direction
	void elevatorRequestStop(map<int, vector<Passenger*>>* Levels);
};


#endif //ELEVATORSIMULATIONSSOFTWARE_TIMINGWHEEL_H
