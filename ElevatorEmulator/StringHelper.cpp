#include <iostream>
#include <string>
#include <iostream>
#include <ctime>
#include <chrono>
#include <sstream>
#include <string>
#include <vector>


#include "StringHelper.h"

int StringHelper::string_to_int(std::string num)
{
    int number;
    number = stoi(num);
    return number;
}

float StringHelper::string_to_float(std::string num)
{
    float number;
    number = stof(num);
    return number;
}



vector<string> StringHelper::string_split_f(stringstream &target, string filter) {
    vector<string> out;
    vector<string> temp;
    vector<string>::iterator v_it;
    string word;
    for (int filter_char = 0; filter_char < (filter.length()); filter_char++) {
        if (filter_char == 0) {
            while (getline(target, word, filter[filter_char])) {
                temp.push_back(word);
            }
        } else {
            for (v_it = out.begin(); v_it != out.end(); v_it++) {
                stringstream temp_target(*v_it);
                while (getline(temp_target, word, filter[filter_char])) {
                    temp.push_back(word);
                }
            }
        }
        //replace old data
        out.clear();
        for (v_it = temp.begin(); v_it != temp.end(); v_it++) {
            out.push_back(*v_it);
        }
        //clear temp vector
        temp.clear();
    }

    return out;
}

