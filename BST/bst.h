#pragma once

//class that holds the nods and the key
class BSTnode {
public:
	int key;
	BSTnode* left;
	BSTnode* right;
	BSTnode* parent;
};

//class that hold the functions of the BST
class BST {
public:
	BST();
	//only need insert and print function for this program
	void Insert(int key);
	void PrintTreeInOrder();
	
	//Commenting these out as I could not get it to work
	//void kLargestCheck(int k);
	//void findKLargest(int k);

	//letting program know what functions will be used
protected:
	BSTnode* Insert(BSTnode* node, int key);
	void PrintTreeInOrder(BSTnode* node);

	//creating root variable to be used for insert function
private:
	BSTnode* root;
};