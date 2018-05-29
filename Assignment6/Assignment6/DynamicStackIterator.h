#pragma once
#include "DynamicStack.h"
template<class T>
class DynamicStackIterator
{
private:
	DynamicStack<T> fStack;
public:
	DynamicStackIterator(const DynamicStack<T>& aStack);
	const T& operator*() const; // dereference
	DynamicStackIterator& operator++(); // prefix increment
	DynamicStackIterator operator++(int); // postfix increment
	bool operator==(const DynamicStackIterator& aOtherIter) const;
	bool operator!=(const DynamicStackIterator& aOtherIter) const;
	DynamicStackIterator end() const; // new iterator (after last element)
};

//constructor
template<class T>
DynamicStackIterator<T>::DynamicStackIterator(const DynamicStack<T>& aStack)
{
	fStack = aStack;
}

//dereference
template<class T>
const T& DynamicStackIterator<T>::operator*() const
{
	//returning top of stack
	return fStack.top();
}

//prefix increment
template<class T>
DynamicStackIterator<T>& DynamicStackIterator<T>::operator++()
{
	//increment operations
	fStack.pop();
	return *this;
}

//postfix increment
template<class T>
DynamicStackIterator<T> DynamicStackIterator<T>::operator++(int)
{
	DynamicStackIterator temp = *this;
	++(*this);
	return temp;
}

//equivalence operator
//cannot compare Dynamic stack objects directly without destroying the stacks.
//only compare the respective stack sizes when defining operator== and !=
template<class T>
bool DynamicStackIterator<T>::operator==(const DynamicStackIterator& aOtherIter) const
{
	return fStack.size() == aOtherIter.fStack.size();
}

//not equivalence operator
template<class T>
bool DynamicStackIterator<T>::operator!=(const DynamicStackIterator& aOtherIter) const
{
	return !(*this == aOtherIter);
}

// new iterator (after last element)
//must be consistent with == and !=
template<class T>
DynamicStackIterator<T> DynamicStackIterator<T>::end() const
{
	DynamicStackIterator temp = *this;
	
	//move to end
	while (!temp.fStack.isEmpty())
		temp.fStack.pop();
	
	return temp;
}