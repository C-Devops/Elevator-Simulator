#include <iostream>

using namespace std;


#include "ElevatorDirection.h"
#include "StringHelper.h"

char ElevatorDirection::checkDirection(string currentFloors, string DestinationFloors)
{

    // True mean Go Up
    int CurrentFloor = StringHelper::string_to_int(currentFloors);
    int DestinationFloor = StringHelper::string_to_int(DestinationFloors);

    if (CurrentFloor < DestinationFloor)
    {
        return 'U';
	}
	else if (CurrentFloor > DestinationFloor)
    {
        return 'D';
    }
	else if(CurrentFloor == DestinationFloor)
    {
        return 'N';
	}
	else {
		return 'N';
	}

}

char ElevatorDirection::checkDirection(int currentFloor, int DestinationFloor)
{

	// True mean Go Up
	//int CurrentFloor = StringHelper::string_to_int(currentFloors);
	//int DestinationFloor = StringHelper::string_to_int(DestinationFloors);

	if (currentFloor < DestinationFloor)
	{
		return 'U';
	}
	else if (currentFloor > DestinationFloor)
	{
		return 'D';
	}
	else if (currentFloor == DestinationFloor)
	{
		return 'N';
	}
	else {
		return 'N';
	}

}
