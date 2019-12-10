/*
 * this os MedicalStafff.cpp File
 *
 */
#include <iostream>


#include "MedicalStaff.h"
#include "Passenger.h"

int MedicalStaff::count=0;

MedicalStaff::MedicalStaff()
{
    //cout << " MedicaStaff Constructor ---->" << endl;
    string uniqueId =  "MS";
    count++;
    string unique = uniqueId + std::to_string(count);
    PassengerId = unique;
    name = "MedicalStaff";
}


MedicalStaff::~MedicalStaff()
{
    // cout << "MedicalStaff Destructor  --> " << endl;
    count --;
}

void MedicalStaff::introduce()
{
    cout << "\t\tHi ! I am MedicalStaff:\t"<<PassengerId << endl;
    cout << "\t\tCurrent Floor:\t"<<CurrentFloor<< endl;
    cout << "\t\tDestination Floor:\t"<<DestinationFloor<< endl;
    cout << "\t\tWeight :\t"<<Weight<< endl;
    cout << "\t\tI want to go :\t"<<DirectionPassenger<< endl;
    cout << "\t\tI Call Type :\t"<< callType << endl;
    cout <<"\n";
}

void MedicalStaff::emergency()
{
    cout << "MedicalStaff : emergencey" << endl;
}