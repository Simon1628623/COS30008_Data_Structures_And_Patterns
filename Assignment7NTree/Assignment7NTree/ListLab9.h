
// COS30008, Tutorial 9, 2016

#pragma once

template<class T>
List<T>::List()
{
	fTop = &Node::NIL;					// initialize top                               
	fLast = &Node::NIL;					// initialize last                                  
	fCount = 0;							// initialize count                                 
}

template<class T>
void List<T>::push_back( const T& aElement )
{
	Node* lNewElement = new Node( aElement );	// create a new node						
    
	if ( fTop == &Node::NIL )					// Is this the first node?					
	{
		fTop = lNewElement;						// make lNewNode first node					
		fLast = lNewElement;					// make lNewNode last node as well			
	}
	else
	{
		fLast->append( *lNewElement );          // make lNewElement next of last			
		fLast = lNewElement;					// make lNewNode last node					
	}
    
	fCount++;									// increment count							
}

template<class T>
void List<T>::remove( const T& aElement )
{
	Node* lNode = fTop;							// start from the top						
    
	while ( lNode != &Node::NIL )				// Are there still nodes available?			
	{
		if ( lNode->getValue() == aElement )	// Have we found the node?					
			break;								// stop the search							
		lNode = (Node *)&lNode->getNext();      // move to next node						
	}
    
	// At this point we have either reached the end or found the node.
	if ( lNode != &Node::NIL )						// We have found the node.				
	{
		if ( lNode == fTop )						// Was it the first node?				
		{
			fTop = (Node *)&lNode->getNext();		// set top to next of node				
		}
		if ( lNode == fLast )						// Was it the last node?				
		{
			fLast = (Node *)&lNode->getPrevious();	// set last to previous of node			
		}
        
		lNode->remove();							// isolate node							
		delete lNode;								// release node's memory 				
		fCount--;									// decrement count						
	}
}

template<class T>
const T& List<T>::operator[]( unsigned int aIndex ) const
{
	if ( aIndex < fCount )                                  // Is index within bounds?		
	{
		Node* lNode = fTop;									// start from the top			
		while ( aIndex )									// Have we reached the index?	
		{
			// No
			aIndex--;										// decrement index				
			lNode = (Node*)&lNode->getNext();				// move to next node			
		}
		// Yes
		return lNode->getValue();							// return node value			
	}
	else
	{
		throw std::range_error( "Index out of bounds." );	// signal error					
	}
}

template<class T>
//DoublyLinkedNodeIterator<T> List<T>::getIterator() const
typename List<T>::Iterator List<T>::getIterator() const
{
	return Iterator( *fTop );					// return a node iterator                   
}
