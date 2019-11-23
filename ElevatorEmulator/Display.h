#include <iostream>
#include <map>
#include <vector>
using namespace std;


#ifndef ELEVATORTESTSIMULATION_DISPLAY_H
#define ELEVATORTESTSIMULATION_DISPLAY_H


class Display {

public:
    /*
     * Methods
     */

    static int TotalPassengerCreated;                                                   // Counts How Many Passenger created for BatchSize
    static void introducePassenger(map<int,vector<Passenger *>> Levels);                // call introduce method on each Passengres
    static  void displayTotalPassengerCount(int num);                                   // Display Summary
    static void displayDestinationFloors( map<int , vector<Passenger *>> &LevelDest);    // Display Dest Levels main
    static void  displayLevelsCurrent(map<int,vector<Passenger *>> &Levels);

};


#endif //ELEVATORTESTSIMULATION_DISPLAY_H
