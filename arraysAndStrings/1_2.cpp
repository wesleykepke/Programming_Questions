/*
Implement a function void reverse(char* str) in C or C++ which reverses a 
null-terminated string. 
Date: January 17, 2015
*/

#include <iostream>
#include <string.h>
using namespace std;

void reverse(char* str);

int main(void) {
	char* wesley = new char[6];
	wesley[0] = 'w';
	wesley[1] = 'e';
	wesley[2] = 's';
	wesley[3] = 'l';
	wesley[4] = 'e';
	wesley[5] = 'y';
	char coding[6] = {'c', 'o', 'd', 'i', 'n', 'g'};

	reverse(wesley);
	for (int i = 0; i < strlen(wesley); i++) {
		cout << wesley[i]; 
	}
	cout << endl; 

	reverse(coding);
	for (int i = 0; i < strlen(coding); i++) {
		cout << coding[i]; 
	}
	cout << endl;

	return 0; 
}

void reverse(char* str) {
	if (strlen(str) == 0) {
		return; 
	}

	int head = 0; 
	int tail = strlen(str) - 1; // NULL character
	char temp; 
	while (head <= tail) {
		temp = str[head]; 
		str[head] = str[tail]; 
		str[tail] = temp; 
		head++;
		tail--; 
	}
}