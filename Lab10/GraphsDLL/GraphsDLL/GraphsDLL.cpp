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

	for (int i = 0; i < graph.size(); ++i) {
		if (graph[i]->getItem() == first) {
			if (graph[i]->getNext() == nullptr) {
				graph[i]->setNext(new Node(second));
			}
			else {
				addNode(graph[i], second);
			}
			foundFirst = true;
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
				return true;
			}
		}
	}

	return false;
}

bool Graphs::removeEdge(int first, int second) {
	bool foundFirst = false;

	for (int i = 0; i < graph.size(); ++i) {
		if (graph[i]->getItem() == first) {
			if (removeNode(graph[i], second)) {
				foundFirst = true;
			}
			else {
				return false;
			}
			
		}
	}

	for (int i = 0; i < graph.size(); ++i) {
		if (graph[i]->getItem() == second && foundFirst) {
			if (removeNode(graph[i], first)) {
				return true;
			}
			else {
				return false;
			}
		}
	}

	return false;
}

bool Graphs::hasEdge(int first, int second) {
	bool foundFirst = false;
	Node* cur;

	for (int i = 0; i < graph.size(); ++i) {
		if (graph[i]->getItem() == first) {
			cur = graph[i];
			while (true) {
				cur = cur->getNext();
				if (cur == nullptr) {
					return false;
				}
				else if (cur->getItem() == second) {
					foundFirst = true;
					break;
				}
			}
		}
	}

	for (int i = 0; i < graph.size(); ++i) {
		if (graph[i]->getItem() == second && foundFirst) {
			cur = graph[i];
			while (true) {
				cur = cur->getNext();
				if (cur == nullptr) {
					return false;
				}
				else if (cur->getItem() == first) {
					return true;
				}
			}
		}
	}

	return false;
}

std::vector<int> Graphs::outEdges(int val) {
	std::vector<int> temp;
	Node* cur;
	for (int i = 0; i < graph.size(); i++) {
		cur = graph[i];
		while (cur != nullptr) {
			if (cur->getItem() == val) {
				if (cur->getNext() != nullptr) {
					temp.push_back(cur->getNext()->getItem());
				}
			}
			cur = cur->getNext();
		}
	}
	return temp;
}

	// return vector
	

// out is the nodes that a certain node points to
// in is the nodes that point to a certain node

std::vector<int> Graphs::inEdges(int val) {
	std::vector<int> temp;
	Node* cur;
	Node* prev;

	for (int i = 0; i < graph.size(); i++) {
		prev = graph[i];
		cur = graph[i]->getNext();
		while (true) {
			if (cur->getItem() == val) {
				temp.push_back(prev->getItem());
			}
			prev = cur;
			cur = cur->getNext();
			if (cur == nullptr) {
				break;
			}
		}
	}
	
	
	return temp;
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

bool Graphs::print() {
	Node* cur;

	for (int i = 0; i < graph.size(); ++i) { 
        std::cout << "Adjacency list of vertex " << i << std::endl;
		std::cout << "head";

		cur = graph[i];
        while(cur->getNext() != nullptr) {
			cur = cur->getNext();
			std::cout << " -> " << cur->getItem();
		} 
            
        std::cout << std::endl;
	} 

	return true;
}