/*
 * This is Patient.cpp File
 *
 */

#include <iostream>

using namespace std;

#include "Patients.h"
#include "Passenger.h"

int Patients::count = 0;


Patients::Patients()
{
    // cout << " Patients class  Constructor ---->" << endl;
    string uniqueId =  "P";
    count ++;
    string unique = uniqueId + std::to_string(count);
    PassengerId = unique;
    name = "Patients";
}

Patients::~Patients()
{
    // cout  << "Patient class Destructor --------> " <<  endl;
    count --;
}


void Patients::introduce()
{
    cout << "\t\tHi ! I am Patients:\t"<<PassengerId << endl;
    cout << "\t\tCurrent Floor:\t"<<CurrentFloor<< endl;
    cout << "\t\tDestination Floor:\t"<<DestinationFloor<< endl;
    cout << "\t\tWeight :\t"<<Weight<< endl;
    cout << "\t\tI want to go :\t"<<DirectionPassenger<< endl;
    cout << "\t\tI Call Type :\t"<< callType << endl;
    cout <<"\n";
}
