/*
Name: Wesley Kepke
Date: May 22, 2015
Problem: Not really a problem. Just exploring the comming implementation for a
recursive fibonacci calculation and then using dynamic programming to improve
the complexity.
*/

#include <iostream>
#include <map>
using namespace std;

int fib(int nthTerm);
int dynamicProgrammingFibHelper(int nthTerm);
int dynamicProgrammingFib(int nthTerm, map<int,int>& auxiliaryTable);

int main(void) {
	bool loopCondition = true;
	int fibTerm = 1; 
	while(loopCondition == true) {
		cout << "Enter a term in the fibonacci sequence (type 0 to end program): ";
		cin >> fibTerm;
		if(fibTerm < 0) {
			cout << "Invalid digit." << endl;
			continue;
		}
		if(fibTerm == 0) {
			loopCondition = false;
			continue;
		}
		cout << "Using the recursive O(2^n) implementation: " << fib(fibTerm) << endl;
		cout << "Using the recursive and dynamic programming O(n) implementation: ";
		cout << dynamicProgrammingFibHelper(fibTerm) << endl;
		cout << "==========================================================================" << endl;  
	}

	return 0; 
}

int fib(int nthTerm){
	if(nthTerm == 0 ) {
		return 0;
	}
	else if(nthTerm == 1) {
		return 1;
	}
	
	else return (fib(nthTerm - 1) + fib(nthTerm - 2));
}

int dynamicProgrammingFibHelper(int nthTerm) {
	map<int,int> fibValues;
	fibValues[0] = 0;
	fibValues[1] = 1;
	return dynamicProgrammingFib(nthTerm, fibValues); 
}

int dynamicProgrammingFib(int nthTerm, map<int,int>& auxiliaryTable) {
	map<int,int>::iterator it = auxiliaryTable.find(nthTerm);
	int tempFibValue = 0; 

	// cached values will return immediately - no further computation is needed
	if(it != auxiliaryTable.end()) {
		return it->second;
	}

	tempFibValue = dynamicProgrammingFib(nthTerm - 1, auxiliaryTable) +
					dynamicProgrammingFib(nthTerm - 2, auxiliaryTable);

	auxiliaryTable[nthTerm] = tempFibValue;
	return tempFibValue;
}