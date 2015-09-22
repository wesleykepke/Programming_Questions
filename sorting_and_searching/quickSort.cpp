/*
This is my implementation of quickSort.
*/
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

#define SIZE 11

void quickSort(int* array, int low, int high);
int partition(int* array, int low, int high);
void swap(int* array, int low, int high);

int main(void) {
   // variables 
	int* testArray = new int[SIZE];
   srand( time(NULL) );
   int i = 0; 

   // fill array with random values
   cout << "Randomizing array.." << endl; 
   for (i; i < SIZE; i++) {
      testArray[i] = rand() % 100;
      cout << testArray[i] << "\t";
   } 
   cout << endl;

   // perform quickSort
   cout << "After quickSort():" << endl; 
   quickSort(testArray, 0, SIZE - 1);
   for (i = 0; i < SIZE; i++) {
      cout << testArray[i] << "\t";
   }
   cout << endl; 

   // clean up
   delete []testArray;
   testArray = NULL; 
	return 0; 
}

void quickSort(int* array, int low, int high) {
   int index = partition(array, low, high);
   if (low < (index - 1)) {
      quickSort(array, low, index - 1);
   } 
   if (index < high) {
      quickSort(array, index, high);
   }
}

int partition(int* array, int low, int high) {
   int pivot = array[(low + high) / 2];

   while (low <= high) {
      // find an element on the left that doesn't belong
      while (array[low] < pivot) {
         low++; 
      }

      // find an element on the right that doesn't belong
      while (array[high] > pivot) {
         high--; 
      }

      // swap elements if necessary 
      if (low <= high) {
         swap(array, low, high);
         low++;
         high--; 
      }
   }

   return low; 
}

void swap(int* array, int low, int high) {
   int temp = array[low];
   array[low] = array[high];
   array[high] = temp;
}