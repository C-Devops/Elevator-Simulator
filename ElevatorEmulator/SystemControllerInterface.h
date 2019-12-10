#include <iostream>
#include <iostream>
#include <map>
#include <vector>


using namespace std;
#include "Passenger.h"
#include "TrafficGenerator.h"
#include "SystemControllerBridge.h"
#include "SystemControllerBridge.h"

#ifndef ELEVATORSIMULATORDESIGNPATTERN_SYSTEMCONTROLLERINTERFACE_H
#define ELEVATORSIMULATORDESIGNPATTERN_SYSTEMCONTROLLERINTERFACE_H


class SystemControllerInterface{


protected:

    // Pointer to base Class implememnation class
    SystemControllerBridge *_systemControllerBridge;


public:
    /*
     * Constructor and Destructor
     */

    SystemControllerInterface(SystemControllerBridge * _systemControllerBridge);

    ~SystemControllerInterface();

public:
    /*
     * Methods
     */
    void startElevatorinterface(int simulationtime);

public:
    /*
     * Attributes
     */
    map<int, vector<vector<std::string>>> PData;        // PData DataStructure
    map<int,vector<Passenger *>> *Levels;
    map<int , vector<Passenger *>> LevelDest;           // Dest Floor Data Structure
    map<int, bool> floorStatus;                         // Its Flag whether person is there on that FLoor or not

    std::string path;                                   // File Path
    int numberElevator;                                 // Total Number of Elevators
    int maxCapacity;                                    // max capacity of elevator
    int maxFloor;                                       // Max Floors
    int delay;
    TrafficGenerator *generate;

};


#endif //ELEVATORSIMULATORDESIGNPATTERN_SYSTEMCONTROLLERINTERFACE_H
