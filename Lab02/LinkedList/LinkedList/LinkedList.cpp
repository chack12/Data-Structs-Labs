// LinkedList.cpp : Defines the exported functions for the DLL application.
//

#include "header.h"
#include "LinkedList.h"
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <sstream>

using namespace std;

ILinkedList::ILinkedList() : m_count(0)
{

}

Node::Node() : m_value(-1), m_next(nullptr)
{

}
Node::Node(int val) : m_value(val), m_next(nullptr)
{

}
Node::Node(int val, Node * nextNode) : m_value(val), m_next(nextNode)
{

}
void Node::setItem(const int& val)
{
	m_value = val;
}
void Node::setNext(Node* nextNodePtr)
{
	m_next = nextNodePtr;
}
int Node::getItem() const
{
	return m_value;
}
Node * Node::getNext() const
{
	return m_next;
}
Node::~Node()
{
	std::cout << "Deleting node with value " << m_value << std::endl;
	delete m_next;
}

PointerBasedLinkedList::PointerBasedLinkedList() : ILinkedList(), m_head(nullptr)
{

}
/** Returns true  if list is empty, otherwise true */
bool PointerBasedLinkedList::isEmpty() const
{
	//If the head is pointing to nothing then the linked list is empty
	if (m_head == nullptr) {
		return true;
	}
	return false;
}

void PointerBasedLinkedList::Reverse() {
	Node* cur = m_head;
	int count = 0, count2 = 0;
	while (cur->getNext() != nullptr) {
		count++;
		cur = cur->getNext();
	}
	count2 = count;
	for (int i = 0; i < count; ++i) {
		cur = m_head;
		for (int j = 0; j < count2; ++j) {
			cur = cur->getNext();
		}
		std::cout << cur->getItem() << std::endl;
	}

}

/** Adds a value to the LinkedList.  Return true if able to, otherwise false */
bool PointerBasedLinkedList::add(int val)
{
	//Create a new node with the inputted value and point it to nullptr (because it is the end)
	Node* temp = new Node(val);
	temp->setNext(nullptr);

	Node* cur = new Node();
	cur = m_head;

	//If the linked list is empty make the new value the head node
	if (cur == nullptr) {
		m_head = temp;

		return true;
	}
	else {
		//Find the last node
		while (cur->getNext() != nullptr) {
			cur = cur->getNext();
		}

		//Point the last node to the new node that was created
		cur->setNext(temp);

		return true;
	}

	return false;
}
/** Remove a value to the LinkedList.  Return true if able to, otherwise false.
Will only remove one entry if there are multiple entries with the same value */
bool PointerBasedLinkedList::remove(int val)
{
	Node* cur = new Node();
	Node* prev = new Node();
	cur = m_head;
	prev = m_head;

	//If the head contains the value you want to remove
	if (m_head->getItem() == val) {
		//There is nothing after the head so make the head point to nullptr
		if (m_head->getNext() == nullptr) {
			m_head = nullptr;
		}
		else {
			//Move the head over 1 node
			m_head = m_head->getNext();
		}
		return true;
	}
	else {
		//Find the node that contains the value
		while (cur->getItem() != val) {
			cur = cur->getNext();
			
			if (cur == nullptr) {
				return false;
			}

			if (cur->getItem() == val) {
				//If the values node is at the end of the list set the node before the one you want to remove to nullptr making that the new last node
				if (cur->getNext() == nullptr) {
					prev->setNext(nullptr);
				}
				else {
					//Set the next node of the node before the one you want to remove to the node after the one you want to remove
					prev->setNext(cur->getNext());
				}
				return true;
			}

			prev = prev->getNext();
		}
	}

	return false;
}

/** Remove  all elements from LinkedList */
void PointerBasedLinkedList::clear()
{
	delete m_head;
	m_head = NULL;
}
PointerBasedLinkedList::~PointerBasedLinkedList()
{
	clear();
}

std::string PointerBasedLinkedList::toString() const
{
	string str = "";

	Node* cur = new Node();
	cur = m_head;

	//If there is nothing in the linked list return ""
	if (cur == nullptr) {
		return str;
	}
	else {
		//Keep adding the items to a string with a space in between until you get to end
		while (cur != nullptr) {
			str += std::to_string(cur->getItem()) + " ";

			cur = cur->getNext();
		}
	}

	//Remove the extra space at the end
	str.pop_back();

	return str;
}

ArrayBasedLinkedList::ArrayBasedLinkedList() : ILinkedList()
{
	for (int i = 0; i < 10; ++i) {
		m_values[i] = -1;
	}
}

bool ArrayBasedLinkedList::isEmpty() const
{
	//If the array doesn't contain all -1 then it is empty
	for (int i = 0; i < 10; i++) {
		if (m_values[i] != -1) {
			return false;
		}
	}

	return true;
}
bool ArrayBasedLinkedList::add(int val)
{
	//Find where the first -1 is and then put the value at that place
	for (int i = 0; i < 10; i++) {
		if (m_values[i] == -1) {
			m_values[i] = val;
			return true;
		}
	}
	return false;
}
bool ArrayBasedLinkedList::remove(int val)
{
	if (!isEmpty()) {
		//If the value you want to remove is found replace it with a -1
		for (int i = 0; i < 10; i++) {
			if (m_values[i] == val) {
				m_values[i] = -1;
				return true;
			}
		}
	}
	return false;
}
void ArrayBasedLinkedList::clear()
{
	//Set all values to -1
	for (int i = 0; i < 10; ++i) {
		m_values[i] = -1;
	}
}
ArrayBasedLinkedList::~ArrayBasedLinkedList()
{

}

std::string ArrayBasedLinkedList::toString() const
{
	string str = "";
	
	//If the array is full of -1s return an empty string
	if (isEmpty()) {
		return str;
	}
	else {
		for (int i = 0; i < 10; i++) {
			//Add all the values to a string with a space after it as long as it isn't a -1
			if (m_values[i] != -1) {
				str += std::to_string(m_values[i]) + " ";
			}
		}
	}

	//Get rid of the extra space
	str.pop_back();

	return str;
}
