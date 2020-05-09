#pragma once

#include <string>
#include <vector>
#include <iostream>
#include "teacher.h"
#include "typeSort.h"

using namespace std;

class univer {

private:
	char delimiter = '_';
public:
	char name[20];
	int number_of_faculties;
	int number_of_graduates;
	vector<teacher> teachers;
	typeSort sortedVariable = typeSort::nameProperty;

	void addTeacher(teacher t);

	string printToFile();
	void writeToConsole();
	int getValueSortedProperty();

	static univer createFromFile(string data);

	static univer createFromConsole();

	static auto sortByName() {
		return [](const univer& o1, const univer& o2) -> bool {
			return o1.name[0] > o2.name[0];
		};
	}

	static auto compareDupplicateByName() {
		return [](const univer& u1, const univer& u2) -> bool {
			return strcmp(u1.name, u2.name) == 0;
		};
	}

	static auto compareFirstIncludeByName() {
		return [](const univer& u1, const univer& u2) -> bool {
			return strcmp(u1.name, u2.name) == 0;
		};
	}

	friend ostream& operator << (ostream& output, univer& u) {
		u.writeToConsole();
		return output;
	}

	friend bool operator >= (univer& first, univer& second) {
		return first.getValueSortedProperty() >= second.getValueSortedProperty();
	}

	friend bool operator < (univer& first, univer& second) {
		return first.getValueSortedProperty() < second.getValueSortedProperty();
	}

	friend bool operator > (univer& first, univer& second) {
		return first.getValueSortedProperty() > second.getValueSortedProperty();
	}

	bool operator== (univer& rhs) {
		return getValueSortedProperty() == rhs.getValueSortedProperty();
	}
};