#pragma once
#ifndef TRAFFIC_GENERATOR_H_
#define TRAFFIC_GENERATOR_H_

#include <string>
#include <stdio.h>
#include <vector>
#include "Passenger.h"
#include "Visitors.h"
#include "Patients.h"
#include "SupportStaff.h"
#include "SecurityPersonnel.h"
#include "MedicalStaff.h"
using namespace std;

class traffic_generator{
private:
    /*float vistor_rate;
    float patients_rate;
    float sup_staff_rate;
    float med_staff_rate;
    float security_staff_rate;*/
    
    //vistor range in a 100
    int vistor_range [2];
    int patients_range [2];
    int sup_staff_range [2];
    int med_staff_range [2];
    int security_staff_range [2];
    
    //improve probability for passenger spawn diversity
	vector<int> passenger_spawn_range;
    
    //vector holding value of type of elevator calls, call rand()%100 place
    //used in set_probability_call()
    vector<int> vistor_call_rate;
    vector<int> patients_call_rate;
    vector<int> sup_staff_call_rate;
    vector<int> med_staff_call_rate;
    vector<int> security_staff_call_rate;

public:
    //rate is array probability spawm rate, call_rate input "reg,emer,evac", weight input "lowest, highest"
    traffic_generator(vector<float> &rate, vector<string> call_rate, vector<string>weight);//string vis_call_rate, string pat_call_rate, string sup_call_rate, string med_call_rate, string security_call_rate, string sup_weight, string med_weight);
    ~traffic_generator();

    //create vector with value 1(vistor), 2(patient), 3(support staff), 4(medical staff), 5(security staff)
	vector<int> set_prob_spw_range(vector<float> rates);
    
    //create vector with value 0(normal), 1(emer), 3(evac)
    vector<int> set_probabilitys_call(vector<int> prop);
    
    //return random call 0(normal), 1(emergency), 2(evacuate) depending on type of passenager
    int passenger_elev_call(string type);
    
    //return passenager object
    Passenger * gen_pass();

};

#endif // !TRAFFIC_GENERATOR_H
