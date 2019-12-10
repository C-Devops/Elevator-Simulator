//
// Created by Soumil Shah on 11/13/19.
//


#include <iostream>
#include <map>
#include <vector>


#ifndef ELEVATORTESTSIMULATION_GENERATEUNIQUEPASSENGER_H
#define ELEVATORTESTSIMULATION_GENERATEUNIQUEPASSENGER_H

#include "Passenger.h"
#include "Visitors.h"
#include "Patients.h"
#include "SupportStaff.h"
#include "MedicalStaff.h"
#include "SecurityPersonnel.h"
#include "StringHelper.h"
#include "RandomGenerator.h"



class GenerateUniquePassenger {

public:
    vector<int> passengerSpawnRate;

public:
    static Passenger * genpass(map<int, vector<vector<std::string>>> &PData, vector<int> &PassengerSpawnRange);

};


#endif //ELEVATORTESTSIMULATION_GENERATEUNIQUEPASSENGER_H
