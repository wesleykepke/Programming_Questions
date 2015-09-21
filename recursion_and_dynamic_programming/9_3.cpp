/*
Name: Wesley Kepke
Date: May 27, 2015
Problem: A magic index in an array A[0,...,n-1] is defined to be an index such 
that A[i] = i. Given a sorted array of distinct integers, write a method to 
find a magic index, if one exists, in array A.
*/

#include <iostream>
using namespace std;

#define STOP_CONDITION -9999

int* getIntegerDataFromUser();
void printData(int* data);
int findMagicIndex(int* data, int currentIndex);

int main(void) {
	int* inputData = NULL; 
	int magicIndexLocation = 0; 
	bool loopCondition = true;
	char continueDecision; 

	while(loopCondition == true) {
		inputData = getIntegerDataFromUser();
		magicIndexLocation = findMagicIndex(inputData, 0);
		cout << "Displaying array:" << endl;
		printData(inputData);
		if(magicIndexLocation == -1) {
			cout << "No magic index exists." << endl; 
		}
		else {
			cout << "Magic index exists at location: " << magicIndexLocation;
			cout << endl; 
		}

		cout << "Would you like to enter data into another array (y/n)? ";
		cin >> continueDecision; 
		bool decidedYes = (continueDecision == 'y') || (continueDecision == 'Y');
		bool decidedNo = (continueDecision == 'n') || (continueDecision == 'N');
		if(decidedYes) {
			cout << endl; 
			delete []inputData;
			inputData = NULL; 
		}
		else if(decidedNo) {
			loopCondition = false;
			continue; 
		}
	}

	delete []inputData;
	inputData = NULL; 
	return 0; 
}

int* getIntegerDataFromUser() {
	int userInputSize = 0; 
	int* userInputArray = NULL; 
	int counter = 0;
	bool inputLoopCondition = true;  
	bool validUserInput = true; 

	cout << "Enter an array size (integer) in the range of 1-10: ";
	cin >> userInputSize; 
	validUserInput = (userInputSize < 1) || (userInputSize > 10);
	while((validUserInput == false) || (cin.fail())) {
		cin.clear();
		cin.ignore();
		cout << "Error: Incompatible size." << endl; 
		cout << "Enter an array size (integer) in the range of 1-10: ";
		cin >> userInputSize; 		
	}

	userInputArray = new int[userInputSize + 1];
	for(counter; counter < userInputSize; counter++) {
		inputLoopCondition = true; 
		while(inputLoopCondition == true) {
			cout << "Enter value for Array[" << counter << "]: ";
			cin >> userInputArray[counter];

			if(cin.fail()) {
				cout << "Error: Not an integer." << endl;
				cin.clear();
				cin.ignore();
			}

			else {
				inputLoopCondition = false; 
			}
		}
	}

	userInputArray[userInputSize] = STOP_CONDITION;
	return userInputArray;
}

void printData(int* data) {
	int index = 0;
	while(data[index] != STOP_CONDITION) {
		cout << "Array[" << index << "] = " << data[index];
		cout << endl;
		index++;
	}
}

int findMagicIndex(int* data, int currentIndex) {
	int magicIndexLocation = 0; 

	if(data[currentIndex] == STOP_CONDITION) {
		magicIndexLocation = -1; 
	}

	else if(data[currentIndex] == currentIndex) {
		magicIndexLocation = currentIndex; 
	}

	else {
		magicIndexLocation = findMagicIndex(data, currentIndex + 1); 
	}

	return magicIndexLocation; 
}