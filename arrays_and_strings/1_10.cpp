/*
Name: Wesley Kepke
Date: May 20, 2015
Problem: Write a recursive function that prints a string backwards. 
*/

#include <iostream>
#include <string.h>
using namespace std;

void recursiveReverse(char* str, int len);

int main(void) {
	bool loopCondition = true;
	char* input = new char[100];
	int inputLen = 0; 

	while(loopCondition == true) {
		cout << "Enter a string to reverse (type 'exit' to end the program): ";
		cin >> input;
		if(strcmp("exit", input) == 0) {
			loopCondition = false;
		}
		inputLen = strlen(input) - 1;
		cout << "Output: "; 
		recursiveReverse(input, inputLen);
		cout << endl;  
	}

	delete []input;
	input = NULL; 
	return 0; 
}

void recursiveReverse(char* str, int len) {
	if(len == 0) {
		cout << str[0]; 
	}
	else {
		cout << str[len];
		recursiveReverse(str, len - 1);
	}
}