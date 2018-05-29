#pragma once
#include "DynamicQueue.h"
template<class T>
class DynamicQueueIterator
{
private:
	DynamicQueue<T> fQueue;
public:
	DynamicQueueIterator(const DynamicQueue<T>& aQueue);
	const T& operator*(); // dereference
	DynamicQueueIterator& operator++(); // prefix increment
	DynamicQueueIterator operator++(int); // postfix increment
	bool operator==(const DynamicQueueIterator& aOtherIter) const;
	bool operator!=(const DynamicQueueIterator& aOtherIter) const;
	DynamicQueueIterator end() const; // new iterator (after last element)
};

template<class T>
DynamicQueueIterator<T>::DynamicQueueIterator(const DynamicQueue<T>& aQueue)
{
	fQueue = aQueue;
}

template<class T>
const T& DynamicQueueIterator<T>::operator*()
{
	return fQueue.top();
}

template<class T>
DynamicQueueIterator<T>& DynamicQueueIterator<T>::operator++()
{
	fQueue.dequeue();
	return *this;
}

template<class T>
DynamicQueueIterator<T> DynamicQueueIterator<T>::operator++(int)
{
	DynamicQueueIterator temp = *this;
	++(*this);
	return temp;
}

template<class T>
bool DynamicQueueIterator<T>::operator==(const DynamicQueueIterator& aOtherIter) const
{
	return fQueue.size() == aOtherIter.fQueue.size();
}

template<class T>
bool DynamicQueueIterator<T>::operator!=(const DynamicQueueIterator& aOtherIter) const
{
	return !(*this == aOtherIter);
}

template<class T>
DynamicQueueIterator<T> DynamicQueueIterator<T>::end() const
{
	DynamicQueueIterator temp = *this;

	//move to end
	while (!temp.fQueue.isEmpty())
		temp.fQueue.dequeue();

	return temp;
}