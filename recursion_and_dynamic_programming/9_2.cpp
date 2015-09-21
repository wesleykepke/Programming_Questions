/*
Name: Wesley Kepke
Date: May 26, 2015
Problem: Imagine a robot sitting on the upper left corner of an X by Y grid. The
robot can only move in two directions; right and down. How many possible paths
<<<<<<< HEAD
are there for the robot to go from (0,0) to (X,Y)? 
=======
are there for the robot to go from (0,0) to (X,Y). 
>>>>>>> d03045d4ef3530040cd261d71dd893cb59b2525d
*/

#include <iostream>
#include <vector>
using namespace std;

int calculationHelper(int xDimension, int yDimension);
void calculateNumOfPaths(int currentX, int currentY,
							int desiredX, int desiredY, 
							vector<int>& destinationCount);

int main(void) {
	int inputX = 0;
	int inputY = 0;
	bool loopCondition = true; 

	while(loopCondition == true) {
		cout << "Enter value for X dimension (type 0 to end program): ";
		cin >> inputX;
		if(inputX == 0) {
			loopCondition = false;
			continue; 
		}
		cout << "Enter value for Y dimension: ";
		cin >> inputY;
		cout << "There are " << calculationHelper(inputX - 1, inputY - 1); // #todo may change
		cout << " paths from (0,0) to (" << inputX << "," << inputY;
		cout << ")." << endl; 
		cout << "============================================================";
		cout << endl;  
	}

	return 0; 
}

int calculationHelper(int xDimension, int yDimension) {
	vector<int> rightVector;
	vector<int> downVector; 
	calculateNumOfPaths(0, 1, 
						xDimension, yDimension, 
						rightVector);
	calculateNumOfPaths(1, 0, 
						xDimension, yDimension, 
						downVector);
	return rightVector.size() + downVector.size();
}

void calculateNumOfPaths(int currentX, int currentY,
							int desiredX, int desiredY, 
							vector<int>& destinationCount) {
	if(currentX > desiredX) {
		return; 
	}

	else if(currentY > desiredY) {
		return; 
	}

	bool onX = currentX == desiredX;
	bool onY = currentY == desiredY;

	if(onX == true && onY == true) {
		destinationCount.push_back(1);
		return;
	}

	calculateNumOfPaths(currentX + 1, currentY,
						desiredX, desiredY,
						destinationCount);
	calculateNumOfPaths(currentX, currentY + 1,
						desiredX, desiredY,
						destinationCount);
}