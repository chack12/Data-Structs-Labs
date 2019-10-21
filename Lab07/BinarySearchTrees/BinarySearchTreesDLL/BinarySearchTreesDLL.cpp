// BinarySearchTreesDLL.cpp : Defines the exported functions for the DLL.
//

#include <iostream>
#include <vector>
#include "framework.h"
#include "BinarySearchTreesDLL.h"

//BinarySearchTrees Implementation
bool BinarySearchTrees::Insert(Node myNode)	{
	return false;
}

Node* BinarySearchTrees::Find(std::string myValue)	{

}

int BinarySearchTrees::Size()	{

}

std::vector<std::string> BinarySearchTrees::GetAllAscending()	{

}

std::vector<std::string> BinarySearchTrees::GetAllDescending()	{

}

bool BinarySearchTrees::EmptyTree()	{
	return false;
}

bool BinarySearchTrees::Remove(std::string myValue) {
	return false;
}

//Node Implementation
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

bool Node::SetItem(std::string myValue) {
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