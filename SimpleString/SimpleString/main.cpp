#pragma once

#include <iostream>
#include "SimpleString.h"
#include "Handle.h"

using namespace std;
/*
int main()
{
	SimpleString s1;
	s1 + 'A';
	SimpleString s2 = s1;
	s2 + 'B';

	s1 = s2;
	cout << "S1: " << *s1 << endl;
	cout << "S2: " << *s2 << endl;

	return 0;
}
*/

/*
int main()
{
	SimpleString* ps1 = new SimpleString();
	(*ps1) + 'A';
	SimpleString* ps2 = ps1->clone();
	(*ps2) + 'B';

	cout << "S1: " << **ps1 << endl;
	cout << "S2: " << **ps2 << endl;

	delete ps1;
	delete ps2;

	return 0;
}
*/

int main()
{
	Handle<SimpleString> hs1(new SimpleString());
	*hs1 + 'A';
	Handle<SimpleString> hs2(hs1->clone());
	*hs2 + 'B';
	Handle<SimpleString> hs3 = hs1;

	cout << "HS1: " << **hs1 << endl;
	cout << "HS2: " << **hs2 << endl;
	cout << "HS3: " << **hs3 << endl;

	return 0;
}