/*
Name: Wesley Kepke
Date: May 20, 2015
Problem: Write a function to print all permutations of a string. For 
simplicity, assume all characters are unique. 
*/

#include <iostream>
#include <string.h>
using namespace std;

void generatePermutations(char* str, int low, int high);
int calculateNumOfPermutations(char* str);
void swapElements(char* str, int indexOne, int indexTwo);
void printString(const char* str);

int main(void) {
	char* input = new char[100];
	bool loopCondition = true;

	while(loopCondition == true) {
		cout << "Enter a string (type 'exit' to end program): ";
		cin >> input;
		if(strcmp("exit", input) == 0) {
			loopCondition = false;
		}
		cout << "Generating " << calculateNumOfPermutations(input);
		cout << " permutations:" << endl;
		generatePermutations(input, 0, strlen(input) - 1);
	}

	return 0; 
}

void generatePermutations(char* str, int low, int high) {
	if(low == high) {
		printString(str);
	}
	else {
		for(int i = low; i <= high; i++) {
			swapElements(str, low, i);
			generatePermutations(str, low + 1, high);
			swapElements(str, low, i);
		}
	}
}

int calculateNumOfPermutations(char* str) {
	int len = strlen(str);
	int result = 1; 
	while(len > 0) {
		result *= len;
		len--;
	}
	return result; 
}

void swapElements(char* str, int indexOne, int indexTwo) {
	char temp = str[indexOne];
	str[indexOne] = str[indexTwo];
	str[indexTwo] = temp; 
}

void printString(const char* str) {
	for(int i = 0; i < strlen(str); i++) {
		cout << str[i];
	}
	cout << endl; 
}