#pragma once

#include <string>

using namespace std;

class teacher {
private:
	char delimiter = '#';

public:
	char name[20];
	char surname[20];
	char patronymic[20];

	void writeToConsole();

	static teacher createFromConsole();
	static teacher createFromFile(string* data);

	string toFileString();

	friend ostream& operator << (ostream& output, teacher& u) {
		output << u.toFileString();
		return output;
	}

	friend bool operator > (teacher& first, teacher& second) {
		return (int)first.name[0] > (int)second.name[0];
	}

	friend bool operator < (teacher& first, teacher& second) {
		return (int)first.name[0] < (int)second.name[0];
	}

	friend bool operator == (teacher& first, teacher& second) {
		return (int)first.name[0] == (int)second.name[0];
	}

	friend bool operator >= (teacher& first, teacher& second) {
		return (int)first.name[0] >= (int)second.name[0];
	}

	friend bool operator <= (teacher& first, teacher& second) {
		return (int)first.name[0] <= (int)second.name[0];
	}
};
