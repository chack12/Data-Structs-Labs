// BinarySearchTreesDLL.cpp : Defines the exported functions for the DLL.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>
#include "framework.h"
#include "BinarySearchTreesDLL.h"
#include <stack>

//*********************
//* BinarySearchTrees *
//*********************
bool BinarySearchTrees::Insert(Node* myNode)	{
	Node* cur = root;
	bool exitFlag = false;

	//If there is no root make the node the root
	if (root == nullptr) {
		root = myNode;
		return true;
	}

	while (!exitFlag) {
		//Traverse down the left side (also accounting for if the values are the same)
		if (myNode->GetValue().compare(cur->GetValue()) <= 0) {
			//Check to see if cur is the last node on the left
			if (cur->GetLeft() != nullptr)	{
				cur = cur->GetLeft();
			}
			else {
				cur->SetLeft(myNode);
				exitFlag = true;
			}
		}
		//Traverse down the right side
		else if (myNode->GetValue().compare(cur->GetValue()) > 0){
			//Check to see if cur is the last node on the right
			if (cur->GetRight() != nullptr) {
				cur = cur->GetRight();
			}
			else {
				cur->SetRight(myNode);
				exitFlag = true;
			}
		}
	}

	return false;
}

Node* BinarySearchTrees::Find(std::string myValue)	{
	Node* cur = root;

	while (true) {
		//Check the root
		if (cur->GetValue() == myValue) {
			return cur;
		}
		//Compare to cur and go down the left side
		else if (myValue.compare(cur->GetValue()) < 0) {
			cur = cur->GetLeft();
		}
		//Compare to cur and go down the right side
		else if (myValue.compare(cur->GetValue()) > 0) {
			cur = cur->GetRight();
		}
		else {
			return nullptr;
		}

		//If it can't find anything return nullptr
		if (cur == nullptr) {
			return nullptr;
		}
	}
}

int BinarySearchTrees::Size(Node* node)	{
	//If the root has noo value then the size is 0
	if (root == nullptr) {
		return 0;
	}
	else {
		//Recursively get the size of the left and right
		return Size(node->GetLeft()) + 1 + Size(node->GetRight());
	}
}

std::vector<std::string> BinarySearchTrees::GetAllAscending() {
	std::stack<Node*> stack;
	std::vector<std::string> retVal;
	Node* cur = root;
	Node* temp;
	bool notEmpty = true;

	while (notEmpty) {
		//Add all the left sides into the stack
		if (cur != nullptr) {
			stack.push(cur);
			cur = cur->GetLeft();
		}
		else {
			notEmpty = stack.size();
			//Make sure the stack isn't empty
			if (notEmpty) {
				//Get the top of the stack and put it into the array
				temp = stack.top();
				retVal.push_back(temp->GetValue());
				//Reset the value of cur
				cur = temp;
				//Get rid of the value that was just added to the vector
				stack.pop();

				//Get the right side of the tree
				cur = cur->GetRight();
			}
		}
	}

	return retVal;
}

std::vector<std::string> BinarySearchTrees::GetAllDescending()	{
	std::stack<Node*> stack;
	std::vector<std::string> retVal;
	Node* cur = root;
	Node* temp;
	bool notEmpty = true;

	while (notEmpty) {
		//Add all the right sides into the stack
		if (cur != nullptr) {
			stack.push(cur);
			cur = cur->GetRight();
		}
		else {
			notEmpty = stack.size();
			//Make sure the stack isn't empty
			if (notEmpty) {
				//Get the top of the stack and put it into the array
				temp = stack.top();
				retVal.push_back(temp->GetValue());
				//Reset the value of cur
				cur = temp;
				//Get rid of the value that was just added to the vector
				stack.pop();

				//Get the left side of the tree
				cur = cur->GetLeft();
			}
		}
	}

	return retVal;
}

bool BinarySearchTrees::EmptyTree()	{
	//Deleting the root will delete everything below it
	try {
		delete root;
		root = nullptr;
		return true;
	}
	catch (...) {
		return false;
	}
}

Node* BinarySearchTrees::Remove(std::string myValue) {
	Node* node = root;
	Node* parent = new Node();
	Node* temp = new Node();
	Node* removed = new Node();

	while (node != nullptr) {
		//If there is an empty tree
		if (node == nullptr) {
			return node;
		}
		//Go left until you find the node holding the value
		else if (myValue.compare(node->GetValue()) < 0) {
			parent = node;
			node = node->GetLeft();
		}
		//Go right until you find the node holding the value
		else if (myValue.compare(node->GetValue()) > 0) {
			parent = node;
			node = node->GetRight();
		}
		else
		{
			//No child
			if (node->GetRight() == nullptr && node->GetLeft() == nullptr) {
				if (parent->GetLeft() == node) {
					parent->SetLeft(nullptr);
				}
				else {
					parent->SetRight(nullptr);
				}

				//Checking to see if the node being removed is the last one
				if (root == node) {
					root = nullptr;
				}

				node = nullptr;
			}
			//One child left 
			else if (node->GetRight() == nullptr) {
				if (root == node) {
					root = node->GetLeft();
				}
				else {
					//Checking to see if the node needs to go on the other side
					if (node->GetRight() == nullptr) {
						parent->SetRight(node->GetLeft());
					}
					else {
						parent->SetLeft(node->GetLeft());
					}
				}
			}
			//One child right
			else if (node->GetLeft() == nullptr) {
				if (root == node) {
					root = node->GetRight();
				}
				else {
					//Checking to see if the node needs to go on the other side
					if (node->GetLeft() == nullptr) {
						parent->SetLeft(node->GetRight());
					}
					else {
						parent->SetRight(node->GetRight());
					}
				}
			}
			//Two child
			else {
				if (root == node) {
					//Getting the removed node
					removed = node;
					//Grabbing the side that will be deleted
					temp = root->GetLeft();
					//Moving the root up from the fight
					root = node->GetRight();
					//Making the node back to the root
					node = root;

					while (true) {
						//Get to the bottom of the new left side
						if (node->GetLeft() != nullptr && myValue.compare(node->GetValue()) < 0) {
							node = node->GetLeft();
						}
						//Setting the old left side at the bottom of new left side
						else {
							node->SetLeft(temp);
							
							removed->SetLeft(nullptr);
							removed->SetRight(nullptr);
							return removed;
						}
					}
				}
				else {
					//Grabbing the right side
					temp = node->GetRight();

					//Moving the left side
					while (temp->GetLeft() != nullptr) {
						temp = temp->GetLeft();
					}

					node->SetValue(temp->GetValue());
				}
			}

			if (node != nullptr) {
				node->SetLeft(nullptr);
				node->SetRight(nullptr);
			}
			
			return node;
		}
	}
}

Node* BinarySearchTrees::GetRoot() {
	return root;
}

//***********************
//* Node Implementation *
//***********************
bool Node::SetLeft(Node* myNode) {
	//Sets the left node
	left = myNode;
	if (myNode != nullptr) {
		return true;
	}

	return false;
}

bool Node::SetRight(Node* myNode)  {
	//Sets the right node
	right = myNode;
	if (myNode != nullptr) {
		return true;
	}

	return false;
}

Node* Node::GetLeft() {
	return left;
}

Node* Node::GetRight() {
	return right;
}

std::string Node::GetValue() {
	return value;
}

bool Node::SetValue(std::string myValue) {
	//Makes sure it isn't a blank value
	if (myValue != "") {
		value = myValue;
		return true;
	}

	return false;
}

bool Node::IsLeaf() {
	//Checks to see if the left and right are both nullptr
	if (left == nullptr && right == nullptr) {
		return true;
	}

	return false;
}