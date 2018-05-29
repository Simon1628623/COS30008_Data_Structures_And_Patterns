#include "CharacterCounterIterator.h"

using namespace std;

//It takes a CharacterCounter object and provides access to non - zero frequency FrequencyMap objects
//The iterator preserves the original array order, that is, the iterator returns FrequencyMap objects in the sequence determined by the ASCII encoding of characters
CharacterCounterIterator::CharacterCounterIterator(CharacterCounter& aCounter)
{
	//initialize frequency map
	for (int i = 0; i < 256; i++)
	{
		fMaps[i] = FrequencyMap(i, aCounter[i]);
	}

	//postion index on first non zero element (check operator++)
	fIndex = 0;
	while (fIndex < 256 && fMaps[fIndex].getFrequency() == 0)
	{
		fIndex++;
	}
}

//dereference operator
//dereference operator returns element the iterator is currently postioned on
//const as it does not change any isntance vars of the iterator
//const avoids copying original value stored in collection
const FrequencyMap& CharacterCounterIterator::operator*() const
{
    return fMaps[fIndex];
}

//prefix increment
//advances iterator and returns a reference of this iterator
CharacterCounterIterator& CharacterCounterIterator::operator++()
{
	//positions index on next non zero element
	fIndex++;
	while (fIndex < 256 && fMaps[fIndex].getFrequency() == 0)
	{
		fIndex++;
	}
	//returns a reference to the current iterator (set forward)
	return *this;
}

//postfix increment
//advances iterator and returns a copy of the old iterator
CharacterCounterIterator CharacterCounterIterator::operator++(int)
{
	CharacterCounterIterator temp = *this;
	
	++(*this);
    //returns a copy of the old iterator(position unchanged)
	return temp;
}

//Iterator Equivalence
//two iterators are equal if and only if they refer to the same element 
//fIndex is current index of array
//arrays are passed as a pointer to the first element that is constant throught runtime
bool CharacterCounterIterator::operator==(const CharacterCounterIterator& aOther) const
{
	//only works in ideal situation so we comment out collection and assume that is is correct
	return (fIndex == aOther.fIndex);// && (fMaps == aOther.fMaps);
}

//iterator inequality
bool CharacterCounterIterator::operator!=(const CharacterCounterIterator& aOther) const
{
	return !(*this == aOther);
}

//Auxiliary Methods
//return fresh iterators set to the first element 
CharacterCounterIterator CharacterCounterIterator::begin() const
{
	//no access to original character counter
	//solution copy and set copies fIndex to first non zero element
	CharacterCounterIterator temp = *this;
	temp.fIndex = -1; // start before 0
	++temp; //sets fIndex to 0 or first non zero frequency map
	
	
	return temp;
}

//and past the end element
CharacterCounterIterator CharacterCounterIterator::end() const
{
	//no access to original char counter so we copy and set above max value
	CharacterCounterIterator temp = *this;
	temp.fIndex = 256;
    return temp;
}