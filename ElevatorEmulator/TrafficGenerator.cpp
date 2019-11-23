//
// Created by Soumil Shah on 11/13/19.
//

#include <iterator>
#include <iostream>
#include <vector>
#include <map>
#include <chrono>
#include <algorithm>
#include <random>


#include "TrafficGenerator.h"
#include "FileRead.h"
#include "RandomGenerator.h"
#include "StringHelper.h"
#include "GenerateUniquePassenger.h"
#include "Display.h"
#include "StatisticsKeeper.h"
#include "Passenger.h"


TrafficGenerator::TrafficGenerator(std::string path):batchSize{0}
{
    /*
     * Constructor
     */


    FileRead *reader;
    reader = FileRead::getInstance();
    reader->readFile(path);
    PData = reader->PData;

    vector<float>Rates;     // [0.15 0.25 0.3 0.2 0.1 ]
    for (int i=1; i <PData.size(); i++)
    {
        Rates.push_back(StringHelper::string_to_float(PData[i][0].back()));
    }

    // Populate with Empty Passenger Pointer on Each Floor
    PassengerSpawnRange = setSpawnRange(Rates);
    for (int i=0; i <= StringHelper::string_to_int(PData[0][0][0]) ;i++ )
    {
        Levels[i] = Tem;
    }

}

TrafficGenerator::~TrafficGenerator(){}

void TrafficGenerator::displayPassenger()
{
    Display::introducePassenger(Levels);
    Display::displayLevelsCurrent(Levels);
    Display::displayTotalPassengerCount(StatisticsKeeper::totalPassengerCreatedInBatchSize);
}

void TrafficGenerator::generatePassengers()
{
    batchSize = RandomGenerator::generateRandomNumber(0,StringHelper::string_to_int(PData[0][0][0]));
    if(batchSize !=0)
    {
		Passenger ** passenger;
		passenger = new Passenger*[batchSize] ;
        for (int i=0; i<batchSize; i++)     // Batch Size is 10
        {
            try {
                passenger[i] = GenerateUniquePassenger::genpass(PData, PassengerSpawnRange);
                Levels[passenger[i]->CurrentFloor].push_back(passenger[i]);             // Then Populates Levels
                StatisticsKeeper::totalPassengerCreatedInBatchSize = StatisticsKeeper::totalPassengerCreatedInBatchSize + 1;

            }
            catch (int e)
            {
                cout << "Some thing strange occured" << endl;
            }
        }
    }

}

vector<int> TrafficGenerator::setSpawnRange(vector<float> &Rates)
{
    vector <int> Tem;

    vector<float>::iterator v_it;
    int  type = 1;


    for(v_it=Rates.begin();v_it !=Rates.end(); v_it ++){

        int range = int((*v_it)*100);
        for (int i=0; i<range; i++)
        {
            Tem.push_back(type);
        }

        type = type + 1;

    }

    //  Put the Reference  Code
    unsigned  seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(Tem.begin(), Tem.end(), default_random_engine(seed));

    return Tem;
}