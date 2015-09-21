/*
Name: Wesley Kepke
Date: May 23, 2015
Problem: Implementation of the rod cutting example from the CLRS algorithms
textbook. 

Given a rod of length n, we want to find the maximum revenue that can be 
obtained by cutting the rod into smaller pieces.

Length|Price
0|0
1|1
2|5
3|8
4|9
5|10
6|17
7|17
8|20
9|24
10|30

This program will contain many implementations:
recursiveTopDown: This is the most naive implementation but runs in O(2^n) time
because each call makes 2 recursive calls.
*/

#include <iostream>
using namespace std;

#define NEG_INFINITY -9999999

// Auxilliary functions
int findMax(int valOne, int valTwo);
void createLengthAndPriceTable(int* dataTable);

// O(2^n) implementation
int recursiveTopDown(int* dataTable, int rodLength);

// Memoized top-down approach: O(n^2)
int memoizedTopDown(int* dataTable, int rodLength);
int memoizedRodCutting(int* dataTable, int rodLength, int* auxTable);

// Bottom-up approach: O(n^2)
int bottomUpRodCutting(int* dataTable, int rodLength);
int bottomUpRodCuttingWithSolution(int* dataTable, int rodLength,
									int*& auxTable, int*& solutionTable);
void printBottomUpSolution(int rodLength, int* solutionTable);

int main(void) {
	int* priceTable = new int[12];
	int* extraTableForBottomUpImplementation = NULL;
	int* solutionTableForBottomUpImplementation = NULL;
	bool loopCondition = true;
	int inputRodLength = 0;

	createLengthAndPriceTable(priceTable);
	while(loopCondition == true) {
		cout << "Enter a rod length (type 0 to exit program): ";
		cin >> inputRodLength;
		
		if(inputRodLength == 0) {
			loopCondition = false;
			continue; 
		}
		else if(inputRodLength > 10 || inputRodLength < 0) {
			cout << "ERROR: Rod length must be between 0 and 10." << endl;
			continue;
		}
		
		cout << "Recursive O(2^n) implementation: ";
		cout << recursiveTopDown(priceTable, inputRodLength) << endl;

		cout << "Memoized O(n^2) top-down implementation: ";
		cout << memoizedTopDown(priceTable, inputRodLength) << endl; 

		cout << "Bottom-up O(n^2) implementation: ";
		cout << bottomUpRodCutting(priceTable, inputRodLength) << endl; 

		cout << "Bottom-up O(n^2) implementation with solution computed: ";
		cout << bottomUpRodCuttingWithSolution(priceTable, inputRodLength,
												extraTableForBottomUpImplementation,
												solutionTableForBottomUpImplementation) << endl; 
		cout << "\t" << "Solution: " << endl;
		printBottomUpSolution(inputRodLength, solutionTableForBottomUpImplementation);
		delete []extraTableForBottomUpImplementation;
		extraTableForBottomUpImplementation = NULL;
		delete []solutionTableForBottomUpImplementation;
		solutionTableForBottomUpImplementation = NULL;
		cout << "============================================================" << endl; 
	}

	delete []priceTable;
	priceTable = NULL;
	delete []extraTableForBottomUpImplementation;
	extraTableForBottomUpImplementation = NULL;
	delete []solutionTableForBottomUpImplementation;
	solutionTableForBottomUpImplementation = NULL;  
	return 0; 
}

int findMax(int valOne, int valTwo) {
	if(valOne > valTwo) {
		return valOne; 
	}

	else return valTwo;
}

void createLengthAndPriceTable(int* dataTable) {
	dataTable[0] = 0;
	dataTable[1] = 1;	
	dataTable[2] = 5;	
	dataTable[3] = 8;	
	dataTable[4] = 9;	
	dataTable[5] = 10;	
	dataTable[6] = 17;	
	dataTable[7] = 17;	
	dataTable[8] = 20;	
	dataTable[9] = 24;	
	dataTable[10] = 30;
	dataTable[11] = '\0';	
}

