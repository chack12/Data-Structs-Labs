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
	if (root == nullptr) {
		return 0;
	}
	else {
		return Size(node->GetLeft()) + 1 + Size(node->GetRight());
	}
}

std::vector<std::string> BinarySearchTrees::GetAllAscending()	{
	std::stack<Node*> stack;
	std::vector<std::string> retVal;
	Node* cur = root;
	Node* temp;
	bool notEmpty = true;

	while (notEmpty) {
		if (cur != nullptr) {
			stack.push(cur);
			cur = cur->GetLeft();
		}
		else {
			notEmpty = stack.size();
			if (notEmpty) {
				temp = stack.top();
				retVal.push_back(temp->GetValue());
				cur = temp;
				stack.pop();

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
		if (cur != nullptr) {
			stack.push(cur);
			cur = cur->GetRight();
		}
		else {
			notEmpty = stack.size();
			if (notEmpty) {
				temp = stack.top();
				retVal.push_back(temp->GetValue());
				cur = temp;
				stack.pop();

				cur = cur->GetLeft();
			}
		}
	}

	return retVal;
}

bool BinarySearchTrees::EmptyTree()	{
	delete root;
	return true;
}

Node* BinarySearchTrees::Remove(std::string myValue) {
	Node* prev = new Node();
	Node* cur = new Node();
	Node* left = new Node();
	Node* right = new Node();
	if (root == nullptr) {
		return nullptr;
	}
	// If value is less than root, start traversing left
	else if (root->GetValue().compare(myValue) < 0) {
		prev = root;
		cur = root->GetLeft();
		left = cur->GetLeft();
		right = cur->GetRight();
		while (cur->GetValue().compare(myValue) != 0) {
			// Continue to traverse left
			if (cur->GetValue().compare(myValue) < 0) {
				if (cur->GetLeft() != nullptr) {
					prev = cur;
					cur = cur->GetLeft();
					left = cur->GetLeft();
					right = cur->GetRight();
				}
				else  {
					return nullptr;
				}	
			}
			// Go to the right
			else if (cur->GetValue().compare(myValue) > 0)	{
				if (cur->GetLeft() != nullptr) {
					prev = cur;
					cur = cur->GetRight();
					left = cur->GetLeft();
					right = cur->GetRight();
				}
				else {
					return nullptr;
				}
			}
		}
		if (prev->GetValue().compare(right->GetValue()) <= 0) {
			prev->SetLeft(right);
		}
		else  {
			prev->SetRight(right);
		}
		if (right->GetValue().compare(left->GetValue()) >= 0) {
			right->SetLeft(left);
		}
		else  {
			right->SetRight(left);
		}
	}


	return false;
}

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