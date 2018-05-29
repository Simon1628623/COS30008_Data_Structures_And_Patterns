
// COS30008, Tutorial 9, 2016

#pragma once

#include "DoublyLinkedNode.h"
#include "DoublyLinkedNodeIterator.h"

#include <stdexcept>

template<class T> 
class List
{
private:
	// auxiliary definition to simplify node usage
	typedef DoublyLinkedNode<T> Node;

	Node* fTop;		// the first element in the list
	Node* fLast;	// the last element in the list
	int fCount;		// number of elements in the list

public:
	// auxiliary definition to simplify iterator usage
	typedef DoublyLinkedNodeIterator<T> Iterator;

	List();							// default constructor - creates empty list
	~List();						// destructor - frees all nodes

	bool isEmpty() const;	// Is list empty?
	int size() const;		// list size

	void push_front( const T& aElement );	// adds a node initialized with aElement at front
	void push_back( const T& aElement );	// adds a node initialized with aElement at back
	
	void remove( const T& aElement );	// remove node that matches aElement from list

	const T& operator[]( unsigned int aIndex ) const;	// list indexer
	
	Iterator getIterator() const;	// return an iterator for the nodes of the list
};

template<class T>
List<T>::~List()
{
	while ( fTop != &Node::NIL )
	{
		Node* temp = (Node *)&fTop->getNext();  // get next node (to become top)
		fTop->remove();                         // move first node
		delete fTop;							// free node memory
		fTop = temp;							// make temp the new top
	}
}

template<class T> 
bool List<T>::isEmpty() const
{
	return fTop == &Node::NIL;
}

template<class T> 
int List<T>::size() const
{
	return fCount;
}

template<class T>
void List<T>::push_front( const T &aElement )
{
	Node* lNewElement = new Node( aElement );	// create a new node

	if ( fTop == &Node::NIL )					// Is this the first node?
	{
		fTop = lNewElement;						// make lNewNode first node
		fLast = lNewElement;					// make lNewNode last node as well
	}
	else
	{
		fTop->prepend( *lNewElement );          // make lNewElement previous of top
		fTop = lNewElement;						// make lNewNode first node
	}

	fCount++;									// increment count
}

#include "ListLab9.h"    // your solution

