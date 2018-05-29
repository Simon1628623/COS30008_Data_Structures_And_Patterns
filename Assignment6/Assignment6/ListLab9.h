
// COS30008, Tutorial 9, 2016

#pragma once

template<class T>
List<T>::List()
{
	fTop = &Node::NIL;					// initialize top                                   2
	fLast = &Node::NIL;					// initialize last                                  2
	fCount = 0;							// initialize count                                 1/5
}

template<class T>
void List<T>::push_back( const T& aElement )
{
	Node* lNewElement = new Node( aElement );	// create a new node						3
    
	if ( fTop == &Node::NIL )					// Is this the first node?					3
	{
		fTop = lNewElement;						// make lNewNode first node					1
		fLast = lNewElement;					// make lNewNode last node as well			1
	}
	else
	{
		fLast->append( *lNewElement );          // make lNewElement next of last			3
		fLast = lNewElement;					// make lNewNode last node					1
	}
    
	fCount++;									// increment count							2/14
}

template<class T>
void List<T>::remove( const T& aElement )
{
	Node* lNode = fTop;							// start from the top						2
    
	while ( lNode != &Node::NIL )				// Are there still nodes available?			3
	{
		if ( lNode->getValue() == aElement )	// Have we found the node?					3
			break;								// stop the search							1
		lNode = (Node *)&lNode->getNext();      // move to next node						3
	}
    
	// At this point we have either reached the end or found the node.
	if ( lNode != &Node::NIL )						// We have found the node.				3
	{
		if ( lNode == fTop )						// Was it the first node?				2
		{
			fTop = (Node *)&lNode->getNext();		// set top to next of node				3
		}
		if ( lNode == fLast )						// Was it the last node?				2
		{
			fLast = (Node *)&lNode->getPrevious();	// set last to previous of node			3
		}
        
		lNode->remove();							// isolate node							2
		delete lNode;								// release node's memory 				2
		fCount--;									// decrement count						2/31
	}
}

template<class T>
const T& List<T>::operator[]( unsigned int aIndex ) const
{
	if ( aIndex < fCount )                                  // Is index within bounds?		3
	{
		Node* lNode = fTop;									// start from the top			2
		while ( aIndex )									// Have we reached the index?	2
		{
			// No
			aIndex--;										// decrement index				1
			lNode = (Node*)&lNode->getNext();				// move to next node			3
		}
		// Yes
		return lNode->getValue();							// return node value			3
	}
	else
	{
		throw std::range_error( "Index out of bounds." );	// signal error					3/17
	}
}

template<class T>
//DoublyLinkedNodeIterator<T> List<T>::getIterator() const
typename List<T>::Iterator List<T>::getIterator() const
{
	return Iterator( *fTop );					// return a node iterator                   3
}
