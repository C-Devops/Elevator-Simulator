#include "traffic_generator.h"
#include "Format_functions.h"
#include "Passenger.h"
#include "Visitors.h"
#include "Patients.h"
#include "SupportStaff.h"
#include "SecurityPersonnel.h"
#include "MedicalStaff.h"
#include <iostream>
#include <vector>
#include <stdlib.h>     // exit, EXIT_FAILURE
#include <string>
#include <sstream>

traffic_generator::traffic_generator(vector<float> &rates, vector<string> call_rate, vector<string>weight){//} string vis_call_rate, string pat_call_rate, string sup_call_rate, string med_call_rate, string security_call_rate, string sup_weight, string med_weight){
    //check if percentage == to 100%
    int total;// = int(vis_rate + pat_rate + sup_rate + med_rate + security_rate);
    for(int i = 0; i<rates.size(); i++){
        total += int(rates[i]*100);
    }
    if(total == 100 and rates.size()==5){
	passenger_spawn_range = set_prob_spw_range(rates);
        /*int last_temp =0;
        for(int i = 1; i < rates.size()+1; i++){
            int temp = int(rates[i-1]*100)+last_temp;
            switch(i){
                case 1:
                    vistor_range[0] = last_temp;
                    vistor_range[1] = temp;
                    break;
                case 2:
                    patients_range[0] = last_temp;
                    patients_range[1] = temp;
                    break;
                case 3:
                    sup_staff_range[0] = last_temp;
                    sup_staff_range[1] = temp;
                    break;
                case 4:
                    med_staff_range[0] = last_temp;
                    med_staff_range[1] = temp;
                    break;
                case 5:
                    security_staff_range[0] = last_temp;
                    security_staff_range[1] = temp;
                    break;
                default:
                    cout<<"case not found"<<endl;
                    exit (EXIT_FAILURE);
            }
            last_temp = temp;
        }*/
	
    }else{
        cout<<"rates doesn't add up"<<endl;
        exit (EXIT_FAILURE);
    }
    Format_functions funct;
    //stringstream tmp_str;
    for(int i =1; i=call_rate.size()+1;i++){
        vector<string> split;
        vector<int> calls;
        stringstream s(call_rate[i-1]);
        funct.string_split(s,split,",");
        funct.string_to_int(split, calls);
        switch(i){
            case 1:
                vistor_call_rate = set_probabilitys_call(calls);
                break;
            case 2:
                patients_call_rate = set_probabilitys_call(calls);
                break;
            case 3:
                sup_staff_call_rate = set_probabilitys_call(calls);
                break;
            case 4:
                med_staff_call_rate = set_probabilitys_call(calls);
                break;
            case 5:
                security_staff_call_rate = set_probabilitys_call(calls);
                break;
            default:
                cout<<"case not found"<<endl;
                exit (EXIT_FAILURE);
        }
    }
}

traffic_generator::~traffic_generator(){
    cout << "traffic generator closed" << endl;
}

vector<int> traffic_generator::set_prob_spw_range(vector<float> rates) {
	vector<int> temp;
	vector<float>::iterator v_it;
	int type = 1;
	//int start
	for (v_it = rates.begin(); v_it != rates.end(); v_it++) {
		//cout << type << endl;
		int rang = int((*v_it) * 100);
		//cout << "rang " << rang << "\ntype " << type << endl;
		for (int i = 0; i < rang ; i++) {
			temp.push_back(type);
		}
		type++;
	}
	//shuffle using system clock
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	shuffle(temp.begin(), temp.end(), default_random_engine(seed));
	return temp;
}

vector<int> traffic_generator::set_probabilitys_call(vector<int> prop){
    vector<int> temp (100);
    vector<int> range;
    vector<int>::iterator v_it;
    int type = 0; //0(reg), 1(emer), 2(evac)

    //fill vector with calls type
    for(v_it = prop.begin(); v_it != prop.end(); v_it++){
        for(int i = 0; i<*v_it; i++){
            temp.push_back(type);
        }
        type++;
        //tmp_int = *v_it;
    }

    //shuffle using system clock
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	shuffle(temp.begin(), temp.end(), default_random_engine(seed));
    return temp;
}

int traffic_generator::passenger_elev_call(string id){
    Passenger * p;
    Format_functions funct;
    vector<string> base_id;
    stringstream s(id);
    funct.string_split(s, base_id, "0123456789");
    int tmp = rand()%100;
    int out =0;
    if(base_id[0] == "V"){
        out = vistor_call_rate[tmp];
    }else if(base_id[0] == "P"){
        out = patients_call_rate[tmp];
    }else if(base_id[0] == "SS"){
        out = sup_staff_call_rate[tmp];
    }else if(base_id[0] == "MS"){
        out = med_staff_call_rate[tmp];
    }else if(base_id[0] == "SEC"){
        out = security_staff_call_rate[tmp];
    }else{
        cout << "type not found" << endl;
        exit(EXIT_FAILURE);
    }
    return out;
}

Passenger traffic_generator::gen_pass(){
    int pick = rand()%100;
    Passenger * p;
    switch (passenger_spawn_range[pick]) {
	case 1:
		p = new Visitors();
		break;
	case 2:
		p = new Patients();
		break;
	case 3:
		p = new SupportStaff();
		break;
	case 4:
		p = new MedicalStaff();
		break;
	case 5:
		p = new SecurityPersonnel();
		break;
	default:
		cout << "case not found: gen_pass" << endl;
		exit(EXIT_FAILURE);
    }
    /*if(vistor_range[0]<= pick and vistor_range[1]> pick){
        p = new Visitors();
    }else if(patients_range[0] <= pick and patients_range[1] > pick){
       p = new Patients();
    }else if(sup_staff_range[0] <= pick and sup_staff_range[1] > pick){
        p = new SupportStaff();
    }else if(med_staff_range[0] <= pick and med_staff_range[1] > pick){
        p = new MedicalStaff();
    }else if(security_staff_range[0] <= pick and security_staff_range[1] > pick){
        p = new SecurityPersonnel();
    }else{
        cout << "passenger generator failed" << endl;
        exit(EXIT_FAILURE);
    }*/
    return p;
}
