// COS30008, Tutorial 12, 2016 - Unit Testing
#pragma once
#include "Node.h"
template<class DataType>
class NodeIterator
{
private:
	enum IteratorStates { DATA, END };
	typedef Node<DataType>* NodeImpl;
	NodeImpl fTop;
	NodeImpl fLast;
	NodeImpl fCurrent;
	IteratorStates fState;
public:
	NodeIterator(NodeImpl aList)
	{
		fTop = aList;
		// set current to top element;
		fCurrent = fTop;
		// set fLAST
		if (aList)
		{
			fLast = aList;
			while (fLast->fNext != (NodeImpl)0)
				fLast = fLast->fNext;
		}
		else
			fLast = (NodeImpl)0;
		// set state
		fState = fCurrent ? DATA : END;
	}
	DataType operator*() const
	{
		//error!!!!!
		//return fCurrent->fValue;
		return fCurrent->fValue;
	}
	NodeIterator& operator++() // prefix increment
	{
		if (fState == DATA)
		{
			fCurrent = fCurrent->fNext;
				// end of list?
				if (fCurrent == (Node<DataType>*)0)
					fState = END;
		}
		return *this;
	}
	NodeIterator operator++(int) // postfix increment
	{
		NodeIterator<DataType> Result = *this;
		++(*this);
		return Result;
	}
	bool operator==(const NodeIterator& aOtherIter) const
	{
		return (fCurrent == aOtherIter.fCurrent) &&
			(fTop == aOtherIter.fTop) &&
			(fState == aOtherIter.fState);
	}
	bool operator!=(const NodeIterator& aOtherIter) const
	{
		return !(*this == aOtherIter);
	}
	NodeIterator end() const
	{
		NodeIterator<DataType> Result = *this;
		Result.fCurrent = (NodeImpl)0;
		Result.fState = END;
		return Result;
	}
};