/*
Name: Wesley Kepke
Date: May 14, 2015
Problem: Implement a function void reverse(char* str) in C or C++ which 
reverses a null-terminated string.
*/

#include <iostream>
#include <string.h>
using namespace std;

void reverse(char* str);
void swapLetters(char* str, int firstLoc, int secondLoc);

int main(void) {
	char* temp = new char[300];
	bool loopCondition = true;

	while(loopCondition == true) {
		cout << "Enter a string to reverse (type 'exit' to end program): ";
		cin >> temp; 
		if(strcmp("exit", temp) == 0) {
			loopCondition = false; 
		}
		reverse(temp);
		cout << "Reversed string is: " << temp << endl; 
	}

	delete []temp;
	temp = NULL; 
	return 0;
}

void reverse(char* str) {
	int low = 0;
	int high = strlen(str) - 1;

	if(strlen(str) == 0) {
		return; 
	}

	while(low < high) {
		swapLetters(str, low, high);
		low++;
		high--;
	}
}

void swapLetters(char* str, int firstLoc, int secondLoc) {
	char temp = str[firstLoc];
	str[firstLoc] = str[secondLoc];
	str[secondLoc] = temp; 
}