#include "Node.h"

Node :: Node(){
    data = 0;
    leftChild = NULL;
    rightChild = NULL; 
}
Node :: Node(int _data){
    data = _data; 
    leftChild = NULL;
    rightChild = NULL; 
}
Node :: ~Node(){}

int Node :: getData() const{
    return data; 
}

	/*
	* Returns the left child of this node or null if it doesn't have one.
	*
	* @return the left child of this node or null if it doesn't have one.
	*/
NodeInterface *  Node :: getLeftChild() const{
        return leftChild; 
    }

	/*
	* Returns the right child of this node or null if it doesn't have one.
	*
	* @return the right child of this node or null if it doesn't have one.
	*/
NodeInterface * Node :: getRightChild() const{
        return rightChild; 
    }
