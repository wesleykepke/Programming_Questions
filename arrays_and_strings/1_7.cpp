/*
Name: Wesley Kepke
Date: May 18, 2015
Problem: Write an algorithm such that if an element in an MxN matrix is 0, its
entire row and column are set to 0.
*/

#include <iostream>
#include <fstream>
using namespace std;

void setMatrixElementsToZero(int** matrix, int numRows, int numCols);
void dynamicallyAllocateMatrix(int**& matrix, int numRows, int numCols);
void dynamicallyDeallocateMatrix(int**& matrix, int numRows, int numCols);
void printMatrix(int** matrix, int numRows, int numCols);
void readDataIntoMatrix(char* fileName, int**& matrix, int &numRows, int &numCols);

int main(int argc, char** argv) {
	int** matrix = NULL;
	int matrixRows = 0;
	int matrixCols = 0; 
	readDataIntoMatrix(argv[1], matrix, matrixRows, matrixCols);
	cout << "Original matrix: " << endl; 
	printMatrix(matrix, matrixRows, matrixCols);
	cout << "After rows/cols have been set to 0: " << endl;
	setMatrixElementsToZero(matrix, matrixRows, matrixCols);
	printMatrix(matrix, matrixRows, matrixCols);
	dynamicallyDeallocateMatrix(matrix, matrixRows, matrixCols);
	return 0; 
}

void setMatrixElementsToZero(int** matrix, int numRows, int numCols) {
	bool** zeroLocations = new bool*[numRows];
	for(int i = 0; i < numRows; i++) {
		zeroLocations[i] = new bool[numCols];
	}

	for(int i = 0; i < numRows; i++) {
		for(int j = 0; j < numCols; j++) {
			zeroLocations[i][j] = false;
			if(matrix[i][j] == 0) {
				zeroLocations[i][j] = true; 
			}
		}
	}

	for(int i = 0; i < numRows; i++) {
		for(int j = 0; j < numCols; j++) {
			if(zeroLocations[i][j] == true) {
				for(int k = 0; k < numCols; k++) {
					matrix[i][k] = 0;
				}

				for(int k = 0; k < numRows; k++) {
					matrix[k][j] = 0;
				}
			}
		}
	}

	for(int i = 0; i < numRows; i++) {
		delete []zeroLocations[i];
		zeroLocations[i] = NULL;
	}

	delete []zeroLocations;
	zeroLocations = NULL; 	
}

void dynamicallyAllocateMatrix(int**& matrix, int numRows, int numCols) {
	if(matrix != NULL) {
		cout << "Error: Matrix may already contain data." << endl;
		return;
	}

	matrix = new int*[numRows];
	for(int i = 0; i < numRows; i++) {
		matrix[i] = new int[numCols];
	}
}

void dynamicallyDeallocateMatrix(int**& matrix, int numRows, int numCols) {
	if(matrix == NULL) {
		return;
	}

	for(int i = 0; i < numRows; i++) {
		delete []matrix[i];
		matrix[i] = NULL;
	}

	delete []matrix;
	matrix = NULL;
}

void printMatrix(int** matrix, int numRows, int numCols) {
	for(int i = 0; i < numRows; i++) {
		for(int j = 0; j < numCols; j++) {
			cout << matrix[i][j] << "\t";
		}

		cout << endl; 
	}
}

void readDataIntoMatrix(char* fileName, int**& matrix, int &numRows, int &numCols) {
	fstream file(fileName);
	file >> numRows;
	file >> numCols;

	dynamicallyAllocateMatrix(matrix, numRows, numCols);
	for(int i = 0; i < numRows; i++) {
		for(int j = 0; j < numCols; j++) {
			file >> matrix[i][j];
		}
	}
}