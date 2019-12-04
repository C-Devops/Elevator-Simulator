//
// Created by Soumil Shah on 11/26/19.
//

#ifndef ELEVATORSIMULATIONSSOFTWARE_PARTITIONS_H
#define ELEVATORSIMULATIONSSOFTWARE_PARTITIONS_H


#include "Elevators.h"
#include "ElevatorDirection.h"
#include "Passenger.h"
//#include "partition.h"
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class partitions {
public:
    Elevators* elevator = nullptr;
    partitions* next = nullptr;

public:
    partitions(Elevators* e, partitions* n = nullptr);
    ~partitions();
    void elevatorTask(map<int, vector<Passenger *>> * Levels);
    void setNextPartition(partitions* n);
    partitions* getNextPartitions();
};

#endif //ELEVATORSIMULATIONSSOFTWARE_PARTITIONS_H
