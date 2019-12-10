/*
 * This is Passenger Class Files
 * This is Passenger.h
 * Name: Soumil Nitin Shah
 * Student id: soushah@my.bridgeport.edu
 */

#include <iostream>
#include <string>
using  namespace std;



#ifndef ELEVATOREMULATOR_PASSENGER_H
#define ELEVATOREMULATOR_PASSENGER_H


class Passenger{

public:
    /*
     * Attributed for Passenger Class
     */

    std::string PassengerId;
    int Weight;
    int CurrentFloor;
    int DestinationFloor;
    char DirectionPassenger;
    std::string name;
    char callType;

public:
    /*
     * Passengers Class Constructor and Destructor
     */

    Passenger();                // No args Constructor
    virtual ~Passenger();       // Destructor

public:
    /*
     * Methods
     */


    void RequestFloor();
    void FindWaitTime();
    virtual void introduce();
};


#endif //ELEVATOREMULATOR_PASSENGER_H
