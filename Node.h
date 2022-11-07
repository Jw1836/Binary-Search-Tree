

#pragma once
#include "NodeInterface.h"
#include <iostream>

class Node : public NodeInterface {
friend class BST;

public:
	Node();
	Node(int data);
	~Node();

	/*
	* Returns the data that is stored in this node
	*
	* @return the data that is stored in this node.
	*/
	int getData() const;

	/*
	* Returns the left child of this node or null if it doesn't have one.
	*
	* @return the left child of this node or null if it doesn't have one.
	*/
	NodeInterface * getLeftChild() const;

	/*
	* Returns the right child of this node or null if it doesn't have one.
	*
	* @return the right child of this node or null if it doesn't have one.
	*/
	NodeInterface * getRightChild() const;

	Node *leftChild; 
	Node *rightChild; 
	int data; 

};