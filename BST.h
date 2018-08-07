#include <iostream>
using namespace std;

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

class BST
{
 public:
  /***** Function Members *****/
  BST();
  bool empty() const;
  bool search(int  item) const; 
  void insert(const int & item);



private:
	/***** Node class *****/
	class BinNode
	{
	public:
		int data;
		BinNode * left;
		BinNode * right;

		// BinNode constructors
		// Default -- data part is default int value; both links are null.
		BinNode()
			: left(0), right(0)
		{}

		// Explicit Value -- data part contains item; both links are null.
		BinNode(int item)
			: data(item), left(0), right(0)
		{}

	};// end of class BinNode declaration
	


	  /***** Data Members *****/
	BinNode * myRoot;
public:
	/***** Function Members *****/
	bool searchRec(BinNode * Root, int  item) const;
	void inOrder();
	void inOrderRec(BinNode * Root);
	void preOrder();
	void preOrderRec(BinNode * Root);
	int nodeCount();
	int nodeCountRec(BinNode * Root, int count);
	//void inOrder(myRoot);
	//void preOrderRec(myRoot);
	//int nodeCountRec(myRoot, int count);


}; // end of class declaration

#endif