/*
Name: Wesley Kepke
Date: May 15, 2015
Problem: Implement a method to perform basic string compression using the 
counts of repeated characters. For example, the string aabcccccaaa would
become a2b1c5a3. If the "compressed" string would not become smaller than
the original string, your method should return the original string. You
can assume the string has only upper and lower case letters (a-z).
*/

#include <iostream>
#include <string.h>
using namespace std;

/*
Only works for sequences that have less than 9 of the same characters in 
succession
*/
void stringCompression(char* str);

int main(void) {
	char temp[256];
	bool loopCondition = true; 

	while(loopCondition == true) {
		cout << "Enter a string to compress (type 'exit' to end program): ";
		cin >> temp;
		if(strcmp("exit", temp) == 0) {
			loopCondition = false;
			break;
		}
		stringCompression(temp);
		cout << "Compressed string is: " << temp << endl;
	}

	return 0; 
}

void stringCompression(char* str) {
	int lowIndex = 0;
	int highIndex = lowIndex + 1;
	int mainIndex = 0;
	int strLength = strlen(str);
	int charCount = 1;
	int successiveLetterCount = 0;
	char targetLetter; 

	for(lowIndex = 1; lowIndex < strLength; lowIndex++) {
		if(str[lowIndex] != str[lowIndex - 1]) {
			charCount++; 
		}
	}

	if((charCount * 2) > strLength) {
		return; 
	}

	lowIndex = 0;
	targetLetter = str[lowIndex]; 
	for(mainIndex = 0; mainIndex <= strLength; mainIndex++) {
		if(str[mainIndex] == targetLetter) {
			successiveLetterCount++; 
		}

		else if((str[mainIndex] != targetLetter) && 
					successiveLetterCount == 1) {
			str[lowIndex] = targetLetter;
			targetLetter = str[mainIndex];
			str[highIndex] = successiveLetterCount + '0';
			successiveLetterCount = 1;
			lowIndex += 2;
			highIndex = lowIndex + 1;
		}

		else {
			str[lowIndex] = targetLetter; 
			str[highIndex] = successiveLetterCount + '0'; 
			lowIndex += 2;
			highIndex = lowIndex + 1; 
			successiveLetterCount = 1;
			targetLetter = str[mainIndex];
		}
	}

	str[charCount * 2] = '\0';
}