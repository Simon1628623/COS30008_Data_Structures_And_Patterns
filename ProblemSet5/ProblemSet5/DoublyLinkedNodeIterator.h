#pragma once

#include "DoublyLinkedNode.h"

template<class DataType>
class DoublyLinkedNodeIterator
{
private:
	enum IteratorStates{BEFORE, DATA, AFTER};

	//donotes whether the iterator is before the first element or after the last
	//clearly mark when the iterator is before the first element, within first and last or after the last element
	IteratorStates fState;

	typedef DoublyLinkedNode<DataType> Node;

	const Node* fLeftmost;
	const Node* fRightmost;
	const Node* fCurrent;

public:
	typedef DoublyLinkedNodeIterator<DataType> Iterator;

	//constructor to properly set fLeftmost, fRightmost and fCurrent. position iterator on the first element of the list
	//if we pass an empty list to the iterator, the constructor has to set up the state to AFTER in order to consistent with == and != operators
	DoublyLinkedNodeIterator(const Node& aList)
	{
		fLeftmost = &aList.getPrevious();
		fRightmost = &aList.getNext();
		fCurrent = &aList;
		fState = DATA;

		if (&aList == &Node::NIL)
			fState = AFTER;
	}
	
	//dereference to access current element the iterator is positioned on
	const DataType& operator*() const
	{
		return fCurrent->getValue();
	}

	//prefix increment to next element
	Iterator& operator++()
	{	
		//all increment or decrement operators have to test is the iterator is still positioned within the collection
		if (fState == DATA || fState == BEFORE)
		{
			fCurrent = &fCurrent->getNext();

			//increment state machine
			switch (fState)
			{
			case BEFORE:
				if (*this != rightEnd())
				{
					fState = DATA;
				}
				if (*this == rightEnd())
				{
					fState = AFTER;
				}
				break;
			case DATA:
				if (*this == rightEnd())
				{
					fState = AFTER;
				}
				if (*this != rightEnd())
				{
					fState = DATA;
				}
				break;
			case AFTER:
				if (*this == rightEnd())
				{
					fState = AFTER;
				}
				break;
			}
		}
		else
		{
			throw "Iterator out of range";
		}
		return *this;
	}

	//postfix increment
	Iterator operator++(int)
	{
		Iterator temp = *this;
		
		//reusing code from prefix
		fCurrent++;

		return temp;
		//return fCurrent->getPrevious();
	}

	//prefix decrement to previous element 
	Iterator& operator--()
	{
		if (fState == DATA || fState == AFTER)
		{
			fCurrent = &fCurrent->getPrevious();

			//decrement state machine
			switch (fState)
			{
			case BEFORE:
				if (*this == leftEnd())
				{
					fState = BEFORE;
				}
				break;
			case DATA:
				if (*this == leftEnd())
				{
					fState = BEFORE;
				}
				if (*this != leftEnd())
				{
					fState = DATA;
				}
				break;
			case AFTER:
				if (*this == leftEnd())
				{
					fState = BEFORE;
				}
				if (*this != leftEnd())
				{
					fState = DATA;
				}
				break;
			}
		}
		else
		{
			throw "Iterator out of range";
		}
		return *this;
	}

	//postfix decrment
	Iterator operator--(int)
	{
		Iterator temp = *this;
		
		//reusing code from prefix
		fCurrent--;
		
		return temp;
		//return fCurrent->getNext();
	}

	bool operator==(const Iterator& aOtherIter) const
	{
		return (fCurrent == aOtherIter.fCurrent) && (&fCurrent->getPrevious() == &aOtherIter.fCurrent->getPrevious()) && (&fCurrent->getNext() == &aOtherIter.fCurrent->getNext());
	}
	
	bool operator!=(const Iterator& aOtherIter) const
	{
		return !(*this == aOtherIter);
	}

	//returns a new list iterator positioned before the first element of the dln
	Iterator leftEnd() const
	{
		Iterator it = *this;
		
		while (it.fState == DATA)
			it--;

		return it;
	}
	//a new iterator positioned on the first element
	Iterator first() const
	{
		Iterator it = *this;

		while (it.fState == DATA)
			it--;
		it++;

		return it;
	}
	//a new iterator positioned on the last element
	Iterator last() const
	{
		Iterator it = *this;

		while (fState == DATA)
			it++;
		it--;
		
		return it;
	}
	//returns new iterator that is positioned after the last element of the doubly linked list
	Iterator rightEnd() const
	{
		Iterator it = *this;
		
		while (fState == DATA)
			it++;

		return it;
	}
};