/*
Assumes rodLength and number of items in dataTable are compatible. 
*/
int recursiveTopDown(int* dataTable, int rodLength) {
	int optimalValue = NEG_INFINITY;

	// No revenue for rod of length 0
	if(rodLength == 0) {
		return 0; 
	}

	else {
		for(int i = 1; i <= rodLength; i++) {
			optimalValue = findMax(optimalValue, 
									(dataTable[i] + 
										recursiveTopDown(dataTable, rodLength - i)));
		}
	}

	return optimalValue;
}

int memoizedTopDown(int* dataTable, int rodLength) {
	int* auxData = new int[rodLength + 1];
	int optimalValue = 0; 

	for(int i = 0; i <= rodLength; i++) {
		auxData[i] = NEG_INFINITY;
	}

	optimalValue = memoizedRodCutting(dataTable, rodLength, auxData);
	delete []auxData;
	auxData = NULL; 
	return optimalValue;

}

/*
This is has O(n^2) running time but may be more difficult to tell. Since a 
recursive call to solve a previously solved problem returns immediately, the
function solves each subproblem just once. It solves subproblems for lengths
1,2,...,rodLength. To solve a subproblem of size rodLength, the for loop 
iterates rodLength amount of times. 

Therefore, the total amount of iterations for this for loop over all recursive
calls forms an arithmetic series, giving a total of O(rodLength^2) iterations.
*/
int memoizedRodCutting(int* dataTable, int rodLength, int* auxTable) {
	int optimalValue = NEG_INFINITY;

	// Check if solution exists
	if(auxTable[rodLength] >= 0) {
		return auxTable[rodLength];
	}

	else if(rodLength == 0) {
		return 0; 
	}

	else {
		for(int i = 1; i <= rodLength; i++) {
				optimalValue = findMax(optimalValue, 
						(dataTable[i] + memoizedRodCutting(dataTable, 
															rodLength - i, 
															auxTable)));
		}
	}

	auxTable[rodLength] = optimalValue;
	return optimalValue;
}

int bottomUpRodCutting(int* dataTable, int rodLength) {
	int optimalValue = 0; 
	int* auxData = new int[rodLength + 1];
	auxData[0] = 0;

	for(int i = 1; i <= rodLength; i++) {
		optimalValue = NEG_INFINITY;
		for(int j = 1; j <= i; j++) {
			optimalValue = findMax(optimalValue, 
									dataTable[j] + auxData[i - j]);
		}

		auxData[i] = optimalValue;
	}

	optimalValue = auxData[rodLength];
	delete []auxData;
	auxData = NULL; 
	return optimalValue;
}

int bottomUpRodCuttingWithSolution(int* dataTable, int rodLength,
									int*& auxTable, int*& solutionTable) {
	int optimalValue = 0;

	if(auxTable != NULL) {
		cout << "ERROR: Parameter 'auxTable' may already contain data." << endl;
		return -1;
	}

	if(solutionTable != NULL) {
		cout << "ERROR: Parameter 'solutionTable' may already contain data." << endl;
		return -1;
	}

	auxTable = new int[rodLength + 1];
	auxTable[0] = 0; 
	solutionTable = new int[rodLength + 1];

	for(int i = 1; i <= rodLength; i++) {
		optimalValue = NEG_INFINITY;
		for(int j = 1; j <= i; j++) {
			if(optimalValue < (dataTable[j] + auxTable[i - j])) {
				optimalValue = (dataTable[j] + auxTable[i - j]);
				solutionTable[i] = j;
			}
		}

		auxTable[i] = optimalValue;
	}

	return auxTable[rodLength];	
}

void printBottomUpSolution(int rodLength, int* solutionTable) {
	int i = 1; 

	while(rodLength > 0) {
		cout << "\t" << "For cut #" << i << ", cut a " << solutionTable[rodLength];
		cout << " size piece." << endl;
		rodLength -= solutionTable[rodLength];
		i++; 
	}
}