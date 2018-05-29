#include "FibonacciIterator.h"

//Default Constructor to set up Fibonacci sequence
FibonacciIterator::FibonacciIterator(long aMaxN) : fMaxN(aMaxN), fCurrentN(1), fPrevious(0), fCurrent(1){}

//iterator methods
//return current Fibonacci number
const long& FibonacciIterator::operator*() const
{
	return fCurrent;
}
//prefix, next Fibonacci number
FibonacciIterator& FibonacciIterator::operator++()
{
	fCurrentN++;
	//moving sequence values
	long temp = fCurrent;
	fCurrent = fCurrent + fPrevious;
	fPrevious = temp;
	return *this;
}

//postfix
FibonacciIterator FibonacciIterator::operator++(int)
{
	FibonacciIterator temp = *this;

	//reusing code from prefix
	++(*this);

	return temp;
}

bool FibonacciIterator::operator==(const FibonacciIterator& aOther) const
{
	return fCurrentN == aOther.fCurrentN && fMaxN == aOther.fMaxN;
}

bool FibonacciIterator::operator!=(const FibonacciIterator& aOther) const
{
	return !(*this == aOther);
}

//auxiliaries
// return new iterator positioned at n = 1
FibonacciIterator FibonacciIterator::begin() const
{
	//set object at beggining
	FibonacciIterator lIterator(fMaxN);
	/* long way of doing above
	FibonacciIterator temp = *this;
	temp.fCurrentN = 0;
	//setting iterator at 1
	++temp;
	//reseting fibonacci sequence 
	temp.fCurrent = 1;
	temp.fPrevious = 0;
	*/
	return lIterator;
}

//return new iterator positioned at maxn+1
FibonacciIterator FibonacciIterator::end() const
{
	FibonacciIterator temp = *this;
	temp.fCurrentN = temp.fMaxN + 1;
	return temp;
}