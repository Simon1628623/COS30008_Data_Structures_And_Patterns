
// COS30008, Problem set 7, 2016

#include "NTree.h"

#include <string>
#include <iostream>

using namespace std;

int main()
{
	string A( "A" );
	string A1( "AA" );
	string A2( "AB" );
	string A3( "AC" );
	string AA1( "AAA" );
	string AB1( "ABA" );
	string AB2( "ABB" );

	typedef NTree<string,3> NS3Tree;

	NS3Tree root( A );
    
	root.attachNTree( 0, *(new NS3Tree( A1 )) );
	root.attachNTree( 1, *(new NS3Tree( A2 )) );
	root.attachNTree( 2, *(new NS3Tree( A3 )) );

	root[0].attachNTree( 0, *(new NS3Tree( AA1 )) );
	root[1].attachNTree( 0, *(new NS3Tree( AB1 )) );
	root[1].attachNTree( 1, *(new NS3Tree( AB2 )) );

    NS3Tree copy = root;
    
    cout << "copy:       " << copy.key() << endl;
    cout << "copy[0]:    " << copy[0].key() << endl;
    cout << "copy[1]:    " << copy[1].key() << endl;
    cout << "copy[2]:    " << copy[2].key() << endl;
    cout << "copy[0][0]: " << copy[0][0].key() << endl;
    cout << "copy[1][0]: " << copy[1][0].key() << endl;
    cout << "copy[1][1]: " << copy[1][1].key() << endl;

    // test traversal
    TreeVisitor<string> v4;
    cout << "Breadth-first traversal:" << endl;
    root.traverseBreadthFirst( v4 );
    cout << endl;

    cout << "Success." << endl;
    
	return 0;
}

//copy: A
//copy[0] : AA
//copy[1] : AB
//copy[2] : AC
//copy[0][0] : AAA
//copy[1][0] : ABA
//copy[1][1] : ABB
//Breadth - first traversal :
//A AA AB AC AAA ABA ABB
//Success.
