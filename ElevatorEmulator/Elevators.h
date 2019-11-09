#include <iostream>
//#include <ctime>
using namespace std;

#ifndef ELEVATORS_H_
#define ELEVATORS_H_


class Elevators {
private:
	int elevator_id;
	int maxCapacity;
	int current_floor;
	bool current_direction; //false == up, true == down
	bool door;//false == close, true == open
	vector<string> onboard;//hold pass ids

public:
    /*
     *  Constructor and Dest
     */
    Elevators(int e, int max = 10);
    ~Elevators();
    bool check_door();//check if door is open
	void toggle_door();//open or close door
	int get_current_floor();//return current floor
	void next_floor();//increment or deincrement floor number
	bool get_current_direction();//return direction
	void toggle_direction();//change direction
};


#endif //!ELEVATORS_H
