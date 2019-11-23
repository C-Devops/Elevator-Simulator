#pragma once
#ifndef TIMINGWHEEL_H_
#define TIMINGWHEEL_H_

#include "partitions.h"

class timingWheel {
public:
	partitions ** slots;
	int currentSlot;
	int delaySize;
	int maxDelay;
	int numFloors;

	timingWheel(int floors = 1, int delay = 1);
	~timingWheel();
	void insert(int travelFloors, Elevators* p);
	void schedule();
	void clearCurrentSlot();
	void clearSlot(int s);
};

#endif // !TIMINGWHEEL_H_
