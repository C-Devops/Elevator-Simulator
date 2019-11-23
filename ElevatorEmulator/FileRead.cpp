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

#include <stdlib.h>     /* exit, EXIT_FAILURE */
using namespace std;

#include "FileRead.h"
#include "StringHelper.h"

FileRead* FileRead::instance = 0;

FileRead* FileRead::getInstance()
{
    if (instance == 0)
    {
        instance = new FileRead();
    }

    return instance;
}

FileRead::FileRead()
{}

FileRead::~FileRead()
{

}

void FileRead::readFile(std::string path)
{
	std::ifstream in_file(path);
	/*try {
		
		if (in_file.bad()) {
			throw "Error couldn't read file";
		}
	}
	catch (string e) {
		cout << e << ": FileReader" << endl;
		exit(EXIT_FAILURE);
	}*/

    //std::stringstream ss(line);

    vector<std::string> TemLine;

    vector<std::string> Rate;
    vector<std::string> Call;
    vector<std::string> Weight;

    int PassengerCounter = 1;

	cout << "--------------- File Contents ----------------" << endl;

    while (std::getline(in_file, line))
    {
		cout << line << endl;
        std::stringstream ss(line);

        if (counter <=3)                                        // Logic for reading First Three Line
        {
            while  (ss >> result)
            {
                buldingSetup.push_back(result);                     // ['8','4', '12', '10']
            }
        }
        else                                                           // Rest of Lines
        {
            TemLine = (StringHelper::string_split_f(ss, "CE"));     // ['Visitors 0.15', '100 0 0 ']
            if(TemLine.size() !=3)
            {
                TemLine.push_back(" 1 1");                          //  ['Visitors 0.15', '100 0 0 ', '1 1']
            }
            else
            {

            }

            stringstream tem_rate(TemLine.at(0));
            Rate = StringHelper::string_split_f(tem_rate, " ");             // ['Visitors', '0.15']

            stringstream tem_call(TemLine.at(1));
            Call = StringHelper::string_split_f(tem_call, " ");             // ['100', '0', '0']

            stringstream tem_weight(TemLine.at(2));
            Weight = StringHelper::string_split_f(tem_weight, " ");         // ['1', '1']

            PData[PassengerCounter].push_back(Rate);
            PData[PassengerCounter].push_back(Call);
            PData[PassengerCounter].push_back(Weight);

            /*
             *      {
             *          1: [
             *                  ['Visitors', '0.15'],
             *                  ['100', '0', '0'],
             *                  ['1', '1']
             *              ],
             *     .
             *     .
             *     .
             *     }
             */

            PassengerCounter = PassengerCounter + 1;

        }

        counter = counter + 1;
    }
	cout << "----------------------------------------------\n" << endl;

    PData[0].push_back(buldingSetup);
    /*
           *      {
           *          0:[['8','4','12','10'],],
           *
           *          1: [
           *                  ['Visitors', '0.15'],
           *                  ['100', '0', '0'],
           *                  ['1', '1'],
           *              ],
           *     .
           *     .
           *     .
           *     }
           */

}