#include <iostream>
#include <stack>


//function initializers
bool solutionCheck();
void printBoard();
int offBoard();

//initializing memory for board, creating row, col, n, and filled variables
int board[10][10];
int row = 0, col = 0, n = 0;
int filled = 1;

//x coordinate stack and y coordinate stack
std::stack<int> xCoord;
std::stack<int> yCoord;


int main() {
	//while loop to make sure user enters number within my parameters
	bool isValid = false;
	while(!isValid){
		
		std::cout << "Enter a whole number for n, less than 10 and greater than 3" <<std::endl;
		std::cin >> n;
		if (n < 4 || n > 10) {
			
			isValid = false;
		}
		else {
			isValid = true;
		}
	}
	board[n][n];//create board of n x n size

	//set each position to 0
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			board[i][j] = 0;
		}
	}

	//place first queen, push location on to x and y stacks
	board[row][col] = 1;
	xCoord.push(row);
	yCoord.push(col);
	//prepare next queen and push trial position
	col++;
	xCoord.push(row);
	yCoord.push(col);
	
	//while loop that runs until each queen has been placed
	while (filled < n) {
		//if queen has left the board, go to offBoard function
		if (row > n-1) {
			offBoard();
		}
		//if spot works, place a queen, reset row, add 1 to col, update stack
		if (solutionCheck()) {
		
			filled++;
			board[row][col] = 1;
			
			row = 0;
			col += 1;
			xCoord.push(row);
			yCoord.push(col);
			
		}
		//else go to next row and update stack
		else {
			xCoord.pop();
			row++;
			xCoord.push(row);
			
			
		}
		
		
	}

	printBoard();
	

}

bool solutionCheck() {
	//check each position below current in the same column
	for (int check = col-1; check >= 0; check--) {
		if (board[row][check] == 1) {
			return false;
		}
	}
	//check each position diagonally to the left and down
	for (int Xcheck = row - 1, Ycheck = col -1; Xcheck >= 0 && Ycheck >=0; Xcheck--, Ycheck--) {
		if (board[Xcheck][Ycheck] == 1) {
			return false;
		}
	}
	//check each position diagonally to the right and down
	for (int Xcheck2 = row + 1, Ycheck2 = col - 1; Xcheck2 < 8 && Ycheck2 >= 0; Xcheck2++, Ycheck2--) {
		if (board[Xcheck2][Ycheck2] == 1) {
			return false;
		}
	}
	
	return true;

}

void printBoard() {
	//prints out solution
	for (int i = n-1; i >=0; i--) {
		for (int j = 0; j < n; j++) {
			std::cout << board[i][j];
		}
		std::cout << std::endl;
	}
		

}

int offBoard() {
	//if off board, pop current x,y from stacks and set last x,y as current
	xCoord.pop();
	yCoord.pop();
	//if stack has emptied, it means there is no solution
	if (xCoord.size() == 0) {
		filled = 10;
		std::cout << "No Solution" << std::endl;
		return 0;
	}
	row = xCoord.top();
	col = yCoord.top();
	//reset queen position to 0, add 1 to row, and update x coord stack
	board[row][col] = 0;
	row++;
	xCoord.pop();
	xCoord.push(row);
	filled--;

	//check if new position is off board before continuing
	if (row > n-1) {
		offBoard();
	}
}









