#include <iostream>
#include <map>
#include <vector>
#include "GenerateUniquePassenger.h"


#include "Passenger.h"
#include "Visitors.h"
#include "Patients.h"
#include "SupportStaff.h"
#include "MedicalStaff.h"
#include "SecurityPersonnel.h"
#include "StringHelper.h"
#include "RandomGenerator.h"
#include "ElevatorDirection.h"
#include "StatisticsKeeper.h"




Passenger * GenerateUniquePassenger::genpass(map<int, vector<vector<std::string>>> &PData, vector<int> &PassengerSpawnRange)
{

    // Max Floor
    int floor = StringHelper::string_to_int( PData[0][0][0]);

    // Give 1 - 5
    int PassengerIndex = RandomGenerator::generateRandomNumber(0, PassengerSpawnRange.size());

    Passenger *p;

    int d = RandomGenerator::generateRandomNumber(0,floor);
    int c = RandomGenerator::generateRandomNumber(0,floor);


    while(c == d)
    {
        if(c == d)
        {
            d = RandomGenerator::generateRandomNumber(0,floor);
            // int c = RandomGenerator::generateRandomNumber(0,floor);
            break;
        }
    }


    std::string name;
    map<int , Passenger*> GenerateUniquePass;
    // GenerateUniquePass.insert(pair<int , Passenger* >(1, new Visitors));


    if(PData.size() > 0)
    {
        // Iterate over PData for names
        for (int i=1; i<PData.size(); i++)
        {
            name = PData[i][0][0];

            if (name == "Visitor")     // 1
            {
                GenerateUniquePass.insert(pair<int , Passenger* >(i, new Visitors));
            }
            else if(name == "Patient")
            {
                GenerateUniquePass.insert(pair<int , Passenger* >(i, new Patients));
            }

            else if(name == "Support")
            {
                GenerateUniquePass.insert(pair<int , Passenger* >(i, new SupportStaff));
            }

            else if(name == "Medical")
            {
                GenerateUniquePass.insert(pair<int , Passenger* >(i, new MedicalStaff));
            }

            else if(name == "Security")
            {
                GenerateUniquePass.insert(pair<int , Passenger* >(i, new SecurityPersonnel));
            }
            else
            {
                /*
                * Prompt useer if he wants to create a new user
                */
                cout<< "name"<< name <<endl;
                cout << "Pleas enter object in input file " << endl;
            }
        }
    }

    // Data structure is created

    // Gives Passenger Pointer
    int tmpType = PassengerSpawnRange[PassengerIndex];
    if (tmpType >0)
    {

    }
    if(tmpType == 0)                // Quick Fix for Crash
    {
        tmpType = tmpType + 1;      // SomeTime it was generating 0
    }

    Passenger *tm = GenerateUniquePass[tmpType];
    tm->DestinationFloor = d;
    tm->CurrentFloor = c;

    string lowwt = PData[tmpType][2][1];
    string highwt = PData[tmpType][2][2];

    tm->Weight = RandomGenerator::generateRandomNumber(
            StringHelper::string_to_int(lowwt),
            StringHelper::string_to_int(highwt));

    string currentfloor = to_string(c);
    string destinationFloor = to_string(d);

    tm->DirectionPassenger = ElevatorDirection::checkDirection(currentfloor,destinationFloor);
    tm->callType = RandomGenerator::generatCall(PData[tmpType][1]);
	
    return tm;


}