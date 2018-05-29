#include <iostream>
#include "IntArrayIterator.h"

using namespace std;
//arrays are passed as pointers to first elements to functions           we must not repeat the default val
IntArrayIterator::IntArrayIterator(const int aArray[], const int aLength, int aStart) : fArrayElements(aArray), fLength(aLength) // must use member initialize const intance vars
{
	fIndex = aStart;
}

//dereference operator
//dereference operator returns element the iterator is currently postioned on
//const as it does not change any isntance vars of the iterator
//const avoids copying original value stored in collection
const int& IntArrayIterator::operator*() const
{
	return fArrayElements[fIndex];
}

//prefix increment
//advances iterator and returns a reference of this iterator
IntArrayIterator& IntArrayIterator::operator++()
{
	fIndex++;
    //returns a reference to the current iterator (set forward)
	return *this;
}

//postfix increment
//advances iterator and returns a copy of the old iterator
IntArrayIterator IntArrayIterator::operator++(int)
{
	IntArrayIterator temp = *this;
	fIndex++;
    //returns a copy of the old iterator(position unchanged)
	return temp;
}

//Iterator Equivalence
//two iterators are equal if and only if they refer to the same element 
//fIndex is current index of array
//arrays are passed as a pointer to the first element that is constant throught runtime
bool IntArrayIterator::operator==(const IntArrayIterator& aOther) const
{
	//only works in ideal situation
    return (fIndex == aOther.fIndex) && (fArrayElements == aOther.fArrayElements);
}

//iterator inequality
bool IntArrayIterator::operator!=(const IntArrayIterator& aOther) const
{
	return !(*this == aOther);
}

//Auxiliary Methods
//return fresh iterators set to the first element and past the end element
IntArrayIterator IntArrayIterator::begin() const
{
	return IntArrayIterator(fArrayElements, fLength);; //we use the default value 0 for aSTart here
}

IntArrayIterator IntArrayIterator::end() const
{
	return IntArrayIterator(fArrayElements, fLength, fLength);
}