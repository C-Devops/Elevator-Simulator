#pragma once
#ifndef FORMAT_FUCNTIONS_H_
#define FORMAT_FUNCTIONS_H_

#include <iostream>
#include <vector>
using namespace std;

class Format_functions{
public:
    Format_functions();
    void string_split(stringstream& target, vector<string>& out, string filter);
    void string_to_int(vector<string>& input, vector<int>& output);
};

#endif //!FORMAT_FUNCTIONS_H