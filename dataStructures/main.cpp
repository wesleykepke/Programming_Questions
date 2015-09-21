#include <iostream>
#include "bst.h"
#include "bstNode.h"
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(void) {
	cout << "Main Driver!" << endl;
	bst<int> binaryTree;
	int userInput = 0; 
	char loopConditionHelper; 
	bool loopCondition = true; 

	cout << "Please enter 10 numbers: " << endl; 
	for(int i = 0; i < 10; i++) {
		cout << '\t' << "Input: ";
		cin >> userInput;
		binaryTree.insert(userInput); 
	}

	cout << "Displaying tree (inorder traversal): " << endl;
	binaryTree.inorderDisplay();
	cout << endl;

	cout << "Enter a number to search for: ";
	cin >> userInput;
	while(loopCondition) {
		if(binaryTree.searchTree(userInput)) {
			cout << "Input " << userInput << " exists in the tree." << endl; 
		}
		else {
			cout << "Input " << userInput << " does not exist in the tree." << endl;  
		}
		cout << "Would you like to search for more data in the tree? (Y/y or N/n): ";
		cin >> loopConditionHelper;
		loopCondition = (loopConditionHelper == 'y' || loopCondition == 'Y');
		if(loopCondition) {
			cout << "Enter a number to search for: ";
			cin >> userInput;
		}
	}

	return 0; 
}