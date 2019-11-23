#include <iostream>
#include <map>
#include <vector>

using  namespace std;


#include "SystemController.h"
#include "TrafficGenerator.h"
#include "StringHelper.h"
#include "Elevators.h"
#include "Display.h"

void SystemController::startElevator()
{

    cout << "Total Elevators " << numberElevator << endl;
    cout << "max capacity " << maxCapacity << endl;
    cout << "maxFloor "<< maxFloor << endl;


    Display::displayDestinationFloors(LevelDest);

	Elevators** elevator;
	elevator = new Elevators * [numberElevator] ;

    for(int i=0; i<numberElevator; i++)
    {
        elevator[i] = new Elevators();
        elevator[i]->maxCapacity = maxCapacity;
		elevator[i]->higestFloor = Levels.size();
		elevator[i]->DestFlag = new bool[Levels.size()];
    }

    for(int i=0; i<numberElevator; i++)
    {
        elevator[i]->elevatorIntroduce();
    }



//
//    int uindex = 0;
//    int temWeiht = 0;
//
//    // Loop for Elevators
//    // numberElevator
//    for(int i=0;i<1; i++)
//    {
//        temWeiht = 0;
//        cout << "Id: \t" << elevator[i]->ElevatorId << endl;
//
//        // Each Floor
//        for(int j=0;j<Levels.size(); j++){
//
//            elevator[i]->currentFloor = j;
//            cout << "Floor :\t" << j << endl;
//
//            uindex = 0;
//            for (auto u:Levels.at(j))
//            {
//                if(Levels[j].size() > 0)
//                {
//                    temWeiht = elevator[i]->elevatorWeightCounter + (u)->Weight ;
//
//                    if((u)->DirectionPassenger == 'U' and temWeiht < maxCapacity and (u)->CurrentFloor == elevator[i]->currentFloor)
//                    {
//                        // Increase the Weight
//                        elevator[i]->elevatorWeightCounter = elevator[i]->elevatorWeightCounter + (u)->Weight;
//
//                        // Passenger Boarded    Deque Data Structure
//                        elevator[i]->Up.push_back((u));
//
//                        cout << "\t\t\t\t\t\t" << "Door Opens :\t"
//                             << "Elevator Weight: \t" << elevator[i]->elevatorWeightCounter << "\t" << (u)->PassengerId
//                             << " Dest: \t" <<  (u)->DestinationFloor << endl;
//
//
//                        // Passenger should be removed from Levels once served
//                        try{
//
//                            if(Levels.at(j).size() < uindex)
//                            {
//                                throw 999;
//                            }
//                            else
//                            {
//                                Levels.at(j).erase(Levels[j].begin() + uindex);
//                            }
//                        }
//                        catch (int e)
//                        {
//                            cout << "error :  "<< e << endl;
//                        }
//                    }else{
//                        uindex = uindex + 1;
//                    }
//                }
//            }
//
//
//        }cout <<"\n";
//    }
    cout << "=========================================================" << endl;


}


SystemController::SystemController(std::string p, int epoch):path{p},epoch{epoch}
{
    /*
     * Constructor
     * Populates the Level for Specified Epoch
     */

    // create  a  object of Traffic Generator
    TrafficGenerator *generate;
    generate = new TrafficGenerator(path);

    for(int i=0; i<epoch; i++)
    {
        generate->generatePassengers();
    }

    Levels = generate->Levels;
    PData= generate->PData;
    generate->displayPassenger();

    // Reverse Map
    for (int i=0; i<Levels.size(); i++)
    {
        for(auto x: Levels[i])
        {
            LevelDest[x->DestinationFloor].push_back(x);
        }
    }


    numberElevator = StringHelper::string_to_int(PData[0][0][1]);
    maxCapacity = StringHelper::string_to_int(PData[0][0][2]);
    maxFloor = StringHelper::string_to_int(PData[0][0][0]);

}

SystemController::~SystemController()
{

}


void SystemController::print_status() {
	//print simutation current time
	//print number of new generated passegners
	//print number of passengers each their destinations
	//print number of avg time for passengers to reach their destnaitions
	//print number of emergency calls

	//Output for each elevator:
		//Elevator ID:
		//Elevator current floor:
		//Elevator current direction:
		//Elevator next destination:
		//Elevator current number of passengers:
		//Elevator current weight:

	//Output for each floor:
		//number of passengers waiting on floor
		//the type of call
		//Direction of call
		
}