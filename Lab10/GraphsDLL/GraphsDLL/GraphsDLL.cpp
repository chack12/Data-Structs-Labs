// GraphsDLL.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "GraphsDLL.h"
#include "Node.h"
#include <iostream>
#include <vector>

//Graphs Implementation

bool Graphs::AddEdge(int first, int second) {
	bool foundFirst = false;
	Node* cur;

	for (int i = 0; i < graph.size(); ++i) {
		if (graph[i]->getItem() == first) {
			if (graph[i]->getNext() == nullptr) {
				graph[i]->setNext(new Node(second));
				foundFirst = true;
			}
			else {
				addNode(graph[i], second);
			}
		}
	}

	for (int i = 0; i < graph.size(); ++i) {
		if (graph[i]->getItem() == second && foundFirst) {
			if (graph[i]->getNext() == nullptr) {
				graph[i]->setNext(new Node(first));
				return true;
			}
			else {
				addNode(graph[i], first);
			}
		}
	}

	return false;
}

bool Graphs::removeEdge(int first, int second) {
	bool foundFirst = false;
	Node* cur, prev;

	for (int i = 0; i < graph.size(); ++i) {
		if (graph[i]->getItem() == first) {
			removeNode(graph[i], second);
		}
	}

	for (int i = 0; i < graph.size(); ++i) {
		if (graph[i]->getItem() == second && foundFirst) {
			removeNode(graph[i], first);
		}
	}

	return false;
}

bool Graphs::hasEdge(int first, int second) {

	return false;
}

std::vector<int> Graphs::outEdges() {

	// return vector
}

std::vector<int> Graphs::inEdges() {

	// return vector
}

bool Graphs::removeNode(Node* m_head, int val) {
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

bool Graphs::addNode(Node* m_head, int val)
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