/*
Write a method to replace all spaces in a string with '%20'. You may assume 
that the string has sufficient space at the end of the string to hold the 
additional characters, and that you are given the "true" length of the string.

EXAMPLE:
Input: "Mr John Smith    ", 13
Output: "Mr%20John%20Smith"

Date: January 19, 2015
*/

#include <iostream>
#include <string.h>
using namespace std;

void replace(char* str, int trueLength);

int main(void) {
	char temp[17] = {'M', 'r', ' ', 'J', 'o', 'h', 'n', ' ', 'S', 
						'm', 'i', 't', 'h', ' ', ' ', ' ', ' '};
	replace(temp, 13);
	cout << "Output: " << endl; 
	for (int i = 0; i < 17; i++) {
		cout << temp[i]; 
	}
	cout << endl; 

	return 0; 
}

void replace(char* str, int trueLength) {
	if (str == NULL || strlen(str) == 0) {
		return; 
	}

	int spaceCount = 0;
	for (int i = 0; i < trueLength; i++) {
		if (str[i] == ' ') {
			spaceCount++; 
		}
	}

	int moveLength = (spaceCount * 3) - spaceCount;
	int head = trueLength - 1;
	int tail = trueLength + moveLength - 1; 
	while (spaceCount > 0) {
		if (str[head] == ' ') {
			str[tail] = '0';
			tail--;
			str[tail] = '2';
			tail--;
			str[tail] = '%'; 
			spaceCount--;
			head--; 
			tail--;
		}
		else {
			str[tail] = str[head]; 
			head--;
			tail--; 
		}
	}
}