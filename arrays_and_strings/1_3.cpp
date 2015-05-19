/*
Name: Wesley Kepke
Date: May 14, 2015
Problem: Given two strings, write a method to decide if one is a permutation of
the other.
*/

#include <iostream>
#include <string.h>
using namespace std;

/*
Returns true if "second" is a permutation of "first" and false otherwise.
NOTE: This function considers permutation with repititions. 
For example, "ccc" is a permutation of "cat."
*/
bool isPermutation(char* first, char* second);

int main(void) {
	char *one = new char[300];
	char *two = new char[300];
	bool loopCondition = true;
	bool result = true; 

	while(loopCondition == true) {
		cout << "Enter first string (type 'exit' to end program): ";
		cin >> one;
		cout << "Enter second string: ";
		cin >> two;
		result = isPermutation(one, two);
		if(result == true) {
			cout << two << " is a permutation of " << one << "." << endl; 
		}
		else {
			cout << two << " is NOT a permutation of " << one << "." << endl;
		}
		if(strcmp("exit", one) == 0) {
			loopCondition = false;
		}
	}

	delete []one;
	one = NULL;
	delete []two;
	two = NULL; 
	return 0; 
}

bool isPermutation(char* first, char* second) {
	int *letterCountArr = new int[128];
	int index = 0; 

	if(strlen(first) != strlen(second)) {
		return false; 
	}

	for(index = 0; index < 128; index++) {
		letterCountArr[index] = 0; 
	}

	for(index = 0; index < strlen(first); index++) {
		letterCountArr[first[index] - '0'] = strlen(first); 
	}

	for(index = 0; index < strlen(first); index++) {
		if(letterCountArr[second[index] - '0'] == 0) {
			return false;
		}
		letterCountArr[second[index] - '0']--; 
	}

	delete []letterCountArr;
	letterCountArr = NULL; 
	return true; 
}