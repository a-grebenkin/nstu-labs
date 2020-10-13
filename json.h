#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include "generators/BaseGenerator.h"

using namespace std;

class JSONDecoder {
public:
	JSONDecoder(istream& stream);

	string name;
	
	size_t N = 0;

	vector<string> generators;

	vector<double> sequence;

	GEN_TYPES genType = GEN_TYPES::BASE;

	map<string, string> additional_data;

private:
	string readString(istream& stream);

	string readKey(istream& stream);

	int readInt(istream& stream);

	vector<double> readDoubleArray(istream& stream);

	vector<string> readStringArray(istream& stream);

	string readDynamicToken(istream& stream);
};