/*
Given a matrix (2x2 array), write a method to rotate the matrix by 90 degrees.
Can you do this in place?

Date: January 19, 2015
*/

#include <iostream>
using namespace std;

void rotateBy90(int** arr, int numRows, int numCols);

int main(void) {
	int a = 0; 
	int** test = new int*[4];
	for (int i = 0; i < 4; i++) {
		test[i] = new int[4]; 
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			test[i][j] = a;
			a++;  
		}
	}

	cout << "Original Matrix: " << endl; 
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << test[i][j] << "\t"; 
		}
		cout << endl; 
	}

	cout << endl; 
	rotateBy90(test, 4, 4); 
	cout << endl; 

	cout << "New Matrix (Rotated by 90): " << endl; 
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << test[i][j] << "\t"; 
		}
		cout << endl; 
	}

	for (int i = 0; i < 4; i++) {
		delete []test[i]; 
		test[i] = NULL; 
	}
	delete []test;
	test = NULL; 
	return 0; 
}

void rotateBy90(int** arr, int numRows, int numCols) {
	int oldRow = 0;
	int newRow = 0;
	int oldCol = 0;
	int newCol = 0;
	int stoppingColumn = (numRows - 2); 
	int temp1;
	int temp2; 

	if (arr == NULL) {
		return; 
	}

	if (numRows != numCols) {
		cout << endl << "ERROR: Row and column size must be equal." << endl; 
		return; 
	}

	if (numRows == 1 && numCols == 1) {
		return; 
	}

	for (int i = 0; i < (numRows / 2); i++) {
		for (int j = 0; j <= stoppingColumn; j++) {
			if (i != 0) {
				j = i; 
			}
			oldRow = i; 
			oldCol = j;
			temp2 = arr[oldRow][oldCol];  

			for (int k = 0; k < 4; k++) {
				newRow = oldCol; 
				newCol = (numRows - 1) - oldRow;
				if (k != 0) {
					temp2 = temp1; 
				} 
				temp1 = arr[newRow][newCol];
				arr[newRow][newCol] = temp2; 
				oldRow = newRow;
				oldCol = newCol; 
			}
		}

		stoppingColumn--; 
	}
}