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

	if (root == nullptr) {
		root = myNode;
		return true;
	}

	while (!exitFlag) {
		int temp = myNode->GetValue().compare(cur->GetValue());
		if (myNode->GetValue().compare(cur->GetValue()) < 0) {
			if (cur->GetLeft() != nullptr)	{
				cur = cur->GetLeft();
			}
			else	{
				cur->SetLeft(myNode);
				exitFlag = true;
			}
		}
		else if (myNode->GetValue().compare(cur->GetValue()) > 0){
			if (cur->GetRight() != nullptr) {
				cur = cur->GetRight();
			}
			else {
				cur->SetRight(myNode);
				exitFlag = true;
			}
		}
		else {
			//The values are equal
		}
	}

	return false;
}

Node* BinarySearchTrees::Find(std::string myValue)	{
	return nullptr;
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