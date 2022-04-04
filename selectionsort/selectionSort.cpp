#include <iostream>
#include <string>
#include <stdlib.h>

//function prototypes
int fillArray();
void outputSort();
void selectionSort();

//creating array that can extend up to 20 elements, and initializing n
int unsorted[20];
int n = 0;

int main() {
	fillArray();
	outputSort();
	selectionSort();
}

void selectionSort() {
	//loop that runs n - 1 times to organize whole line
	for (int j = 0; j < n - 1; j++)
	{
		int smallest = j;
		for (int i = j + 1; i < n; i++)//loop that runs n times to find smallest integer
		{
			if (unsorted[i] < unsorted[smallest])
			{//if current integer is larger than next integer being checked, set equal to that place in array
				smallest = i;
			}
			
		}
		if (smallest != j)
		{//if smallest number location is not equal to j, swap with number in j position
			int temp = unsorted[smallest];
			unsorted[smallest] = unsorted[j];
			unsorted[j] = temp;
		}//function to output sorted list each loop
		outputSort();
	}
}

void outputSort() {
	for (int k = 0; k < n; k++)
	{//prints out array, runs as many times as user declared n
		std::cout << "|";
		std::cout << unsorted[k];
		std::cout << "|";
	}
	std::cout << "" << std::endl;
}

int fillArray() {
	//ask user for array length
	std::cout << "Enter a NUMBER for an array length Please keep it between 1 and 20." << std::endl;
	if (!(std::cin >> n))//|| n > 20 || n < 1)
	{//if input is not a number, is above 20 or lower than 1, reject input and close program
		std::cout << "Invalid Input." << std::endl;
		return 0;
	}
	else if (n > 20 || n < 1) {
		std::cout << "Invalid Input." << std::endl;
		fillArray();
	}


		
	//otherwise, fill n array elements of random numbers
	for (int fill = 0; fill < n; fill++) {
		unsorted[fill] = rand() % 1000;
	}

}