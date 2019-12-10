/*
 * this is SupportStaff.cpp
 */


#include "SupportStaff.h"
using namespace std;


#include "Passenger.h"

int SupportStaff::count = 0;


SupportStaff::SupportStaff()
{

    string uniqueId =  "SS";
    count++;
    string unique = uniqueId + std::to_string(count);
    PassengerId = unique;
    name = "SupportStaff";
}

SupportStaff::~SupportStaff(){count --;}


void SupportStaff::introduce()
{
    cout << "\t\tHi ! I am SupportStaff:\t"<<PassengerId << endl;
    cout << "\t\tCurrent Floor:\t"<<CurrentFloor<< endl;
    cout << "\t\tDestination Floor:\t"<<DestinationFloor<< endl;
    cout << "\t\tI want to go :\t"<<DirectionPassenger<< endl;
    cout << "\t\tI Call Type :\t"<< callType << endl;
    cout <<"\n";
}


void SupportStaff::emergency()
{
    cout << "Support Staff Emergency " << endl;
}