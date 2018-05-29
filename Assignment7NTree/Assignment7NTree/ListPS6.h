
// COS30008, Problem set 6, 2016

#pragma once

template<class T>
List<T>::List( const List& aOtherList )
{
    // initialize this list
    fTop = &Node::NIL;					// initialize top                           // 2
    fLast = &Node::NIL;					// initialize last                          // 2
    fCount = 0;							// initialize count                         // 1
    
    // copy aOtherList
    for ( Iterator iter = aOtherList.getIterator(); iter != iter.rightEnd(); iter++ )
        push_back( *iter );                                                         // 5/10
}

template<class T>
List<T>& List<T>::operator=( const List& aOtherList )
{
    if ( &aOtherList != this )                                                      // 2
    {
        // delete this list
        while ( fTop != &Node::NIL )
        {
            Node* temp = (Node *)&fTop->getNext();  // get next node (to become top)
            fTop->remove();                         // move first node
            delete fTop;							// free node memory
            fTop = temp;							// make temp the new top
        }                                                                           // 5
        
        // initialize this list
        fTop = &Node::NIL;					// initialize top
        fLast = &Node::NIL;					// initialize last
        fCount = 0;							// initialize count
        
        // copy aOtherList
        for ( Iterator iter = aOtherList.getIterator(); iter != iter.rightEnd(); iter++ )
            push_back( *iter );                                                     // 5
    }
    
    return *this;                                                                   // 1/13
}

// 10+13=23
