/*
Name: Wesley Kepke
Date: May 14, 2015
Problem: Implement an algorithm to see if a string has all unique characters. 
What if you cannot use additional data structures?
*/

#include <iostream>
#include <string.h>
using namespace std;

bool isStringUnique(char* str); 

int main(void) {
	char* test = new char[300];
	bool loopCondition = true; 

	while(loopCondition == true) {
		bool result = false;
		cout << "Enter a string (type 'exit' to end program): ";
		cin >> test;
		if(strcmp("exit", test) == 0) {
			loopCondition = false;
		}
		result = isStringUnique(test);
		if(result == true) {
			cout << "The string " << test << " has no duplicate letters." << endl;
		}
		else if(result == false) {
			cout << "The string " << test << " has duplicate letters." << endl;
		}
	}	

	delete []test;
	test = NULL;
	return 0; 
}

bool isStringUnique(char* str) {
	bool* temp = new bool[128]; 
	int index = 0; 
	int strLength = strlen(str);
	int asciiVal = 0; 

	if(strlen(str) > 128) {
		return false;
	}

	if(strlen(str) == 0) {
		return false;
	}

	for(index; index < 128; index++) {
		temp[index] = false; 
	}

	for(index = 0; index < strLength; index++) {
		asciiVal = str[index] - '0'; 
		if(temp[asciiVal] == true) {
			return false;
		}
		temp[asciiVal] = true;
	}

	delete []temp;
	temp = NULL; 
	return true; 
}