/*
Given two strings, write a method to decide if one is a permutation of the 
other.
Date: January 17, 2015 
*/

#include <iostream>
#include <string.h>
using namespace std;

bool isPermutation(char strOne[], char strTwo[]);

bool isPermutation2(char* strOne, char* strTwo);

int main(void)
	{
	char abcd[] = "abcd";
	char abc[] = "abc";
	char dbac[] = "dbac"; 

	cout << "First Implementation: " << endl; 
	cout << "ABCD is a permutation of ABC: " << isPermutation(abc, abcd) << endl; 
	cout << "ABC is a permutation of ABCD: " << isPermutation(abcd, abc) << endl; 
	cout << "DBAC is a permutation of ABCD: " << isPermutation(abcd, dbac) << endl; 
	cout << endl; 

	cout << "Second Implementation: " << endl; 
	cout << "ABCD is a permutation of ABC: " << isPermutation2(abc, abcd) << endl; 
	cout << "ABC is a permutation of ABCD: " << isPermutation2(abcd, abc) << endl;  
	cout << "DBAC is a permutation of ABCD: " << isPermutation2(abcd, dbac) << endl; 
	cout << endl; 


	return 0; 
}

// Assuming ASCII instead of Unicode
// Does not take into consideration white space or capital letters  
bool isPermutation(char strOne[], char strTwo[]) {
	if (strlen(strTwo) != strlen(strOne)) {
		return false; 
	}

	bool letterArr[256];
	int val = 0; 
	for (int i = 0; i < 256; i++) {
		letterArr[i] = false; 
	}

	for (int i = 0; i < strlen(strOne); i++) {
		val = strOne[i] - '0';
		letterArr[val] = true; 
	}

	for (int i = 0; i < strlen(strTwo); i++) {
		val = strTwo[i] - '0';
		if (letterArr[val] == false)
			{
			return false; 
			}
	}

	return true; 
}

// Assuming ASCII instead of Unicode
// Does not take into consideration white space or capital letters 
bool isPermutation2(char* strOne, char *strTwo) {
	if (strOne == NULL || strTwo == NULL) {
		return true; 
	}

	if (strlen(strOne) != strlen(strTwo)) {
		return false; 
	} 

	int* letters = new int[256];
	int val = 0; 
	for (int i = 0; i < 256; i++) {
		letters[i] = 0; 
	}

	for (int i = 0; i < strlen(strOne); i++) {
		val = strOne[i] - '0';
		letters[val]++; 
	}

	for (int i = 0; i < strlen(strTwo); i++) {
		val = strTwo[i] - '0';
		letters[val]--;
		if (letters[val] < 0) {
			return false; 
		}
	}

	delete []letters;
	letters = NULL; 
	return true; 
}