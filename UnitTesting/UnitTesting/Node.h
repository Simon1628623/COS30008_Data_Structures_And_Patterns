// COS30008, Tutorial 12, 2016 - Unit Testing
#pragma once
template<class DataType>
class Node
{
public:
	const DataType& fValue;
	Node<DataType>* fNext;
	Node<DataType>* fPrevious;
	Node(const DataType& aValue,
		Node<DataType>* aNext = (Node<DataType>*)0,
		Node<DataType>* aPrevious = (Node<DataType>*)0) :
		fValue(aValue)
	{
		fNext = aNext;
		if (fNext != (Node<DataType>*)0)
			fNext->fPrevious = this;
		fPrevious = aPrevious;
		if (fPrevious != (Node<DataType>*)0)
			fPrevious->fNext = this;
	}
	~Node()
	{
		if (fNext != (Node<DataType>*)0)
			fNext->fPrevious = fPrevious;
		if (fPrevious != (Node<DataType>*)0)
			fPrevious->fNext = fNext;
	}
};

//copy constructor
//value of dereference stored on list when added in list requires refrence not object itself
//copy contructor creates new node pointing to actual value
//stack deletes local var after function ends