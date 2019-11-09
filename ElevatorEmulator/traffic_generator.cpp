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
        int last_temp =0;
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
        }
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
                vistor_call_rate = calls;
                break;
            case 2:
                patients_call_rate = calls;
                break;
            case 3:
                sup_staff_call_rate = calls;
                break;
            case 4:
                med_staff_call_rate = calls;
                break;
            case 5:
                security_staff_call_rate = calls;
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

int traffic_generator::passenger_elev_call(string id){
    Passenger * p;
    switch(id[0]){
        case "V":
            break;
        case "P":
            break;
        case "s";
            break;
        case "M":
            break;
        case "S":
            break;
        default:
            exit(EXIT_FAILURE);
    }

}

Passenger traffic_generator::gen_pass(){
    int pick = rand()%100;
    Passenger * p;
    if(vistor_range[0]<= pick and vistor_range[1]> pick){
        p = new Visitors();
    }else if(patients_range[0] <= pick and patients_range[1] > pick){
        //other
    }
}
