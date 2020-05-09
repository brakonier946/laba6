#include <iostream>

#include <vector>
#include "Spisok.h"

using namespace std;

int main()
{
	Spisok<univer> s;

	s.add(univer::createFromConsole());
	s.add(univer::createFromConsole());
	s.add(univer::createFromConsole());
	s.add(univer::createFromConsole());

	
	s.sort(univer::sortByName());
	cout << endl << "print sorted data: " << endl;
	s.print();


	s.removeDuplicate(univer::compareDupplicateByName());
	cout << endl << "print with remove duplicate: " << endl;
	s.print();


	cout << endl << "write data for find first include: " << endl;
	Spisok<univer> ss;
	ss.add(univer::createFromConsole());
	ss.add(univer::createFromConsole());
	cout << "first include (index): " << s.firstInclude(ss.begin(), ss.end(), univer::compareFirstIncludeByName());

	return 0;
}
