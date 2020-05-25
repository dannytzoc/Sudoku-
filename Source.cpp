#include <iostream>
int grid[9][9] = { {6,0,8,0,0,1,2,4,0},
					   {5,0,0,8,0,0,0,0,9},
					   {0,4,0,6,0,0,3,0,5},
					   {0,5,0,4,0,0,7,9,1},
					   {9,0,0,0,0,0,0,0,4},
					   {7,8,4,0,0,3,0,6,0},
					   {8,0,7,0,0,5,0,2,0},
					   {1,0,0,0,0,9,0,0,6},
					   {0,2,9,3,0,0,1,0,8}
}; // this is the 9 by 9 grid in which you could changed up the numbers 
void printgrid(int a[][9]);
void printgrid(int a[][9]) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			std::cout << a[i][j];
		}
		std::cout << '\n';
	}// this iterates and prints out the two dimensional array 
}
bool possible(int y, int x, int n);
bool possible(int y, int x, int n) {
	for (int i = 0; i < 9; i++) {
		if (grid[y][i] == n)
			return false;// print out false if the row or column have the matchign number
	}
	for (int i = 0; i <= 9; i++) {
		if (grid[i][x] == n)
			return false;
	}
	int x1 = (x / 3) * 3;
	int y1 = (y / 3) * 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (grid[y1 + i][x1 + j] == n)
				return false;// checks the 4 by 4 matrix to see if numbers dont match up 
		}
	}
	return true; // prints out true if it finds a number
}
void solve();
void solve() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (grid[i][j] == 0) {// itertes through the sudoku puzzle and checks if theres a zero which signifies a blank 
				for (int k = 1; k < 10; k++) { // checks if its possible to put a number 1-9
					if (possible(i, j, k)) {
						grid[i][j] = k; // if it is possible it puts the 1-9 number in th gird
						solve(); // then is solves it 
						grid[i][j] = 0; // if it was bad choice then you go back and then put back zero 
					}
				}
				return;
			}
		}
	}
	printgrid(grid);// prints the grid once its done 

}

int main() {
	
	
	printgrid(grid);
	std::cout << "\n";
	std::cout << '\n';
	solve();
	return 0;

}