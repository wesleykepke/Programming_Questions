/*
This is my implementation of quickSort.
*/
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

#define SIZE 11

void quickSort(int* array, int low, int high);
void partition(int* array, int low, int high);

int main(void) {
	int* testArray = new int[SIZE];
   srand( time(NULL) );
   int i = 0; 
   cout << "Randomizing array.." << endl; 
   for (i; i < SIZE; i++) {
      testArray[i] = rand() % 100;
      cout << testArray[i] << "\t";
   } 


   delete []testArray;
   testArray = NULL; 
	return 0; 
}

void quickSort(int* array, int low, int high) {

}

void partition(int* array, int low, int high) {

}