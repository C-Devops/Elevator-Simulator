#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#ifndef ELEVATOREMULATOR_STRINGHELPER_H
#define ELEVATOREMULATOR_STRINGHELPER_H

using namespace std;

class StringHelper {

public:
    static int string_to_int(std::string num);
    static float string_to_float(std::string num);

    //split string based on filter
    static vector<string> string_split_f(stringstream& s, string filter = " ");
};


#endif //ELEVATOREMULATOR_STRINGHELPER_H
