#include "BST.h"

	BST :: BST() {
		root = NULL;
	}
	BST :: ~BST() {}

	NodeInterface * BST :: getRootNode() const {
		return root; 

    }

	/* // j%0ytt&7
	* Attempts to add the given int to the BST tree
	*
	* @return true if added
	* @return false if unsuccessful (i.e. the int is already in tree)
*/
	
	
	bool BST :: add(int data){
		//cout << "add" << endl; 
		return addHelper(data, root); 
		
	


    }
	bool BST :: addHelper(int data, Node *&ref){
		if(ref == NULL){
			ref = new Node(data); // then we are done 
			return true; 
		}
		if(data == ref->data){
			return false; 
		}
		if(data < ref->data){
			return addHelper(data, ref->leftChild);
		}
		if(data > ref->data){
			return addHelper(data, ref->rightChild);
		}
		return false; 

	}

	/*
	* Attempts to remove the given int from the BST tree
	*
	* @return true if successfully removed
	* @return false if remove is unsuccessful(i.e. the int is not in the tree)
	*/

	bool BST :: remove(int data){

		cout << "remove" << endl; 
		return removeHelper(data, root);
		

    }
	Node* BST :: GetInorder(Node*& ref){
		Node* ptr = ref->leftChild; 
		while(ptr->rightChild != NULL){
			ptr = ptr->rightChild;
		}
		return ptr; 
	}
	bool BST :: removeHelper(int data, Node *&ref){
		if(ref == NULL){
			return false; // nothing to remove

		}
		if(data < ref->data){
			return removeHelper(data, ref->leftChild);
		}
		if(data > ref->data){
			return removeHelper(data, ref->rightChild);
		}
		if(data == ref->data){
			if((ref->leftChild != NULL) && (ref->rightChild != NULL)){
				// we have children that we need to connect
				  // how to find the inorder predacessor
				Node* ptr = GetInorder(ref);
				ref->data = ptr->data; 
				cout <<"This is the data from left child function" <<ptr->data << endl;
				return removeHelper(ptr->data, ref->leftChild); // if the in order predecessor has a left node, we call remove
			}
			else if(ref->leftChild != NULL){
				// we have 1 child that is a left child
				Node* temp = ref;  
				ref = ref->leftChild;
				delete temp; 
				temp = NULL;
				return true; 

			}
			else if(ref->rightChild != NULL){
				// we have 1 child that is a right child
				Node* temp = ref;
				ref = ref->rightChild;
				cout <<"This is the data from right child function" <<ref->data << endl;
				delete temp;
				temp = NULL;
				return true; 

			}
			else{
				// no children so we can safely delete this leaf node
				cout << "leaf node" << ref->data << endl; 
				delete ref; 
				ref = NULL; 
				return true; 
			}

		}
		return true; 
	}




	/*
	* Removes all nodes from the tree, resulting in an empty tree.
	*/
	void BST :: clearHelper(Node* ptr){
		if(ptr != NULL){
			clearHelper(ptr->leftChild);
			clearHelper(ptr->rightChild);
		}
		delete ptr; 
		ptr = NULL; 
	}
	void BST :: clear(){
		//cout << "clearing" << endl;
		clearHelper(root); 
		root = NULL;

    }