#include <map>
#include <vector>

using namespace std;


#ifndef ELEVATORTESTSIMULATION_TRAFFICGENERATOR_H
#define ELEVATORTESTSIMULATION_TRAFFICGENERATOR_H

#include "Passenger.h"


class TrafficGenerator {

public:
    /*
     * Attributes
     */
    int numFloor;                                   // How Many Floors
    int numElevators;                               // total Elevator
    int maxCapacity;                                // max capacity
    int batchSize;                                  // Batch Size

    vector<int>PassengerSpawnRange;                 // Vector of 100 Numbers
    map<int, vector<vector<std::string>>> PData;    // primary Data Structure
    map<int,vector<Passenger *>> Levels;            // Current Floow Data Structure
    map<int , vector<Passenger *>> LevelDest;       // Dest Floor Data Structure
    vector<Passenger *> Tem;                        // Tem vector so that we can populate Levels in Constructur

public:
    /*
     * Methods
     */

    void generatePassengers();
    vector<int> setSpawnRange(vector<float> &Rates);
    void displayPassenger();


public:
    /*
     * Constructor and Destructor
     */
    TrafficGenerator(std::string path);                 // Constructor
    ~TrafficGenerator();                                // Dest


};


#endif //ELEVATORTESTSIMULATION_TRAFFICGENERATOR_H
