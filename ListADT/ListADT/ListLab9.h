#pragma once

#include "List.h"

// default constructor - creates empty list
template<class T>
List<T>::List()
{
	fTop = &Node::NIL;					// initialize top
	fLast = &Node::NIL;					// initialize last
	fCount = 0;							// initialize count
}


// return an iterator for the nodes of the list
// getIterator just returns a value-based DoublyLinkedNodeIterator object properly initialized with the top list node.
template<class T>
//DoublyLinkedNodeIterator<T> List<T>::getIterator() const
typename List<T>::Iterator List<T>::getIterator() const
{
	return Iterator(*fTop);					// return a node iterator                   
}

template<class T>
void List<T>::push_back(const T& aElement)
{
	Node* lNewElement = new Node(aElement);	// create a new node

	if (fTop == &Node::NIL)					// Is this the first node?
	{
		fTop = lNewElement;						// make lNewNode first node
		fLast = lNewElement;					// make lNewNode last node as well
	}
	else
	{
		fLast->append(*lNewElement);          // make lNewElement previous of bottom
		fLast = lNewElement;						// make lNewNode last node
	}

	fCount++;									// increment count
}

template<class T>
void List<T>::remove(const T& aElement)
{
	//identified node may coincide with the first node.
	Node* lNode = fTop;

	//while still is a node
	while (lNode != &Node::NIL)
	{
		//has to search for the node that matches aElement
		if (lNode->getValue() == aElement)
			break;
			//also need to cast operator Node* in this method to convert between const Node* and Node* 
			lNode = (Node *)&lNode->getNext();
	}
		//if no node exists, then the list remains unchanged.
		//corresponding node needs to be taken out of the list and its memory released.
		if (lNode != &Node::NIL)
		{
			//boundary conditions need to be addressed properly
			//is it first node
			if (lNode == fTop)
			{
				// set top to next of node
				fTop = (Node *)&lNode->getNext();		
			}
			if (lNode == fLast)
			{
				// set last to previous of node
				fLast = (Node *)&lNode->getPrevious();	
			}
		}
		// isolate node
		lNode->remove();
		// release node's memory
		delete lNode;
		// decrement count
		fCount--;									
	

	
}

//indexer has to search for the element that corresponds to aIndex 
//indexer has to throw a range_error if aIndex out of bounds
template <class T>
const T& List<T>::operator[](unsigned int aIndex) const
{
	//is within bounds
	if (aIndex < fCount)
	{
		//start from top
		Node* lNode = fTop;

		while (aIndex)
		{
			// No
			aIndex--;										// decrement index
			lNode = (Node*)&lNode->getNext();				// move to next node
		}
	// Yes
	return lNode->getValue();							// return node value
	}
	else 
		throw std::range_error("Index out of bounds.");	// signal error
}