#include "Format_functions.h"
#include <sstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Format_functions::Format_functions(){
    cout<<"using created funcitons"<<endl;
}

void Format_functions::string_split(stringstream& target, vector<string>& out, string filter){
    vector<string> temp;
	vector<string>::iterator v_it;
	string word;
	for (int filter_char = 0; filter_char < (filter.length()); filter_char++) {
		if (filter_char == 0) {
			while (getline(target, word, filter[filter_char])) {
				temp.push_back(word);
			}
		}
		else {
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

}

void Format_functions::string_to_int(vector<string>& input, vector<int>& output){
    vector<string>::iterator vs_it;
    for(vs_it = input.begin(); vs_it != input.end(); vs_it++){
        output.push_back(stoi(*vs_it));
    }
}