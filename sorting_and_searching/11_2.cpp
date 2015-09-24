/*
Name: Wesley Kepke
11.2: Write a method to sort an array of strings so that all of the anagrams
are next to each other.
*/
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

void promptUserForInput(char**& words, int& numWords); 
void sortByAnagram(char** words, int size);
bool isAnagram(char* wordOne, char* wordTwo); 
void printWords(char**words, int numWords); 
void deallocateMemory(char**& words, int numWords); 

int main(void) {
	int numWordsForInput = 0;
	char** wordsFromInput = NULL; 	
	promptUserForInput(wordsFromInput, numWordsForInput);
	printWords(wordsFromInput, numWordsForInput); 
	
	deallocateMemory(wordsFromInput, numWordsForInput); 
	return 0;
}

void promptUserForInput(char**& words, int& numWords) {
	char* buffer = new char[50]; 

	cout << "Enter number of words for program (include anagrams): ";
	cin >> numWords;
	words = new char*[numWords];
	for (int i = 0; i < numWords; i++) {
		cout << "Please enter a word: ";
		cin >> buffer;
		words[i] = new char[strlen(buffer)];
		strcpy(words[i], buffer); 
	}
	cout << "Thank you.." << endl; 
}
void sortByAnagram(char** words, int size) {
	char* word = NULL; 
	bool anagramList = new bool[size]; 
	; 
	char* temp = new char[50]; 
	for (int i = 0; i < size; i++) {
		word = words[i]; 
		for (int j = 0; j < size; j++) {
			if (isAnagram(word, words[i])) {
				anagramList[j] = true;
				strcpy(temp, words[i]		
			}	
		}
	}

	delete []temp;
	temp = NULL; 
	delete []anagramList;
	anagramList = NULL; 
}

/*
This function doesn't really check for anagrams. Instead, it mainly checks to
see if all the letters in one words exist in another word.
*/
bool isAnagram(char* wordOne, char* wordTwo) {
	if (strlen(wordOne) != strlen(wordTwo)) {
		return false; 
	}

	// initialize temp array to keep track of letters in wordOne
	int* lettersInWordOne = new int[128];
	for (int i = 0; i < 128; i++) {
		lettersInWordOne[i] = 0;
	}

	// determine which letters are in wordOne
	for (int i = 0; i < strlen(wordOne); i++) {
		lettersInWordOne[wordOne[i] - '0']++; 
	}

	// check for symmetry 
	for (int i = 0; i < strlen(wordTwo); i++) {
		if (--lettersInWordOne[wordTwo - '0'] < 0) {
			return false; 	
		}
	}

	delete []lettersInWordOne;
	lettersInWordOne = NULL; 
	return true; 
} 
 
void printWords(char**words, int numWords) {
	for (int i = 0; i < numWords; i++) {
		cout << words[i] << endl; 
	}
} 

void deallocateMemory(char**& words, int numWords) {
	for (int i = 0; i < numWords; i++) {
		delete []words[i];
		words[i] = NULL;
	}
	delete []words;
	words = NULL; 
}
