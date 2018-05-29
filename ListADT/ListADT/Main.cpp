
// COS30008, Tutorial 9, 2016

#include <iostream>
#include <string>
#include "List.h"

using namespace std;

int main()
{
#define A
#ifdef A
	// Step 1:
	// implement:
	// - default constructor
	// - getIterator

	string s1( "AAAA" );
	string s2( "BBBB" );
	string s3( "CCCC" );
	string s4( "DDDD" );

	List<string> lList;

	lList.push_front( s4 );
	lList.push_front( s3 );
	lList.push_front( s2 );
	lList.push_front( s1 );

	// iterate from the top
	cout << "Top to bottom: " << lList.size() << " elements" << endl;
	for ( List<string>::Iterator iter = lList.getIterator();
			iter != iter.rightEnd(); iter++ )
	{
		cout << "A list element: " << *iter << endl;
	}
	
#endif
#define B    
#ifdef B
	// Step 2:
	// implement:
	// - push_back

	string s5( "EEEE" );
	string s6( "FFFF" );

	lList.push_back( s5 );
	lList.push_back( s6 );

	// iterate from the last
	cout << "Bottom to top: " << lList.size() << " elements" << endl;
	for ( List<string>::Iterator iter = lList.getIterator().last();
			iter != iter.leftEnd(); iter-- )
	{
		cout << "A list element: " << *iter << endl;
	}

#endif
#define C
#ifdef C
	// Step 3:
	// implement:
	// - remove

	lList.remove( s3 );
	lList.remove( s1 );
	lList.remove( s6 );

	// iterate from the top
	cout << "Top to bottom: " << lList.size() << " elements" << endl;
	for ( List<string>::Iterator iter = lList.getIterator();
			iter != iter.rightEnd(); iter++ )
	{
		cout << "A list element: " << *iter << endl;
	}

#endif
#define D    
#ifdef D
	// Step 4:
	// implement:
	// - operator[]

	cout << "Element at index 2: " << lList[2] << endl;

#endif
    
	return 0;
}
