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
using namespace std;

#ifndef ELEVATOREMULATOR_FILEREAD_H
#define ELEVATOREMULATOR_FILEREAD_H


class FileRead {

public:
    /*
     * Attributes
     */
    std::string line;
    string result {};
    int counter = 1;
    vector<std::string> buldingSetup;
    map<int, vector<vector<std::string>>> PData;

private:
    /*
     * Constructor and Destructor
     */
    static FileRead* instance;
    FileRead();

public:
    ~FileRead();

public:
    /*
     * Methods
     */
    void readFile(std::string path);
    static FileRead* getInstance();
};


#endif //ELEVATOREMULATOR_FILEREAD_H
