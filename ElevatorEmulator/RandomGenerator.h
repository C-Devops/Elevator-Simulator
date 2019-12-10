//
// Created by Soumil Shah on 11/7/19.
//
#include <vector>
#include <map>

using namespace std;

#ifndef ELEVATOREMULATOR_RANDOMGENERATOR_H
#define ELEVATOREMULATOR_RANDOMGENERATOR_H


class RandomGenerator {

public:
    static int generateRandomNumber(int low,int high);
    static char generatCall(vector <std::string> &rates);

public:
    RandomGenerator();
    ~RandomGenerator();
};


#endif //ELEVATOREMULATOR_RANDOMGENERATOR_H
