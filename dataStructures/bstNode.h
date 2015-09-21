/* Node header file for a BST. */

#ifndef BSTNODE_H
#define BSTNODE_H

#include <iostream>

template<typename dataType>
class bstNode {
	public:
		bstNode(dataType newDataItem,
				bstNode* leftPtr,
				bstNode* rightPtr); 
		~bstNode(); 

		dataType dataItem;
		bstNode* leftBstNode;
		bstNode* rightBstNode; 
};

#endif