
// COS30008, Tutorial 7, 2016

#pragma once

template<class DataType>
class DoublyLinkedNode
{
public:
    typedef DoublyLinkedNode<DataType> Node;	// nominal equivalence
    
private:
    DataType fValue;    // stored datum
    Node* fNext;        // forward pointer to next element
    Node* fPrevious;    // backward pointer to previous element
    
    // private default constructor for sentinel
    DoublyLinkedNode()
    {
        fValue = DataType();
        fNext = &NIL;
        fPrevious = &NIL;
    }
    
public:
    static Node NIL;                            // sentinel declaration
    
    DoublyLinkedNode( const DataType& aValue ); // constructor (unlinked node)

    void prepend( Node& aNode );                // aNode becomes right node of this
    void append( Node& aNode );                 // aNode becomes left node of this
    void remove();                              // this node is removed
    
    // getter functions
    const DataType& getValue() const;           // return constant reference to datum
    const Node& getNext() const;                // return constant reference to next node
    const Node& getPrevious() const;            // return constant reference to previous node
};

// sentinel implementation
template<class DataType>
DoublyLinkedNode<DataType> DoublyLinkedNode<DataType>::NIL;

// method implementation
template<class DataType>
DoublyLinkedNode<DataType>::DoublyLinkedNode( const DataType& aValue )
{
	fValue = aValue;
	fPrevious = &NIL;
	fNext = &NIL;
}

template<class DataType>
void DoublyLinkedNode<DataType>::prepend( Node& aNode )
{
    aNode.fNext = this;                     // make this the forward pointer of aNode
    
    if ( fPrevious != &NIL )                // make this's backward pointer aNode's
    {                                       // backward pointer and make previous'
        aNode.fPrevious = fPrevious;        // forward pointer aNode
        fPrevious->fNext = &aNode;
    }
    
    fPrevious = &aNode;                     // this' backward pointer becomes aNode
}

template<class DataType>
void DoublyLinkedNode<DataType>::append( Node& aNode )
{
	aNode.fPrevious = this;
    
	if ( fNext != &NIL )
	{
		aNode.fNext = fNext;
		fNext->fPrevious = &aNode;
	}
    
	fNext = &aNode;
}

template<class DataType>
void DoublyLinkedNode<DataType>::remove()
{
	if ( fPrevious != &NIL )
	{
		fPrevious->fNext = fNext;
	}
    
	if ( fNext != &NIL )
	{
		fNext->fPrevious = fPrevious;
	}
}

template<class DataType>
const DataType& DoublyLinkedNode<DataType>::getValue() const
{
    return fValue;
}

template<class DataType>
const DoublyLinkedNode<DataType>& DoublyLinkedNode<DataType>::getNext() const
{
    return *fNext;
}

template<class DataType>
const DoublyLinkedNode<DataType>& DoublyLinkedNode<DataType>::getPrevious() const
{
    return *fPrevious;
}
