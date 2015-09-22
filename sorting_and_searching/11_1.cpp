/*
Name: Wesley Kepke
11.1: You are given two sorted arrays, A and B, where A has large enough buffer
at the end to hold B. Write a method to merge B into A in sorted order.
*/
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

#define ASIZE 10
#define BSIZE 4

void merge(int* a, int* b, int aSize, int bSize);
void randomize(int* a, int* aStop);
void printArray(const int* a, const int* aStop);

int main(void) {
	int* one = new int[ASIZE];
	int* two = new int[BSIZE];
	srand( time(NULL) );
	cout << "Randomizing first array:" << endl;
	randomize(one, one + (ASIZE - BSIZE));
	printArray(one, one + (ASIZE - BSIZE));
	cout << "Randomizing second array:" << endl;
	randomize(two, two + BSIZE);
	printArray(two, two + BSIZE);
	merge(one, two, ASIZE, BSIZE);
	cout << "Merged array:" << endl;
	printArray(one, one + ASIZE);
	delete []one;
	delete []two;
	one = NULL; 
	two = NULL;
	return 0; 
}

void merge(int* a, int* b, int aSize, int bSize) {
	int aLeng = aSize - 1;
	int bIndex = bSize - 1;
	int aIndex = (aSize - bSize) - 1; 

	for (aLeng; aLeng >= 0; aLeng--) {
		if (a[aIndex] > b[bIndex]) {
			a[aLeng] = a[aIndex];
			aIndex--; 
		}
		else {
			a[aLeng] = b[bIndex];
			bIndex--; 
		}
	}
}

void randomize(int* a, int* aStop) {
	int* index = a;
	int increasingRandomValue = rand() % 100;
	while (index != aStop) {
		*index = increasingRandomValue++; // forgot arrays needed to be sorted..
		index++;
	}
}

void printArray(const int* a, const int* aStop) {
	const int* index = a;
	while (index != aStop) {
		cout << *index << "\t";
		index++;
	}
	cout << endl; 
}