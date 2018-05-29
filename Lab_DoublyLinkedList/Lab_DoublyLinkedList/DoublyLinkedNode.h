//parameterized abstraction over a class
//implementation done in the header file
//to instantiate a class template we supply the desired types, as the actual template parameters, so that the compiler can synthesize a specialized class for the template
template<class DataType>
class DoublyLinkedNode
{
public:
	typedef DoublyLinkedNode<DataType> Node; //nominal equivalence

private:
	DataType fValue; //stored datum
	//connecting adjacent list elements.
	Node* fNext; //forward pointer to next element in the list
	Node* fPrevious; //backwards pointer to previous element

	//default constructor for sentinel (NIL)
	DoublyLinkedNode()
	{
		fValue = DataType();
		fNext = &NIL;
		fPrevious = &NIL;
	}

public:
	//sentinel node used to replace a null pointer with a special token denoting no value or nil
	//behave like null pointers but sentinels denote proper empty values
	static Node NIL; //sentinel declaration

	DoublyLinkedNode(const DataType& aValue) //constructor (unlinked node)
	{
		fValue = aValue;
		fPrevious = &NIL;
		fNext = &NIL;
	}

	//mechanisms to manipulate objects of class DoublyLinkedNode.
	//adds the arguement aNode object into the list by making aNode the new fPrevious node of this
	void prepend(Node& aNode) //aNode becomes left node of this
	{
		aNode.fNext = this; //make this forwad pointer of aNode

		if (fPrevious != &NIL)
		{
			//make this's backward pointer aNode's backward pointer and make previous' forward pointer aNode
			aNode.fPrevious = fPrevious;
			fPrevious->fNext = &aNode;
		}
		fPrevious = &aNode; //backwards pointer becomes aNode
	}
	//injects the argument aNode object into the list by making aNode the new fNext node of this
	void append(Node& aNode) //aNode becomes right node of this
	{
		//aNodes previous 
		aNode.fPrevious = this;
		
		if (fNext != &NIL)
		{
			//aNodes next
			aNode.fNext = fNext;
			
			//next objects previous
			fNext->fPrevious = &aNode;
		}
		
		//this next object
		fNext = &aNode;
	}

	//removes this from the list but has to properly link the remaining list nodes adjacent to this
	void remove() //this node is removed
	{
		if (fPrevious != &NIL)
		{
			fPrevious->fNext = fNext;
		}
		
		if (fNext != &NIL)
		{
			fNext->fPrevious = fPrevious;
		}
	}

	//read only getters for corresponding fields of DoublyLinkedNode object
	const DataType& getValue() const //return constant reference to datum
	{
		return fValue;
	}
	const Node& getNext() const //return constant reference to next node
	{
		return *fNext;
	}
	const Node& getPrevious() const //return constant reference to previous node
	{
		return *fPrevious;
	}
};

//sentinel implementation
template<class DataType>
DoublyLinkedNode<DataType> DoublyLinkedNode<DataType>::NIL;