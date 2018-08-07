#include <iostream>
#include <iomanip>

using namespace std;

#include "BST.h"

//--- Definition of constructor
BST::BST()
	: myRoot(0)
{}

bool BST::empty() const
{
	return myRoot == 0;
}

//­­­Definition for search. Calls our recursive
//­­­version of search to find an item in the tree
bool BST::search( int  item) const {
	// Call our recursive function to find item
	return searchRec(myRoot, item);
}
//­­­Definition for searchRec. Search through a BST
//­­­recursively to find an item.
bool BST::searchRec(BinNode* Root, int  item) const
{
	// Search for an item recursively, true found
	// false otherwise.
	if (Root == NULL) {
		return false;
	}
	else if (Root->data == item) 
	{
		return true;
	}
	else if (item<=Root->data) 
	{ // descend left
		return searchRec(Root -> left, item);
	}
	else 
	{ // descend right
		return searchRec(Root->right, item);
	}
}


void BST::insert(const int & item)
{
	BinNode * locptr = myRoot;   // search pointer
	BinNode * parent = 0;        // pointer to parent of current node
	bool found = false;     // indicates if item already in BST
	while (!found && locptr != 0)
	{
		parent = locptr;
		if (item < locptr->data)       // descend left
			locptr = locptr->left;
		else if (locptr->data < item)  // descend right
			locptr = locptr->right;
		else                           // item found
			found = true;
	}
	if (!found)
	{                                 // construct node containing item
		locptr = new BinNode(item);
		if (parent == 0)               // empty tree
			myRoot = locptr;
		else if (item < parent->data)  // insert to left of parent
			parent->left = locptr;
		else                           // insert to right of parent
			parent->right = locptr;
	}
	else
		cout << "Item already in the tree\n";
}
void BST::inOrder() {
	return inOrderRec(myRoot);
}
void BST::inOrderRec(BinNode* Root) {
	if (Root == NULL) {
		return;
	}
	inOrderRec(Root->left);
	printf("%i", Root->data);
	cout << " ";
	inOrderRec(Root->right);
}

void BST::preOrder() {
	return preOrderRec(myRoot);
}
//­­­Definition of preOrderRecursive function.
void BST::preOrderRec(BinNode* Root) {
	if (Root == NULL) {
		return;
	}
	printf("%i", Root->data);
	cout << " ";
	preOrderRec(Root->left);
	preOrderRec(Root->right);
}
int BST::nodeCount() {
	int count = 0;
	return nodeCountRec(myRoot, count);
}

//­­­Definition of nodeCountRecursive function
int BST::nodeCountRec(BinNode* Root, int count) {
	if (Root == NULL) {
		return 0;
	}
	else {
		count = 1 + nodeCountRec(Root->left,
			count) + nodeCountRec(Root->right, count);
	}
	return count;
}