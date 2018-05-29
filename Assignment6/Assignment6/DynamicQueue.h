#pragma once
#include "List.h"
#include <stdexcept>
template<class T>
class DynamicQueue
{
private:
	List<T> fElements;
public:
	bool isEmpty() const;
	int size() const;
	void enqueue(const T& aElement);
	void dequeue();
	const T& top() const;
};

//check if queue is empty
template<class T>
bool DynamicQueue<T>::isEmpty() const
{
	return fElements.size() == 0;
}
//check size of queue
template<class T>
int DynamicQueue<T>::size() const
{
	return fElements.size();
}
//add item to queue
template<class T>
void DynamicQueue<T>::enqueue(const T& aElement)
{
	//assigning aItem to top of list
	fElements.push_front(aElement);
}
//remove item from queue
template<class T>
void DynamicQueue<T>::dequeue()
{
	if (fElements.isEmpty())
		throw std::underflow_error("Queue empty.");

	//access data at "end"/last just before leaving queue
	//increment front pointer to point next available data element
	fElements.remove(top());
}

//front??
template<class T>
const T& DynamicQueue<T>::top() const
{
	if (!isEmpty())
		return fElements[fElements.size()-1];
	else
		throw std::underflow_error("Queue empty.");
}