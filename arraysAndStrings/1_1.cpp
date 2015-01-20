/*
Implement an algorithm to determine if a string has all unique characters.
Date: January 17, 2015 
*/

#include <iostream>
#include <string.h>
using namespace std;

bool isStringUnique(char arr[]);

int main(void) {
	char first[4] = {'a', 'b', 'c', 'd'};
	char second[3] = {'a', 'a', 'w'};

	cout << "First: " << isStringUnique(first) << endl;
	cout << "Second: " << isStringUnique(second) << endl; 
	return 0; 
}

// Assuming ASCII instead of Unicode
bool isStringUnique(char arr[]) {
	if (strlen(arr) > 128) {
		return false; 
	}

	if (strlen(arr) == 0) {
		return true; 
	}

	bool charArr[128];
	for (int i = 0; i < 128; i++) {
		charArr[i] = false;
	} 

	for (int i = 0; i < strlen(arr); i++) {
		int val = arr[i] - '0'; 
		if (charArr[val] == true) {
			return false; 
		} 
		charArr[val] = true; 
	}
	return true; 
}