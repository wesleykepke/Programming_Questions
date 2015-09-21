/*
Here's my implementation of merge sort. 
*/
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

#define SIZE 11
#define INFINITY 9999999

void mergeSort(int* array, int low, int high);
void merge(int* array, int low, int high);

int main(void) {
   // initialization 
   int* testArray = new int[SIZE];
   int i;
   srand( time(NULL) );

   // randomize array 
   cout << "Randomizing array of size: " << SIZE << endl; 
   for (i = 0; i < SIZE; i++) {
      testArray[i] = rand() % 100; 
      cout << testArray[i] << "\t"; 
   }
   cout << endl;

   // perform merge sort procedure 
   mergeSort(testArray, 0, SIZE - 1);
   cout << "after merge" << endl; 

   // display results 
   for (i = 0; i < SIZE; i++) {
      cout << testArray[i] << "\t"; 
   }
   cout << endl;

   // clean up program 
   delete []testArray;
   testArray = NULL; 
   return 0; 
}

void mergeSort(int* array, int low, int high) {
   int mid = 0; 
   cout << "Low: " << low << endl;
   cout << "High: " << high << endl; 
   if (low < high) {
      mid = (high - low) / 2;
      mergeSort(array, low, mid);
      mergeSort(array, mid + 1, high);
      merge(array, low, high);
   }
}

void merge(int* array, int low, int high) {
   int mid = (high - low) / 2;
   vector<int> lower;
   vector<int> higher;
   int i = low; 
   int lowIndex = 0;
   int highIndex = 0; 

   for (i; i <= mid; i++) {
      lower.push_back(array[i]);
   }
   lower.push_back(INFINITY);

   for (i = (mid + 1); i <= high; i++) {
      higher.push_back(array[i]);
   }
   higher.push_back(INFINITY);

   for (i = low; i <= high; i++) {
      if (lower[lowIndex] < higher[highIndex]) {
         array[i] = lower[lowIndex];
         lowIndex++; 
      }
      else {
         array[i] = higher[highIndex];
         highIndex++; 
      }
   }
}