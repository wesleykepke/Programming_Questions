/* Header file for a bst. */

#ifndef BST_H
#define BST_H

#include "bstNode.h"
#include <iostream>

template<typename dataType>
class bst {
	public:
		bst();
		~bst();

		void insert(const dataType& newDataItem); 
		void clear(); 
		void inorderDisplay() const;
		bool searchTree(const dataType& dataItemToSearchFor) const;  

	private:
		bstNode<dataType>* root;
		void insertHelper(bstNode<dataType>*& node, const dataType& newDataItem); 
		void clearHelper(bstNode<dataType>*& node);
		void inorderDisplayHelper(bstNode<dataType>* node) const;
		bool searchTreeHelper(bstNode<dataType>* node, 
								const dataType& dataItemToSearchFor) const;   
};


#endif