#include "univer.h"
#include "teacher.h"
#include <iostream>
#include "stringUtilities.h"
#include "typeSort.h"

using namespace std;

void univer::addTeacher(teacher t) {
	teachers.push_back(t);
}

string univer::printToFile() {
	string data = name + delimiter + to_string(number_of_faculties) + delimiter + to_string(number_of_graduates) + delimiter;

	auto it = teachers.begin();
	while (it != teachers.end()) {
		data += (*it).toFileString() + delimiter;
		it++;
	}

	return data;
}

univer univer::createFromFile(string data) {
	univer u;

	auto dataSplitted = stringUtilities::split(data, u.delimiter);

	strcpy_s(u.name, sizeof(u.name), dataSplitted.at(0));
	u.number_of_faculties = std::stoi(dataSplitted.at(1));
	u.number_of_graduates = std::stoi(dataSplitted.at(2));

	for (int i = 3; i < dataSplitted.size(); i++)
		u.teachers.push_back(teacher::createFromFile(&string(dataSplitted.at(i))));

	return u;
}

univer univer::createFromConsole() {
	univer u;
	cout << endl;

	cout << "name of university: ";
	cin >> u.name;

	cout << "number of faculties: ";
	cin >> u.number_of_faculties;

	cout << "number of graduates: ";
	cin >> u.number_of_graduates;

	int numberOfTeachers;
	cout << "number of teachers: ";
	cin >> numberOfTeachers;
	for (int i = 0; i < numberOfTeachers; i++)
		u.addTeacher(teacher::createFromConsole());

	return u;
}

void univer::writeToConsole() {
	cout << "name of university: " << name << endl
		<< "number of faculties: " << number_of_faculties << endl
		<< "number of graduates: " << number_of_graduates << endl
		<< "data about teachers: " << endl;

	for (int i = 0; i < teachers.size(); i++) {
		auto k = teachers.at(i);
		k.writeToConsole();
		if (i != teachers.size() - 1)
			cout << endl;
	}
}

int univer::getValueSortedProperty() {
	switch (sortedVariable)
	{
	case typeSort::numberOfFacultiesProperty:
		return number_of_faculties;
	case typeSort::numberOfGraduatesProperty:
		return number_of_graduates;
	case typeSort::nameProperty:
	default:
		return (int)name[0];
	}
}