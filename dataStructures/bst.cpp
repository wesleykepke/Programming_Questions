/* Implementation file for a bst. */

#include "bst.h"

template<typename dataType>
bst<dataType>::bst() {
	root = NULL; 
}

template<typename dataType>
bst<dataType>::~bst() {
	clear(); 
}

template<typename dataType>
void bst<dataType>::insert(const dataType& newDataItem) {
	insertHelper(root, newDataItem); 
}

template<typename dataType>
void bst<dataType>::clear() {
	clearHelper(root);
}

template<typename dataType>
void bst<dataType>::inorderDisplay() const {
	inorderDisplayHelper(root); 
}

template<typename dataType>
bool bst<dataType>::searchTree(const dataType& dataItemToSearchFor) const {
	return searchTreeHelper(root, dataItemToSearchFor);
}

template<typename dataType>
void bst<dataType>::insertHelper(bstNode<dataType>*& node, const dataType& newDataItem) {
	if(node == NULL) {
		node = new bstNode<dataType>(newDataItem, NULL, NULL); 
	}
	else {
		if(newDataItem <= node->dataItem) {
			insertHelper(node->leftBstNode, newDataItem); 
		}
		else {
			insertHelper(node->rightBstNode, newDataItem); 
		}
	}
}

template<typename dataType>
void bst<dataType>::clearHelper(bstNode<dataType>*& node) {
	if(node != NULL) {
		clearHelper(node->leftBstNode);
		clearHelper(node->rightBstNode);
		delete node;
		node = NULL; 
	}
}

template<typename dataType>
void bst<dataType>::inorderDisplayHelper(bstNode<dataType>* node) const {
	if(node != NULL) {
		inorderDisplayHelper(node->leftBstNode);
		std::cout << node->dataItem << " "; 
		inorderDisplayHelper(node->rightBstNode); 
	}
}

template<typename dataType>
bool bst<dataType>::searchTreeHelper(bstNode<dataType>* node, 
										const dataType& dataItemToSearchFor) const {
	if(node != NULL) {
		if(node->dataItem == dataItemToSearchFor) {
			return true; 
		}
		else if(dataItemToSearchFor < node->dataItem) {
			return searchTreeHelper(node->leftBstNode, dataItemToSearchFor); 
		}
		else {
			return searchTreeHelper(node->rightBstNode, dataItemToSearchFor); 
		}
	}
	else {
		return false; 
	}
}

/* Needed because this class is templated. */
template class bst<int>;
template class bst<char>; 