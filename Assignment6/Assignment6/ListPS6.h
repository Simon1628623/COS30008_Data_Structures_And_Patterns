#pragma once

template<class T>
// copy constructor
//deep copy allocating new memory and a new pointer to instance
List<T>::List(const List& aOtherList)
{
	//empties vars
	fTop = &Node::NIL;
	fLast = &Node::NIL;
	fCount = 0;

	//assigning new lists
	for (int i = 0; i < aOtherList.size(); i++)
	{
		push_back(aOtherList[i]);
	}
}

template<class T>
// assignment operator
//initializing instance variables after releasing previous memory
List<T>& List<T>::operator=(const List& aOtherList)
{
	//prevents suicide
	if (&aOtherList != this)
	{
		while (fTop != &Node::NIL)
		{
			Node* temp = (Node *)&fTop->getNext();  // get next node (to become top)
			fTop->remove();                         // move first node
			delete fTop;							// free node memory
			fTop = temp;							// make temp the new top
		}
		
		for (int i = 0; i < aOtherList.size(); i++)
		{
			push_back(aOtherList[i]);
		}
	}
	return *this;
}