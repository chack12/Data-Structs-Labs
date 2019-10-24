// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the BINARYSEARCHTREESDLL_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// BINARYSEARCHTREESDLL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef BINARYSEARCHTREESDLL_EXPORTS
#define BINARYSEARCHTREESDLL_API __declspec(dllexport)
#else
#define BINARYSEARCHTREESDLL_API __declspec(dllimport)
#endif

#include <iostream>
#include <vector>

//Binary Search Tree Node Header File
class BINARYSEARCHTREESDLL_API Node {
public:
	/**
	* The constructor for the node
	*
	* @param
	* @return
	*/
	Node() {}
	/**
	* The constructor for the node
	*
	* @param
	* @return
	*/
	Node(std::string myValue) {
		value = myValue;
		left = nullptr;
		right = nullptr;
	}
	/**
	* Sets the left pointer to the node
	*
	* @param	node	pointer to the left node
	* @return			whether it was successful or not
	*/
	bool SetLeft(Node* myNode);
	/**
	* Sets the right pointer of the node
	*
	* @param	node	pointer to the right
	* @return			whether it was successful for not
	*/
	bool SetRight(Node* myNode);
	/**
	* Returns a pointer to the left node
	*
	* @param
	* @return			the pointer to the left node
	*/
	Node* GetLeft();
	/**
	* Returns a pointer to the right node
	*
	* @param
	* @return			the pointer to the right node
	*/
	Node* GetRight();
	/**
	* Sets the item of the node
	*
	* @param	value	the value you want set the node to
	* @return			whether it was successful or not
	*/
	bool SetValue(std::string myValue);
	/**
	* Gets the nodes value
	*
	* @param	node	pointer to the left node
	* @return
	*/
	std::string GetValue();
	/**
	* Whether or not the node is a Leaf
	*
	* @param
	* @return		the value of the node
	*/
	bool IsLeaf();
	/**
	* The destructor for the node
	*
	* @param
	* @return
	*/
	~Node() {
		delete left;
		delete right;
	}
private:
	std::string value;
	Node* left;
	Node* right;
};

//Binary Search Tree Header File
class BINARYSEARCHTREESDLL_API BinarySearchTrees {
public:
	/**
	* The constructor for the Binary Search Tree
	*
	* @param
	* @return
	*/
	BinarySearchTrees() {
		root = nullptr;
	}
	/**
	* The Constructor for the Binary Search Tree
	*
	* @param	node	the node you want to insert
	* @return			whether it was successful for not
	*/
	bool Insert(Node* myNode);
	/**
	* Returns the root of the tree
	*
	* @param
	* @return			returns the root of the tree
	*/
	Node* GetRoot();
	/**
	* Locates the value in the ree and returns a pointer to the node
	* If not in the tree, returns nullptr
	*
	* @param	value	the value you want to find
	* @return			whether it was successful for not
	*/
	Node* Find(std::string myValue);
	/**
	* Returns the size of the binary tree
	* Reference- https://www.geeksforgeeks.org/write-a-c-program-to-calculate-size-of-a-tree/
	* @param	
	* @return			the size of the binary tree 
	*/
	int Size(Node* node);
	/**
	* Returns a vector with all the node's values in ascending order
	* Referenced the powerpoints
	* @param
	* @return			the node's values in ascending order
	*/
	std::vector<std::string> GetAllAscending();
	/**
	* Returns a vector with all the node's values in descending order
	* Referenced the powerpoints
	* @param	
	* @return			the node's values in descending order
	*/
	std::vector<std::string> GetAllDescending();
	/**
	* Checks to see if the tree is empty
	*
	* @param	
	* @return			whether it is was successful or not 
	*/
	bool EmptyTree();
	/**
	* Removes the specified value from the binary tree
	* 
	* @param	value	the value you want to remove
	* @return			whether it was successful for not
	*/
	Node* Remove(std::string myValue);
	/**
	* The destructor for the binary tree
	* Reference - https://stackoverflow.com/questions/45122270/deleting-a-node-from-a-binary-search-tree-without-recursion
	* @param
	* @return
	*/
	~BinarySearchTrees() {
		delete root;
	}
private:
	Node* root;
};