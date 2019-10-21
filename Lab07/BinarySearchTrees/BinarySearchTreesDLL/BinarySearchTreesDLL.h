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

//Binary Search Tree Header File
class BINARYSEARCHTREESDLL_API BinarySearchTrees {
public:
	/**
	* The constructor for the Binary Search Tree
	*
	* @param
	* @return
	*/
	BinarySearchTrees();
	/**
	* The Constructor for the Binary Search Tree
	*
	* @param	node	the node you want to insert
	* @return			whether it was successful for not
	*/
	bool Insert(Node node);
	/**
	* Locates the value in the ree and returns a pointer to the node
	* If not in the tree, returns nullptr
	*
	* @param	value	the value you want to find
	* @return			whether it was successful for not
	*/
	Node* Find(std::string value);
	/**
	* Returns the size of the binary tree
	*
	* @param	
	* @return			the size of the binary tree 
	*/
	int Size();
	/**
	* 
	*
	* @param
	* @return
	*/
	std::vector<int> GetAllAscending();
	/**
	* 
	*
	* @param	
	* @return 
	*/
	std::vector<int> GetAllDescending();
	/**
	* Checks to see if the tree is empty
	*
	* @param	
	* @return	value	whether it is was successful or not 
	*/
	bool EmptyTree();
	/**
	* Removes the specified value from the binary tree
	*
	* @param	value	the value you want to remove
	* @return			whether it was successful for not
	*/
	bool Remove(std::string value);
	/**
	* The destructor for the binary tree
	*
	* @param
	* @return
	*/
	~BinarySearchTrees() {
		delete root;
	}
private:
	Node* root;
};

//Binary Search Tree Node Header File
class BINARYSEARCHTREESDLL_API Node {
public:
	/**
	* The constructor for the node
	*
	* @param
	* @return
	*/
	Node();
	/**
	* Sets the left pointer to the node
	*
	* @param	node	pointer to the left node
	* @return	value	whether it was successful or not 
	*/
	bool SetLeft(Node* node);
	/**
	* Sets the right pointer of the node
	*
	* @param	node	pointer to the right
	* @return			whether it was successful for not
	*/
	bool SetRight(Node* node);
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
	bool SetItem(std::string value);
	/**
	* Whether or not the node is a Leaf
	*
	* @param	
	* @return	value	whether it was successful or not
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
	Node* left;
	Node* right;
};