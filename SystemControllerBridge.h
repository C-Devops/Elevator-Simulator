#include <iostream>
using  namespace std;

#ifndef ELEVATORSIMULATORDESIGNPATTERN_SYSTEMCONTROLLERBRIDGE_H
#define ELEVATORSIMULATORDESIGNPATTERN_SYSTEMCONTROLLERBRIDGE_H

// This is Abstract class
// Implements Bridge Design pattern


class SystemControllerBridge {

public:
    /*
     * Constructor and Destructor
     */
    SystemControllerBridge();
    ~SystemControllerBridge();


public:
    /*
     * Attributes
     */

    int count =22;


public:
    /*
     * Methods That System Controller Imp class will have
     */

    virtual void startElevator(int simulationtime) = 0;     // Pure Virtual Function

};


#endif //ELEVATORSIMULATORDESIGNPATTERN_SYSTEMCONTROLLERBRIDGE_H
