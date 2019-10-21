// BinarySearchTreesDLL.cpp : Defines the exported functions for the DLL.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>
#include "framework.h"
#include "BinarySearchTreesDLL.h"

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

int BinarySearchTrees::Size()	{
	return 0;
}

std::vector<std::string> BinarySearchTrees::GetAllAscending()	{
	std::vector<std::string> temp;
	return temp;
}

std::vector<std::string> BinarySearchTrees::GetAllDescending()	{
	std::vector<std::string> temp;
	return temp;
}

bool BinarySearchTrees::EmptyTree()	{
	return false;
}

bool BinarySearchTrees::Remove(std::string myValue) {
	Node* cur = new Node();
	if (root == nullptr) {
		return false;
	}
	// If value is greater than root, start traversing left
	else if (root->GetValue().compare(myValue) < 0) {
		cur = root->GetLeft();
		while (cur->GetValue().compare(myValue) != 0) {
			// Continue to traverse left
			if (cur->GetValue().compare(myValue) < 0) {
				if (cur->GetLeft() != nullptr) {
					cur = cur->GetLeft();
				}
				else  {
					return false;
				}
				
			}
			// Go to the right
			else if (cur->GetValue() < myValue && cur->GetRight() != nullptr)	{
				cur = cur->GetRight();
			}
		}
	}


	return false;
}

/*std::string BinarySearchTrees::ToLower(std::string myValue) {
	std::transform(myValue.begin(), myValue.end(), myValue.begin(), [](unsigned char c) { return std::tolower(c); });

	return myValue;
}*/

//***********************
//* Node Implementation *
//***********************
bool Node::SetLeft(Node* myNode) {
	if (myNode != nullptr) {
		left = myNode;
		return true;
	}

	return false;
}

bool Node::SetRight(Node* myNode)  {
	if (myNode != nullptr) {
		right = myNode;
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
	if (myValue != "") {
		value = myValue;
		return true;
	}

	return false;
}

bool Node::IsLeaf() {
	if (left == nullptr && right == nullptr) {
		return true;
	}

	return false;
}