/*
 * This is Visitors.cpp File
 * Visitors inherits from Passsengers and Passenger inherits from Counter
 *
 * Visitors >--Passengers ---> Counter
 *
 */

#include <iostream>

using namespace std;

#include "Visitors.h"
#include "Passenger.h"


int Visitors ::count = 0;

Visitors::Visitors()
{
    //cout << "Visitors Constructor  ------->" << endl;

    count ++;
    string uniqueId =  "V";
    string unique = uniqueId + std::to_string(count);
    PassengerId = unique;
    name = "Visitors";
}


Visitors::~Visitors()
{
    // cout << "Visitors Destructor  ------" << endl;
    count --;
}


void Visitors::introduce()
{

    cout << "\t\tHi ! I am Visitor:\t"<<PassengerId << endl;
    cout << "\t\tCurrent Floor:\t"<<CurrentFloor<< endl;
    cout << "\t\tDestination Floor:\t"<<DestinationFloor<< endl;
    cout << "\t\tWeight :\t"<<Weight<< endl;
    cout << "\t\tI want to go :\t"<<DirectionPassenger<< endl;
    cout << "\t\tI Call Type :\t"<< callType << endl;
    cout <<"\n";

}
