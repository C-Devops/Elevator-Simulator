//
// Created by Soumil Shah on 11/28/19.
//

#include "SystemControllerInterface.h"
#include "StringHelper.h"
#include "SystemControllerBridge.h"


SystemControllerInterface::SystemControllerInterface(SystemControllerBridge *_systemControllerBridge):_systemControllerBridge{_systemControllerBridge}
{}

SystemControllerInterface::~SystemControllerInterface(){}

void SystemControllerInterface::startElevatorinterface(int simulationtime)
{
    cout << "+++++++++++++++++ System Controller Interface: SIM Method +++++++++++++++++" << endl;
    _systemControllerBridge->startElevator(simulationtime);
}