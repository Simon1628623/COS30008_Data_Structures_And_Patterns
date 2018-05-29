
// COS30008, Problem set 7, 2016

#pragma once

#include <stdexcept>

#include "TreeVisitor.h"

template<class T, int N>
class NTree
{
private:
	const T* fKey;              // 0 for empty NTree
	NTree<T,N>* fNodes[N];      // N subtress of degree N

	NTree();                    // sentinel constructor

public:
	static NTree<T,N> NIL;      // sentinel

	NTree( const T& aKey );     // a simple NTree with key and N subtrees of degree N
    
	bool isEmpty() const;       // is tree empty
	const T& key() const;       // get key (node value)

    // indexer (allow for result modification by client - no const in result)
	NTree& operator[]( unsigned int aIndex ) const;

    // tree manipulators (using constant references)
	void attachNTree( unsigned int aIndex, const NTree<T,N>& aNTree );
	const NTree& detachNTree( unsigned int aIndex );
    
    // depth-first traversal
    void traverseDepthFirst( const TreeVisitor<T>& aVisitor ) const;

    // copy control
    NTree( const NTree& aOtherNTree );
    ~NTree();
    NTree& operator=( const NTree& aOtherNTree );
    
    // breadth-first traversal
    void traverseBreadthFirst( const TreeVisitor<T>& aVisitor ) const;
};


// implementation

template<class T, int N>
NTree<T,N> NTree<T,N>::NIL;


// sentinel constructor
template<class T, int N>
NTree<T,N>::NTree()
{
	fKey = (T*)0;															
	for ( int i = 0; i < N; i++ )											
		fNodes[i] = &NIL;													
}

// node constructor
template<class T, int N>
NTree<T,N>::NTree( const T& aKey )
{
	fKey = &aKey;															
	for ( int i = 0; i < N; i++ )											
		fNodes[i] = &NIL;													
}

// isEmpty
template<class T, int N>
bool NTree<T,N>::isEmpty() const
{
	return this == &NIL;													
}

// key
template<class T, int N>
const T& NTree<T,N>::key() const
{
	if ( !isEmpty() )														
		return *fKey;														
	else
		throw std::domain_error( "Empty NTree." );							
}

// indexer
template<class T, int N>
NTree<T,N>& NTree<T,N>::operator[]( unsigned int aIndex ) const
{
	if ( isEmpty() )														
		throw std::domain_error( "Empty NTree!" );							

	if ( aIndex < N )														
	{
		return *fNodes[aIndex];		// return reference to subtree			
	}
	else
		throw std::out_of_range( "Illegal subtree index!" );				
}

// tree manipulators
template<class T, int N>
void NTree<T,N>::attachNTree( unsigned int aIndex, const NTree<T,N>& aNTree )
{
	if ( isEmpty() )														
		throw std::domain_error( "Empty NTree!" );							

	if ( aIndex < N )														
	{
		if ( fNodes[aIndex] != &NIL )										
			throw std::domain_error( "Non-empty subtree present!" );		

		fNodes[aIndex] = (NTree<T,N>*)&aNTree;
	}
	else
		throw std::out_of_range( "Illegal subtree index!" );				
}

template<class T, int N>
const NTree<T,N>& NTree<T,N>::detachNTree( unsigned int aIndex )
{
	if ( isEmpty() )														
		throw std::domain_error( "Empty NTree!" );							

	if ( (aIndex < N) && fNodes[aIndex] != &NIL )							
	{
		const NTree<T,N>& Result = *fNodes[aIndex]; // obtain reference to subtree
		fNodes[aIndex] = &NIL;						// set to NIL
		return Result;                              // return subtree (reference)
	}
	else
		throw std::out_of_range( "Illegal subtree index!" );				
}


template<class T, int N>
void NTree<T,N>::traverseDepthFirst( const TreeVisitor<T>& aVisitor ) const
{
    // visit every subtree (no invisit)
	if ( !isEmpty() )
	{
		aVisitor.preVisit( key() );
		for ( unsigned int i = 0; i < N; i++ )
		{
            fNodes[i]->traverseDepthFirst( aVisitor );
		}
		aVisitor.postVisit( key() );
	}
}


#include "NTreePS7.h"
