// COS30008, Tutorial 12, 2016 - Unit Testing
#include "List.h"
#include <iostream>
#include <string>
using namespace std;
int main()
{
	List<string> l;
	string s1("One");
	string s2("Two");
	string s3("Three");
	string s4("Four");
	l.add(s1);
	l.add(s2);
	l.add(s3);
	l.add(s4);
	cout << "The list:" << endl;
	for (List<string>::ListIterator iter = l.iterator();
		iter != iter.end(); iter++)
		cout << *iter << endl;
	List<string> copy = l;
	cout << "The copy:" << endl;
	for (List<string>::ListIterator iter = copy.iterator();
		iter != iter.end(); iter++)
		cout << *iter << endl;
	return 0;
}

//if variables declared inside a function they will be removed from the stack when the function ends deleting the value