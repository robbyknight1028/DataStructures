#include "bst.h"
#include <iostream>
//constructor
BST::BST(){}

//Insert function that checks if the bst has been created,
//if so, decides whether to send the new value to the left
//or to the right
BSTnode* BST::Insert(BSTnode* node, int key) {
	//if bst is doesn't exit, create it, or if the current
	//node has no children
	if (node == NULL) {
		node = new BSTnode;
		node->key = key;
		node->left = NULL;
		node->right = NULL;
		node->parent = NULL;
	}
	//if root is less than current key, place right
	else if (node->key < key) {
		node->right = Insert(node->right, key);
		node->right->parent = node;
	}
	//else place it to the left
	else {
		node->left = Insert(node->left, key);
		node->left->parent = node;
	}
	//return the node to be used later
	return node;
}

void BST::Insert(int key) {
	root = Insert(root, key);
}

void BST::PrintTreeInOrder(BSTnode* node) {
	if (node == NULL) {
		return;
	}
	//print farthest left value(smallest value)
	PrintTreeInOrder(node->left);

	std::cout << node->key << " ";

	//print farthest right value(largest value)
	PrintTreeInOrder(node->right);
}

void BST::PrintTreeInOrder() {
	//print all value starting from left to right
	PrintTreeInOrder(root);
}
/*
void findKLargest(BSTnode* root, int k, int check){
	
	if (root == NULL || k <= check) {
		return;
	}

	findKLargest(root->right, k, check);

	check++;

	if (check == k) {
		std::cout << "The" << k << "th largest element is " << root->key;
		return;
	}

	findKLargest(root->left, k, check);

}

void kLargestCheck(BSTnode* root, int k) {
	int check = 0;
	findKLargest(root, k, check);
}*/
 