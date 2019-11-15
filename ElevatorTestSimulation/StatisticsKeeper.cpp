#include <iostream>
#include <string>


#include "StatisticsKeeper.h"

int StatisticsKeeper::totalPassengerCreatedInBatchSize = 0;

int StatisticsKeeper::visitorCounter = 0;
int StatisticsKeeper::medicalStaffCounter = 0;
int StatisticsKeeper::securityStaffCounter=0;
int StatisticsKeeper::patientCounter = 0;
int StatisticsKeeper::supportStaffCounter = 0;



StatisticsKeeper::StatisticsKeeper()
{
    totalPassengerCreatedInBatchSize ++;
}

StatisticsKeeper::~StatisticsKeeper()
{
    totalPassengerCreatedInBatchSize -- ;
}