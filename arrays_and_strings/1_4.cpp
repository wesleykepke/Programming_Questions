/*
Name: Wesley Kepke
Date: May 14, 2015
Problem: Write a method to replace all spaces in a string with '%20'. You may 
assume that the string has sufficient space at the end of the string to hold 
the additional characters, and that you are given the "true" length of the
string. 
EXAMPLE:
Input "Mr John Smith"
Output: "Mr%20John%20Smith"
*/

#include <iostream>
#include <string.h>
using namespace std;

void replaceSpaces(char* str, int trueLength);

int main(void) {
	char sentence[256];
	bool loopCondition = true; 
	int actualLength = 0; 

	while(loopCondition == true) {
		cout << "Enter a phrase (type 'exit' to end program): ";
		cin.getline(sentence, 256);
		if(strcmp("exit", sentence) == 0) {
			loopCondition = false;
			break;
		}
		else {
			actualLength = strlen(sentence);
			replaceSpaces(sentence, actualLength);
			cout << "Result: " << sentence << endl;
		}
	}

	return 0; 
}

void replaceSpaces(char* str, int trueLength) {
	int spaceCount = 0;
	int lowIndex = 0;
	int highIndex = 0;

	if(strlen(str) == 0) {
		return;
	}		

	for(lowIndex = 0; lowIndex < trueLength; lowIndex++) {
		if(str[lowIndex] == ' ') {
			spaceCount++;
		}
	}

	lowIndex = trueLength - 1;
	highIndex = (trueLength + (spaceCount * 2)) - 1;
	for(lowIndex; lowIndex >= 0; lowIndex--) {
		if(str[lowIndex] == ' ') {
			str[highIndex] = '0';
			str[highIndex - 1] = '2';
			str[highIndex - 2] = '%';
			highIndex -= 3;
		}

		else {
			str[highIndex] = str[lowIndex];
			highIndex--;
		} 
	}

	highIndex = (trueLength + (spaceCount * 2));
	str[highIndex] = '\0';
}