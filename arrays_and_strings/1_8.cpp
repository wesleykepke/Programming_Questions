/*
Name: Wesley Kepke
Date: May 19, 2015
Problem: Assume you have a method "isSubstring" which checks if one string is a 
substring of another. Given two strings, s1 and s2, write code to check if s2
is a rotation of s1 using only one call to "isSubstring" (e.g., "waterbottle"
is a rotation of "erbottlewat").
*/

#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

bool isSubstring(vector<char> str1, vector<char> str2);
bool isRotation(vector<char> str1, vector<char> str2);
void printCharVector(vector<char> str); 

int main(void) {
	vector<char> s1;
	vector<char> s2;
	char* s1Temp = new char[100];
	char* s2Temp = new char[100];
	int s1TempLength = 0;
	int s2TempLength = 0;
	bool loopCondition = true;
	bool isRotationResult = false; 

	while(loopCondition == true) {
		cout << "Enter first word (type 'exit' to end program): ";
		cin >> s1Temp;
		if(strcmp(s1Temp, "exit") == 0) {
			loopCondition = false;
			continue;
		}

		cout << "Enter second word: ";
		cin >> s2Temp;
		s1TempLength = strlen(s1Temp);
		s2TempLength = strlen(s2Temp);
		s1.insert(s1.begin(), s1Temp, s1Temp + s1TempLength);
		s2.insert(s2.begin(), s2Temp, s2Temp + s2TempLength);
		isRotationResult = isRotation(s1, s2);
		switch(isRotationResult) {
			case true:
				cout << s2Temp << " is a rotation of " << s1Temp << "." << endl;
			break;

			case false:
				cout << s2Temp << " is not a rotation of " << s1Temp << "." << endl;
			break;
		};
		s1.clear();
		s2.clear();
	}

	delete []s1Temp;
	s1Temp = NULL;
	delete []s2Temp;
	s2Temp = NULL; 
	return 0; 
}

/*
Checks if "str2" is a substring of "str1."
*/
bool isSubstring(vector<char> str1, vector<char> str2) {
	vector<char>::iterator s1Iterator;
	vector<char>::iterator s2Iterator = str2.begin();
	int s1Size = str1.size();
	int s2Size = str2.size();
	int sameLetterCount = 0; 

	if(s2Size > s1Size) {
		return false;
	}

	for(s1Iterator = str1.begin(); s1Iterator < str1.end(); s1Iterator++) {
		if(*s1Iterator == *s2Iterator) {
			s2Iterator++;
			sameLetterCount++;
			if(sameLetterCount == s2Size) {
				return true;
			}
		}

		else if(sameLetterCount > 0) {
			s2Iterator = str2.begin();
			sameLetterCount = 0;
		}
	}

	return false; 
}

/*
If "str1" = "waterbottle" and "str2" = "erbottlewat," then we should find a 
point of rotation. The point of rotation is around the segment "wat" in 
this example.
So, if we let:
x = "wat"
y = "erbottle"
.. then yx = "erbottlewat" and xy = "waterbottle."
If we produce the string xyxy, then we can see that yx exists in that string.
Using "isSubstring," we will see if "str2" is then a rotation of "str1."
*/
bool isRotation(vector<char> str1, vector<char> str2) {
	vector<char> str1str1;
	str1str1.insert(str1str1.begin(), str1.begin(), str1.end());
	str1str1.insert(str1str1.end(), str1.begin(), str1.end());
	
	if(str1.size() != str2.size()) {
		return false;
	}

	return isSubstring(str1str1, str2);
}

void printCharVector(vector<char> str) {
	vector<char>::iterator i;
	for(i = str.begin(); i < str.end(); i++) {
		cout << *i;
	}
}
