
// COS30008, Problem Set 6, 2016

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
	void enqueue( const T& aElement );
	void dequeue();
    const T& top() const;
};

template<class T>
bool DynamicQueue<T>::isEmpty() const
{
	return fElements.isEmpty();                                         // 2/2
}

template<class T>
int DynamicQueue<T>::size() const
{
	return fElements.size();                                            // 2/2
}

template<class T>
void DynamicQueue<T>::enqueue( const T& aElement )
{
	fElements.push_back( aElement );                                    // 2/2
}

template<class T>
void DynamicQueue<T>::dequeue()
{
    if ( isEmpty() )													// 2
        throw std::underflow_error( "Queue empty." );					// 1
    
    fElements.remove( fElements[0]);                                    // 3/6
}

template<class T>
const T& DynamicQueue<T>::top() const
{
    if ( isEmpty() )													// 2
        throw std::underflow_error( "Queue empty." );					// 1
    
    return fElements[0];												// 2/5
}

// 2+2+2+6+5=17
