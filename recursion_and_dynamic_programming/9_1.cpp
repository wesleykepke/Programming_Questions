/*
Name: Wesley Kepke
Date: May 26, 2015
Problem: A child is running up a staircase with n steps, and can hop either 1 
step, 2 steps, or 3 steps at a time. Implement a method to count how many 
possible ways the child can run up the stairs. 
*/

#include <iostream>
using namespace std;

int stairCount(int numberOfSteps);

int main(void) {
	int inputNumSteps = 0;
	bool loopCondition = true;

	while(loopCondition == true) {
		cout << "Enter number of steps (enter 0 to end program): ";
		cin >> inputNumSteps;
		if(inputNumSteps == 0) {
			loopCondition = false;
			continue; 
		}

		cout << "Possible ways of climbing " << inputNumSteps << " steps: ";
		cout << stairCount(inputNumSteps) << endl;
		cout << "=============================================================";
		cout << endl; 
	}

	return 0; 
}

int stairCount(int numberOfSteps) {
	int possibleOptions = 0; 

	if(numberOfSteps <= 0) {
		return 0; 
	}

	else if(numberOfSteps == 1) {
		return 1;
	}

	else if(numberOfSteps == 2) {
		return 2;
	}

	else if(numberOfSteps == 3) {
		return 4; 
	} 

	else {
		possibleOptions = stairCount(numberOfSteps - 1) +
							stairCount(numberOfSteps - 2) +
							stairCount(numberOfSteps - 3);
	}

	return possibleOptions;
}