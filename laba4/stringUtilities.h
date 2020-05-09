#pragma once

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class stringUtilities {
public:
	static vector<char*> split(string data, char delimiter);
};

