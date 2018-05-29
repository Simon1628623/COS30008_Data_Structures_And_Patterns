#pragma once

#include "DoublyLinkedNodeIterator.h"
#include <iostream>

using namespace std;

void testDoublyLinkedNodeIterator()
{
	typedef DoublyLinkedNode<int>::Node IntNode;

	IntNode n1(1);
	IntNode n2(2);
	IntNode n3(3);
	IntNode n4(4);
	IntNode n5(5);
	IntNode n6(6);

	n1.append(n6);
	n1.append(n5);
	n1.append(n4);
	n1.append(n3);
	n1.append(n2);
	
	DoublyLinkedNodeIterator<int> iter(n1);

	iter--;
	cout << "Forward iterator I:" << endl;
	for (iter++; iter != iter.rightEnd(); iter++)
		cout << *iter << endl;

	cout << "Backwards iterator I:" << endl;
	for (iter--; iter != iter.leftEnd(); iter--)
		cout << *iter << endl;

	cout << "Backward iteration II:" << endl;
	for (iter = iter.last(); iter != iter.leftEnd(); --iter)
		cout << *iter << endl;
	DoublyLinkedNodeIterator<int> iter2(DoublyLinkedNode<int>::NIL);

	if (iter2 == iter2.rightEnd())
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	if (iter2.first() == iter2.rightEnd())
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	if (iter2.last() == iter2.leftEnd())
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}

//Forward iteration I :
//1
//2
//3
//4
//5
//6
//Backward iteration I :
//6
//5
//4
//3
//2
//1
//Forward iteration II :
//1
//2
//3
//4
//5
//6
//Backward iteration II :
//6
//5
//4
//3
//2
//1
//YES
//YES
//YES



int main()
{
	testDoublyLinkedNodeIterator();
	return 0;
}
