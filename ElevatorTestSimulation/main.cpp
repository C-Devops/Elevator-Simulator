#include <iostream>
#include <map>
#include <vector>

#include "Passenger.h"
#include "Visitors.h"
#include "Patients.h"
#include "SupportStaff.h"
#include "MedicalStaff.h"
#include "SecurityPersonnel.h"
#include "FileRead.h"
#include "TrafficGenerator.h"

int main()
    {


    std::string path = "/Users/soumilshah/CLionProjects/ElevatorTestSimulation/input.txt";
    TrafficGenerator *generate;
    generate = new TrafficGenerator(path);
    generate->generatePassengers();

    return 0;
    }