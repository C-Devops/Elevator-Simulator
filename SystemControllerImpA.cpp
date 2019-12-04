#include <iostream>
#include <map>
#include <vector>
#include <iterator>
#include "StatisticsKeeper.h"
using  namespace std;

#include "TrafficGenerator.h"
#include "StringHelper.h"
#include "Elevators.h"
#include "SystemControllerBridge.h"
#include "SystemControllerImpA.h"
#include "timingWheel.h"
#include "partitions.h"

SystemControllerImpA::SystemControllerImpA(std::string p, int delay):path{p}, delay{delay}
{
    // TrafficGenerator *generate;
	cout << "+++++++++++ System Controller ImpA: setup +++++++++++++++" << endl;
    generate = TrafficGenerator::getinstance(path);
    PData = generate->PData;
	maxFloor = stoi(PData.at(0).at(0).at(0));
	numberElevator = stoi(PData.at(0).at(0).at(1));
	cout << "maxFloor " << maxFloor << endl;
	//create elevators
	elevators = new Elevators * [stoi(PData.at(0).at(0).at(1))];
	for (int i = 0; i < stoi(PData.at(0).at(0).at(1)); i++) {
		elevators[i] = new Elevators(maxFloor, stoi(PData.at(0).at(0).at(2)));
		//elevators[i]->higestFloor = maxFloor;
		//elevators[i]->maxCapacity = stoi(PData.at(0).at(0).at(2));
	}

    timewheel =  new timingWheel(maxFloor, delay, PData, elevators);

}


SystemControllerImpA::~SystemControllerImpA()
{

}

void SystemControllerImpA::startElevator(int simulationtime)
{
	cout << "Starting Simulation" << endl;
	//simulation run for user specified time
    for(int i=0; i<=simulationtime; i++)
    {
		//set current time slot of timing wheel
		timewheel->currentSlot = i % (timewheel->maxDelay);
		cout << "Time slot index: " << timewheel->currentSlot << endl;

		//populate floor with new passengers, Note: level returned is pass by reference
		Levels = generate->generatePassengers();
		cout << "Added more Passengers to Levels" << endl;

		// drop off and board passengers to elevators and set next destination
		timewheel->schedule(Levels);
		cout << "Ran each elevator task Successful" << endl;

		//print output file for each time unit of building data
		print_results(i);
		cout << "Printed output file" << endl;

		//clear current slot
		timewheel->clearCurrentSlot();
		cout << "Cleared current time slot\n" << endl;
		
		//increament, decreament or do noting to current elevator floor
		MoveElevators();
		//cout << endl;
    }
	
	// LEVEL DATA STRUCTURE
	for (int j = 0; j < Levels->size(); j++)
	{
		cout << "Floor : " << j << "  Passenger : " << endl;
		for (auto x : Levels->at(j))
		{
			cout << " ID : " << x->PassengerId << endl;
		}
	}

}

void SystemControllerImpA::print_results(int i) {
	//print output file of current building data
	//data from statistic keeper data
	//file output csv format???

	cout << "\n";
	cout << "\t\t===============================================" << endl;
	cout << "\t\t\t\t\t" << "Total number of Passengers " << StatisticsKeeper::totalPassengersgenerated << endl;
	cout << "\t\t\t\t\t" << "Total Visitors  " << StatisticsKeeper::visitorCounter << endl;
	cout << "\t\t\t\t\t" << "Total Patients  " << StatisticsKeeper::patientCounter << endl;
	cout << "\t\t\t\t\t" << "Total Security personal  " << StatisticsKeeper::securityStaffCounter << endl;
	cout << "\t\t\t\t\t" << "Total Support Staff  " << StatisticsKeeper::supportStaffCounter << endl;
	cout << "\t\t\t\t\t" << "Total Medical Staff  " << StatisticsKeeper::medicalStaffCounter << endl;
	cout << "\t\t\t\t\t" << "Total Passenger Going Up " << StatisticsKeeper::totalPassengerGoingUp << endl;
	cout << "\t\t\t\t\t" << "Total Passenger Going Down " << StatisticsKeeper::totalPassengerGoingDown << endl;
	cout << "\t\t===============================================" << endl;
	cout << "\n";
}


void SystemControllerImpA::MoveElevators() {
	for (int i = 0; i < numberElevator; i++) {
		elevators[i]->increamentFloor();
	}
}
