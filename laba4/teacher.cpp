#include "teacher.h"
#include <iostream>
#include <string>
#include "stringUtilities.h"

using namespace std;

teacher teacher::createFromConsole() {
	teacher t;

	cout << "	write data about teacher:" << endl;
	cout << "		name: ";
	cin >> t.name;

	cout << "		surname: ";
	cin >> t.surname;

	cout << "		patronymic: ";
	cin >> t.patronymic;

	return t;
}

teacher teacher::createFromFile(string* data) {
	teacher t;

	auto dataSplitted = stringUtilities::split(*data, t.delimiter);

	strcpy_s(t.name, sizeof(t.name), dataSplitted.at(0));
	strcpy_s(t.surname, sizeof(t.surname), dataSplitted.at(1));
	strcpy_s(t.patronymic, sizeof(t.patronymic), dataSplitted.at(2));

	return t;
}

string teacher::toFileString() {
	char result[sizeof(name) + sizeof(surname) + sizeof(patronymic) + 3];
	strcpy_s(result, sizeof(name), name);
	strcat_s(result, 1, &delimiter);
	strcat_s(result, sizeof(surname), surname);
	strcat_s(result, 1, &delimiter);
	strcat_s(result, sizeof(patronymic), patronymic);
	return string(result);
}

void teacher::writeToConsole() {
	cout << "\tname: " << name << endl
		<< "\tsurname: " << surname << endl
		<< "\tpatronymic: " << patronymic;
}