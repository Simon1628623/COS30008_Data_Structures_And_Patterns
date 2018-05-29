
#pragma once

#include <stdexcept>

#include "TreeVisitor.h"

template<class T, int N>
class NTree
{
private:
	const T* fKey; //0 for empty NTree
	NTree<T, N>* fNodes[N]; //N subtree of degree N

	NTree(); //sentinel constructor

public:
	static NTree<T, N> NIL; //sentinel

	NTree(const T& aKey); //a simple NTree with key and N subtrees

	bool isEmpty() const; //is tree empty
	const T& key() const; //get key (node value)

	//indexer (allow for result modification by client - no const in result)
	NTree& operator[](unsigned int aIndex) const;

	//tree manipulators (using constant references)
	void attachNTree(unsigned int aIndex, const NTree<T, N>& aNTree);
	const NTree& detachNTree(unsigned int aIndex);

	//depth first traversal
	void traverseDepthFirst(const TreeVisitor<T>& aVisitor) const;
};

template<class T, int N>
//null pointer initilizing fKey with suitable value of type pointer to T
NTree<T, N>::NTree() : fKey((T*)0)
{
	//assigning all subtree fNodes with nil values
	for (int i = 0l i < N; i++)
	{
		fNodes[i] = &NIL;
	}
}

template<class T, int N>
//storing address of the reference aKey in fKey
NTree<T, N>::NTree(const T& aKey) : fKey(&aKey)
{
	//each child node in a non empty NTree leaf node is set to location of NIL
	for (int i = 0; i < N; i++)
	{
		fNodes[i] = &NIL;
	}
}

/*~NTree()
{
for(omt i = 0; i < N; i++)
{
if(fNodes[i] != &NIL)
delete fNodes[i];
}
}

*/


template<class T, int N>
bool NTree<T, N>::isEmpty() const
{
	return this == &NIL;
}

template<class T, int N>
const T& NTree<T, N>::key() const
{
	if (isEmpty())
		throw std::domain_error("Empty NTree!");
	return *fKey;
}

template<class T, int N>
NTree<T, N>& NTree<T, N>::operator[](unsigned int aIndex) const
{
	if (isEmpty())
		throw std::domain_error("Empty NTree!");
	if ((aIndex >= 0) && (aIndex < N))
	{
		return *fNodes[aIndex]; //return reference to subtree prevents accidental manipulations outside the tree structure
	}
	else
		throw std::out_of_range("Illegal subtree index!");
}

template<class T, int N>
void NTree<T, N>::attachNTree(unsigned int aIndex, const NTree<T, N>& aNTree)
{
	if (isEmpty())
		throw std::domain_error("Empty NTree!");
	if ((aIndex >= 0) && (aIndex < N))
	{
		if (fNodes[aIndex] != &NIL)
			throw std::domain_error("Non empty subtree present!");
		fNodes[aIndex] = (NTree<T, N>*)&aNTree;

	}
	else
		throw std::out_of_range("Illegal subtree index!");
}

template<class T, int N>
const NTree<T, N>& NTree<T, N>::detachNTree(unsigned int aIndex)
{
	if (isEmpty())
		throw std::domain_error("Empty NTree!");
	if ((aIndex >= 0) && (aIndex < N))
	{
		const NTree<T, N>& Result = *fNodes[aIndex]; //obtain reference to subtree
		//NTree<T, N>* Result = fNodes[aIndex];
		fNodes[aIndex] = &NIL;
		return Result;
	}
	else
		throw std::out_of_range("Illegal subtree index!");
}

//solution only requires proper handling of preorder and post order tree traversal
//however approach for tree traversal of N-ary trees follows the scheme for binary trees shown in class 
template<class T, int N>
void NTree<T, N>::traverseDepthFirst(const TreeVisitor<T>& aVisitor) const
{
	if (!isEmpty())
	{
		aVisitor.preVisit(key()); //show if preorder
		for (unsigned int i = 0; i < N; i++)
		{
			fNodes[i]->traverseDepthFirst(aVisitor);
		}
		aVisitor.postVisit(key()); //show if postorder
	}
}