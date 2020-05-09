#include "stringUtilities.h"
#include <string>
#include <iostream>
#include <regex>
#include <vector>

using namespace std;

vector<char*> stringUtilities::split(string data, char delimiter) {
	vector<char*> m;

	size_t pos = 0;
	std::string token;
	while ((pos = data.find(delimiter)) != std::string::npos) {
		token = data.substr(0, pos);
		m.push_back(_strdup(token.c_str()));
		data.erase(0, pos + 1);
	}

	if (data != "")
		m.push_back(_strdup(data.c_str()));

	return m;
}