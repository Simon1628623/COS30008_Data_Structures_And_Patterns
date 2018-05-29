
#include <string>
#include <iostream>

#include "NTree.h"

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
    NS3Tree nodeA1( A1 );
    NS3Tree nodeA2( A2 );
    NS3Tree nodeA3( A3 );
    NS3Tree nodeAA1( AA1 );
    NS3Tree nodeAB1( AB1 );
    NS3Tree nodeAB2( AB2 );
    
    
	root.attachNTree( 0, nodeA1 );
	root.attachNTree( 1, nodeA2 );
	root.attachNTree( 2, nodeA3 );

	root[0].attachNTree( 0, nodeAA1 );
	root[1].attachNTree( 0, nodeAB1 );
	root[1].attachNTree( 1, nodeAB2 );

	cout << "root:       " << root.key() << endl;
	cout << "root[0]:    " << root[0].key() << endl;
	cout << "root[1]:    " << root[1].key() << endl;
	cout << "root[2]:    " << root[2].key() << endl;
	cout << "root[0][0]: " << root[0][0].key() << endl;
	cout << "root[1][0]: " << root[1][0].key() << endl;
	cout << "root[1][1]: " << root[1][1].key() << endl;

    // test traversal
    PreOrderVisitor<string> v1;
    PostOrderVisitor<string> v2;
    LeftLinearVisitor<string> v3;
    
    cout << "Pre-order traversal:" << endl;
    root.traverseDepthFirst( v1 );
    cout << endl;
    
    cout << "Post-order traversal:" << endl;
    root.traverseDepthFirst( v2 );
    cout << endl;

    cout << "Left-linear traversal:" << endl;
    root.traverseDepthFirst( v3 );
    cout << endl;

    // test detachNTree
    
	root.detachNTree( 0 );

	if ( &root[0] == &NS3Tree::NIL )
		cout << "Detach succeeded." << endl;
	else
		cout << "Detach failed." << endl;

	return 0;
}

//root: A
//root[0] : AA
//root[1] : AB
//root[2] : AC
//root[0][0] : AAA
//root[1][0] : ABA
//root[1][1] : ABB
//Pre - order traversal :
//A AA AAA AB ABA ABB AC
//Post - order traversal :
//AAA AA ABA ABB AB AC A
//Left - linear traversal :
//[A[AA[AAA]][AB[ABA][ABB]][AC]]
//Detach succeeded.
