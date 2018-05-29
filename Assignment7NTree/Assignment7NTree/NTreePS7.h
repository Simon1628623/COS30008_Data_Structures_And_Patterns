#pragma once 

#include <stdexcept>

#include "NTree.h"
#include "DynamicQueue.h"

template<class T, int N>
// copy control
NTree<T, N>::NTree(const NTree& aOtherTree)
{
	//emptying vars
	for (int i = 0; i < N; i++)
	{
		if (fNodes[i] != &NIL)
			fNodes[i] = &NIL;
	}
	fKey = 0;

	//assigning new values
	//attachNTree(aOtherNTree);
	fKey = &aOtherTree.key();
	
	for (int i = 0; i < N; i++)
	{
		fNodes[i] = &aOtherTree[i];
	}
}

template<class T, int N>
NTree<T, N>::~NTree()
{
	for (int i = 0; i < N; i++)
	{
		if (fNodes[i] != &NIL)
			delete fNodes[i];
	}
	delete fKey;
}

template<class T, int N>
NTree<T, N>& NTree<T, N>::operator=(const NTree& aOtherNTree)
{
	if (&aOtherNTree != this)
	{
		//deleting and pretty much using destructor
		for (int i = 0; i < N; i++)
		{
			if (fNodes[i] != &NIL)
				delete fNodes[i];
		}

		//assigning new values
		//attachNTree(aOtherNTree);
		fKey = &aOtherTree.key();
		for (int i = 0; i < N; i++)
		{
			fNodes[i] = &aOtherTree[i];
		}
	}
}

// breadth-first traversal
template<class T, int N>
void NTree<T, N>::traverseBreadthFirst(const TreeVisitor<T>& aVisitor) const
{
	//need a local queue 
	//to avoid unwanted copying, use a pointer to const NTree<T, N> as type for the Dynamic Queue value
	DynamicQueue<const NTree<T,N>*> lQueue; //using pointer to avoid copying

	if (!isEmpty())
		lQueue.enqueue(this); //start with root node

	while (!lQueue.isEmpty())
	{
		const NTree<T,N>& head = *lQueue.top(); //use dereferencing and aliasing
		lQueue.dequeue();
		
		//breadth first traversal for ntree
		aVisitor.preVisit(key());
		for (int i = 0; i < N; i++)
		{
			fNodes[i]->traverseBreadthFirst(aVisitor);
			aVisitor.inVisit(key());
		}
		aVisitor.postVisit(key());
	}
}
