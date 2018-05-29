#pragma once

class FibonacciIterator
{
private:
	long fMaxN; // maximum n
	long fCurrentN; //current n
	long fPrevious; //previous Fibonacci number
	long fCurrent; //current Fibonacci number

public:
	//Default Constructor to set up Fibonacci sequence
	FibonacciIterator(long aMaxN);

	//iterator methods

	const long& operator*() const; //return current Fibonacci number
	FibonacciIterator& operator++(); //prefix, next Fibonacci number
	FibonacciIterator operator++(int); //postfix
	bool operator==(const FibonacciIterator& aOther) const;
	bool operator!=(const FibonacciIterator& aOther) const;

	//auxiliaries
	FibonacciIterator begin() const; // return new iterator positioned at n = 1
	FibonacciIterator end() const; //return new iterator positioned at maxn+1
};