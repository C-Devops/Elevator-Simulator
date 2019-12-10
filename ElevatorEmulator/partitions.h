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
	char callRespondType = 'N'; //type of call the elevator is responding to

public:
    partitions(Elevators* e, partitions* n = nullptr, char callType = 'R');
    ~partitions();
    map<int, vector<Passenger*>> *elevatorTask(map<int, vector<Passenger *>> * Levels);
    void setNextPartition(partitions* n);
    partitions* getNextPartitions();
};

#endif //ELEVATORSIMULATIONSSOFTWARE_PARTITIONS_H
