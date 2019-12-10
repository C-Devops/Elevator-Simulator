#include <iostream>

using namespace std;


#ifndef ELEVATORSIMULATORDESIGNPATTERN_SYSTEMCONTROLLERIMPA_H
#define ELEVATORSIMULATORDESIGNPATTERN_SYSTEMCONTROLLERIMPA_H

#include "SystemControllerBridge.h"
#include "Elevators.h"
#include "timingWheel.h"
#include "partitions.h"


class SystemControllerImpA: public SystemControllerBridge {

public:
    /*
     * Constructor and Destructor
     */
    SystemControllerImpA(std::string path, int delay);
    ~SystemControllerImpA();

public:

    map<int, vector<vector<std::string>>> PData;        // PData DataStructure
    map<int,vector<Passenger *>> *Levels;
    map<int , vector<Passenger *>> *LevelDest;           // Dest Floor Data Structure
    map<int, bool> floorStatus;                         // Its Flag whether person is there on that FLoor or not

    std::string path;                                   // File Path
    int epoch;                                          // Epoch of Iteration
    int numberElevator;                                 // Total Number of Elevators
    int maxCapacity;                                    // max capacity of elevator
    int maxFloor;                                       // Max Floors
    timingWheel *timewheel;                             // timing wheel partition
    int delay;
    TrafficGenerator *generate;
	Elevators** elevators;

public:
    /*
     * Metthods and Attributes
     */
    virtual  void startElevator(int simulationtime)override ;
	void print_results(int i);
	void MoveElevators();

};


#endif //ELEVATORSIMULATORDESIGNPATTERN_SYSTEMCONTROLLERIMPA_H
