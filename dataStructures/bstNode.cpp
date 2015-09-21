/* Implementation file for bstNode */

#include "bstNode.h"

template<typename dataType>
bstNode<dataType>::bstNode(dataType newDataItem, 
					bstNode* leftPtr,
					bstNode* rightPtr) {
	dataItem = newDataItem; 
	leftBstNode = leftPtr;
	rightBstNode = rightPtr; 
}

template<typename dataType>
bstNode<dataType>::~bstNode() {
	leftBstNode = NULL;
	rightBstNode = NULL; 
}

template class bstNode<int>;
template class bstNode<char>; 