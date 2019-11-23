#include <map>
#include <vector>
#include <iostream>

#include "Passenger.h"
#include "Display.h"
#include "StatisticsKeeper.h"


void Display::introducePassenger(map<int,vector<Passenger *>> Levels)
{
    cout << "\n";
    cout << "\t\t==============================================="<< endl;
    cout << "\t\t\t\t\t" << "Passenger Created  " << endl;
    cout << "\t\t==============================================="<< endl;
    cout << "\n";

    // LEVEL DATA STRUCTURE
    for(int j = 0; j< Levels.size(); j++)
    {
        for(auto x:Levels[j])
        {
            x->introduce();

            if(x->name == "SupportStaff")
            {
                StatisticsKeeper::supportStaffCounter = StatisticsKeeper::supportStaffCounter + 1;
            }
            if( x->name == "Visitor" )
            {
                StatisticsKeeper::visitorCounter = StatisticsKeeper::visitorCounter + 1;
            }
            if(x->name == "MedicalStaff")
            {
                StatisticsKeeper::medicalStaffCounter = StatisticsKeeper::medicalStaffCounter + 1;
            }
            if(x->name == "Patients")
            {
                StatisticsKeeper::patientCounter = StatisticsKeeper::patientCounter + 1;
            }
            if(x->name == "SecurityPersonnel")
            {
                StatisticsKeeper::securityStaffCounter = StatisticsKeeper::securityStaffCounter + 1;
            }

            if (x->DirectionPassenger == 'U')       // Up Passengers Tracker
            {
                StatisticsKeeper::totalPassengerGoingUp = StatisticsKeeper::totalPassengerGoingUp + 1;
            }
            if(x->DirectionPassenger == 'D')        // Up Passengers Tracker
            {
                StatisticsKeeper::totalPassengerGoingDown = StatisticsKeeper::totalPassengerGoingDown + 1;
            }
        }

    }

}

void Display::displayLevelsCurrent(map<int,vector<Passenger *>> &Levels)
{

    cout << "\n";
    cout << "\t\t==============================================="<< endl;
    cout << "\t\t\t\t\t" << "Floor Summary   " << endl;
    cout << "\t\t==============================================="<< endl;
    cout << "\n";

    // LEVEL DATA STRUCTURE
    for(int j = 0; j< Levels.size(); j++)
    {
        cout << "Floor : " << j << "  Passenger : " ;

        for (auto x: Levels[j])
        {
            cout << x->PassengerId << " " << x->DirectionPassenger << " " << " W: " << x->Weight << " "  ;
        }cout << "\n";

    }


}

void Display::displayTotalPassengerCount(int num)
{
    cout << "\n";
    cout << "\t\t==============================================="<< endl;
    cout << "\t\t\t\t\t" << "Total Passenger Generated  "<< num  << endl;
    cout << "\t\t\t\t\t" << "Total Visitors  "<< StatisticsKeeper::visitorCounter  << endl;
    cout << "\t\t\t\t\t" << "Total Patients  "<< StatisticsKeeper::patientCounter  << endl;
    cout << "\t\t\t\t\t" << "Total Security personal  "<< StatisticsKeeper::securityStaffCounter  << endl;
    cout << "\t\t\t\t\t" << "Total Support Staff  "<< StatisticsKeeper::supportStaffCounter  << endl;
    cout << "\t\t\t\t\t" << "Total Medical Staff  "<< StatisticsKeeper::medicalStaffCounter  << endl;
    cout << "\t\t\t\t\t" << "Total Passenger Going Up "<< StatisticsKeeper::totalPassengerGoingUp  << endl;
    cout << "\t\t\t\t\t" << "Total Passenger Going Down "<< StatisticsKeeper::totalPassengerGoingDown  << endl;
    cout << "\t\t==============================================="<< endl;
    cout << "\n";

}



void Display::displayDestinationFloors( map<int , vector<Passenger *>> &LevelDest)
{
    cout << "\n";
    cout << "\t\t==============================================="<< endl;
    cout << "\t\t\t\t\t" << "Dest levels   " << endl;
    cout << "\t\t==============================================="<< endl;
    cout << "\n";

    // LEVEL DATA STRUCTURE
    for(int j = 0; j< LevelDest.size(); j++)
    {
        cout << "Floor : " << j << "  Passenger : " ;

        for (auto x: LevelDest[j])
        {
            cout << x->PassengerId << " " << x->DirectionPassenger << " " << " W: " << x->Weight << " "  ;
        }cout << "\n";

    }cout << "\n";

}