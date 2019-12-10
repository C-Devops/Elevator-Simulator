#include <iostream>
#include "Visitors.h"
#include "TrafficGenerator.h"
#include <map>
#include <vector>

#include "SystemControllerBridge.h"
#include "SystemControllerImpA.h"
#include "SystemControllerInterface.h"

int main() {


	std::string path = "C:/EleavtorSim/input.txt";// "/Users/soumilshah/CLionProjects/ElevatorTestSimulation/input.txt";
    int delay = 5;
    int simulationtime = 10;

    SystemControllerImpA a(path, delay);
    SystemControllerInterface obj(&a);

    obj.startElevatorinterface(simulationtime);
    cout << "Done " << endl;

    return 0;



}