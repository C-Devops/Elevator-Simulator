#include <iostream>
#include <map>
#include <vector>

using namespace std;


#ifndef ELEVATORTESTSIMULATION_SYSTEMCONTROLLER_H
#define ELEVATORTESTSIMULATION_SYSTEMCONTROLLER_H

#include "Passenger.h"

class SystemController {

public:
    /*
     * Constructor and Destructor
     */
    SystemController(std::string path, int epoch);      // Populate Traffic in Const
    ~SystemController();                                // Dest

public:
    /*
     * Methods
     */

    void startElevator();                   // Creates Elevator object and Starts Lift etc
	void print_status();

public:
    /*
     * Attributes
     */

    map<int, vector<vector<std::string>>> PData;        // PData DataStructure
    map<int,vector<Passenger *>> Levels;                // Current Floow Data Structrue
    map<int , vector<Passenger *>> LevelDest;           // Dest Floor Data Structure

    std::string path;                                   // File Path
    int epoch;                                          // Epoch of Iteration
    int numberElevator;                                 // Total Number of Elevators
    int maxCapacity;                                    // max capacity of elevator
    int maxFloor;                                       // Max Floors

};


#endif //ELEVATORTESTSIMULATION_SYSTEMCONTROLLER_H
