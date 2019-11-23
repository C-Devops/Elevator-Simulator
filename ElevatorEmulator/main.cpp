#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <deque>


#include "Passenger.h"
#include "Visitors.h"
#include "Patients.h"
#include "SupportStaff.h"
#include "MedicalStaff.h"
#include "SecurityPersonnel.h"
#include "FileRead.h"
#include "TrafficGenerator.h"
#include "SystemController.h"


int main()
{


    //std::string path = "/Users/soumilshah/CLionProjects/ElevatorTestSimulation/input.txt";
	std::string path = "C://EleavtorSim/input.txt";
	int epoch = 1;

	/*int* e[3]{ nullptr };
	if (e[1] == nullptr) {
		cout << "works" << endl;
	}
	else {
		cout << "no works" << endl;
	}*/

	//FileRead* read = FileRead::getInstance();
	//read->readFile(path);
	//map<int, vector<vector<std::string>>> PData = read->PData;
	//cout << "PDATE SIZE " << PData.size() << endl;
	//cout << "Pdata[0][0][0] = " << PData[0][0][0] << endl;

    SystemController *systemcontroller;
    systemcontroller = new SystemController(path , epoch);
    systemcontroller->startElevator();

    return 0;
}