/*
Name: Wesley Kepke
Date: May 16, 2015
Problem: Given an NxN matrix (2d-array), write a function to rotate the
elements by 90 degrees. Can you do this in place?
*/

#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

void allocate2dIntegerMatrix(int**& matrix, int dimensionLength);
void deallocate2dIntegerMatrix(int**& matrix, int dimensionLength);
void print2dIntegerMatrix(int** matrix, int dimensionLength);
bool get2dIntegerDataFromFile(int**& matrix, int& dimensionLength, 
								char* fileName);
void rotateMatrixBy90Degrees(int** matrix, int dimensionLength);

int main(int argc, char** argv) {
	int** matrix = NULL;
	int sideLength = 0;
	bool successfulFileRead = false;
	successfulFileRead = get2dIntegerDataFromFile(matrix, sideLength, argv[1]);
	if(successfulFileRead == true) {
		cout << "Original Matrix:" << endl; 
		print2dIntegerMatrix(matrix, sideLength);
		rotateMatrixBy90Degrees(matrix, sideLength);
		cout << "New Matrix (rotated by 90 degrees):" << endl; 
		print2dIntegerMatrix(matrix, sideLength);
		deallocate2dIntegerMatrix(matrix, sideLength);
	}

	return 0; 
}

void allocate2dIntegerMatrix(int**& matrix, int dimensionLength) {
	matrix = new int*[dimensionLength];
	for(int i = 0; i < dimensionLength; i++) {
		matrix[i] = new int[dimensionLength];
	}
}

void deallocate2dIntegerMatrix(int**& matrix, int dimensionLength) {
	for(int i = 0; i < dimensionLength; i++) {
		delete []matrix[i];
		matrix[i] = NULL; 
	}

	delete []matrix;
	matrix = NULL; 
}

void print2dIntegerMatrix(int** matrix, int dimensionLength) {
	for(int i = 0; i < dimensionLength; i++) {
		for(int j = 0; j < dimensionLength; j++) {
			cout << matrix[i][j] << "\t"; 
		}

		cout << endl; 
	}
}

bool get2dIntegerDataFromFile(int**& matrix, int& dimensionLength, 
								char* fileName) {
	ifstream f(fileName);

	if(matrix != NULL) {
		return false;
	}

	f >> dimensionLength;
	allocate2dIntegerMatrix(matrix, dimensionLength);
	for(int i = 0; i < dimensionLength; i++) {
		for(int j = 0; j < dimensionLength; j++) {
			f >> matrix[i][j];
		}
	}

	return true;
}

void rotateMatrixBy90Degrees(int** matrix, int dimensionLength) {
	int oldX = 0;
	int oldY = 0;
	int newX = 0;
	int newY = 0;
	int oldValue = 0;
	int newValue = 0;
	int rowStoppingCondition = (dimensionLength - 1) / 2;
	int colStoppingCondition = (dimensionLength - 1);

	for(oldX = 0; oldX <= rowStoppingCondition; oldX++) {
		for(oldY = oldX; oldY < colStoppingCondition; oldY++) {
			oldValue = matrix[oldX][oldY];
			for(int i = 0; i < 4; i++) { // Four locations to swap per element
				newX = oldY;
				newY = (dimensionLength - 1) - oldX;
				newValue = matrix[newX][newY];
				matrix[newX][newY] = oldValue;
				oldValue = newValue;
				oldX = newX;
				oldY = newY;
			}
		}
		
		colStoppingCondition--;
	}
}