#include <iostream>
#include <istream>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <iterator>
#include <random>
#include <ctime>
#include <algorithm>
#include <chrono>


using namespace std;

#include "RandomGenerator.h"
#include "StringHelper.h"



RandomGenerator::RandomGenerator()
{
    cout  << "Random Generator" << endl;
}

RandomGenerator::~RandomGenerator()
{
    cout << "Destructor called " << endl;
}

int RandomGenerator::generateRandomNumber(int low, int high){

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(low,high);
    return dist6(rng);
}

char RandomGenerator::generatCall(vector<std::string> &rates)
{
    vector<char> Spawnrange;

    for(int i=1;i<rates.size(); i++)
    {
        for(int j=0; j<StringHelper::string_to_int(rates.at(i)); j ++)
        {
            if(i == 1){Spawnrange.push_back('R');}

            if(i == 2){Spawnrange.push_back('P');}

            if(i == 3){Spawnrange.push_back('E');}
        }
    }

    unsigned  seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(Spawnrange.begin(), Spawnrange.end(), default_random_engine(seed));
    char call  = Spawnrange.at(RandomGenerator::generateRandomNumber(0,99));

    return call;
}
