#pragma once
#include "List.h"
#include <stdexcept>
template<class T>
class DynamicStack
{
private:
	List<T> fElements;
public:
	bool isEmpty() const;
	int size() const;
	void push(const T& aItem);
	void pop();
	const T& top() const;
};

//is there anything in the stack?
template<class T>
bool DynamicStack<T>::isEmpty() const
{
	//if number of elements is 0
	return fElements.size() == 0;
}

//returns actual stack size
template<class T>
int DynamicStack<T>::size() const
{
	//return size of list;
	return fElements.size();
}

//stores item at the next free slot in the stack
template<class T>
void DynamicStack<T>::push(const T& aItem)
{
	//assigning aItem to top of list
	fElements.push_front(aItem);
}

//shifts stack pointer to previous slot in the stack
template<class T>
void DynamicStack<T>::pop()
{
	if (!isEmpty())
	{
		//remove fTop
		fElements.remove(fElements[0]);
	}
	else
		throw std::underflow_error("Stack Empty");
}

//returns ref to the item in the current slot in the stack
template<class T>
const T& DynamicStack<T>::top() const
{
	if (!isEmpty())
		return fElements[0];
	else
		throw std::underflow_error("Stack empty.");
}