/*
Implement a method to perform basic string compression using the counts 
of repeated characters. For example, the string aabcccccaaa would become
a2b1c5a3. If the "compressed" string would not become smaller than the original
string, your method should return the original string. You can assume the string
only has upper and lower case letters (a-z). 

Date: January 19, 2015
*/

#include <iostream>
#include <string.h>
using namespace std; 

void compression(char* arr);
void printStr(const char* arr);

int main(void) {
	char temp[11] = {'a', 'a', 'b', 'c', 'c', 'c', 'c', 'c', 'a', 'a', 'a'};
	char temp2[] = "abbbbbbbbbaaaaaawwwwwwwww";

	cout << "First Attempt: aabcccccaaa" << endl;  
	compression(temp);
	printStr(temp); 

	cout << endl << "Second Attempt: abbbbbbbbbaaaaaawwwwwwwww" << endl;  
	compression(temp2);
	printStr(temp2); 
	return 0; 
}

void printStr(const char* arr) {
	while (*arr != '\0') {
		cout << *arr;
		arr++; 
	}
	cout << endl; 
}

void compression(char* arr) {
	int numLetters = 0; 
	int originalLength = strlen(arr);
	int compressedLength = 0;
	int letterPos = 0;
	char temp; 

	if (arr == NULL || strlen(arr) == 0) {
		return; 
	}

	temp = arr[0];
	numLetters++;  
	for (int i = 1; i < originalLength; i++) {
		if (arr[i] != temp) {
			numLetters++;
			temp = arr[i];  
		}
	} 

	compressedLength = numLetters * 2; 
	if (compressedLength > originalLength) {
		return; 
	}

	temp = arr[0];
	numLetters = 1; 
	for (int i = 1; i <= originalLength; i++) {
		if (arr[i] == temp) {
			numLetters++; 
		}
		else {
			arr[letterPos] = temp;
			arr[letterPos + 1] = (numLetters + '0');
			letterPos += 2; 
			if (numLetters == 1) {
				temp = arr[i + 1];  
			}
			else {
				temp = arr[i];
			}
			numLetters = 1; 
		}
	}
	arr[compressedLength] = '\0'; 
}