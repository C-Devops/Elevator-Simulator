#include <iostream>
#include <string>
#include <map>
#include <vector>




#ifndef ELEVATORTESTSIMULATION_STATISTICSKEEPER_H
#define ELEVATORTESTSIMULATION_STATISTICSKEEPER_H


class StatisticsKeeper {
public:
    StatisticsKeeper();
    ~StatisticsKeeper();

public:
    static int totalPassengerCreatedInBatchSize;
	static int totalPassengersgenerated;

    static int visitorCounter;
    static int medicalStaffCounter;
    static int securityStaffCounter;
    static  int patientCounter;
    static int supportStaffCounter;

    static int totalPassengerGoingUp ;
    static int totalPassengerGoingDown;

};


#endif //ELEVATORTESTSIMULATION_STATISTICSKEEPER_H
