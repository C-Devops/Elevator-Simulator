#include <iostream>


#ifndef ELEVATOREMULATOR_ELEVATORDIRECTION_H
#define ELEVATOREMULATOR_ELEVATORDIRECTION_H

using namespace std;


class ElevatorDirection {
public:
    // U mean going up
    // D mean opp
    // N same
    static char checkDirection(string currentFloor, string DestinationFloor);

};


#endif //ELEVATOREMULATOR_ELEVATORDIRECTION_H
