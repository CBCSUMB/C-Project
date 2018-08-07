/*----- treetester.cpp -----------------------------------------------------
Program for testing BST.
------------------------------------------------------------------------*/
/*
Assignment 7
Christopher Barbarick
2/19/18
Use Binary search trees to see the inorder and postorder of the tree
*/

#include <string>
#include <iostream>
using namespace std;

#include "BST.h"

int main()
{
	// Testing Constructor and empty()
	BST intBST;            // test the class constructor
	cout << "Constructing empty BST\n";
	cout << "BST " << (intBST.empty() ? "is" : "is not") << " empty\n";
	cout << "Your Tree is: " << intBST.nodeCount() << " items Long!" << endl;
	// Testing insert
	cout << "\nNow insert a bunch of integers into the BST."
		"\nTry items not in the BST and some that are in it:\n";
	int number;
	for (;;)
	{
		cout << "Item to insert (-999 to stop): ";
		cin >> number;
		if (number == -999) break;
		intBST.insert(number);
	}
	cout << "BST " << (intBST.empty() ? "is" : "is not") << " empty\n";

	// Testing search()
	cout << "\n\nNow testing the search() operation."
		"\nTry both items in the BST and some not in it:\n";
	for (;;)
	{
		cout << "Item to find (-999 to stop): ";
		cin >> number;
		if (number == -999) break;
		cout << (intBST.search(number) ? "Found" : "Not found") << endl;
	}
	cout << "Your Tree is: " << intBST.nodeCount() << " items Long!" << endl;
	cout << "Your Tree inorder is: "; intBST.inOrder();
	cout << endl;
	cout << "Your Tree preorder is: "; intBST.preOrder();
	system("pause");
}
