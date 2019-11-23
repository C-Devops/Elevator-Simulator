#pragma once
#ifndef PARTITIONS_H_
#define PARTITIONS_H_

#include "Elevators.h"
#include "ElevatorDirection.h"
//#include "partition.h"
#include <iostream>
#include <vector>

using namespace std;

class partitions {
public:
	Elevators* elevator;
	partitions* next = nullptr;

public:
	partitions(Elevators* e, partitions* n = nullptr);
	~partitions();
	void elevatorTask();
	void setNextPartition(partitions* n);
	partitions* getNextPartitions();
};
#endif // !PARTITION_H_