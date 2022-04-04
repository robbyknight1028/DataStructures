#include "bst.h"
#include <iostream>

int main() {
	//ask user for k value
	int k;
	std::cout << "Enter a whole number from 0 to 14.";
	std::cin >> k;
	//create BST
	BST* tree = new BST;
	//initialize array to fill BST
	int numbers[] = { 6, 17, 20, 41, 45, 52, 57, 65, 71, 76, 79, 87, 92, 95, 99 };
	
	//for loop that places each value in array onto BST
	for (int i = 0; i < 15; i++) {
		tree->Insert(numbers[i]);
	}
	
	//go to printtreeinorder function
	tree->PrintTreeInOrder();

	//commenting out as I could not get to work
	//tree->findKLargest(k);
}
