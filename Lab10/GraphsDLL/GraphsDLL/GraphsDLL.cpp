// GraphsDLL.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "GraphsDLL.h"
#include <iostream>
#include <vector>

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

void GraphsDLL::setNextNode(GraphsDLL* node, GraphsDLL* nextNodePtr)
{
	node = nextNodePtr;
}

bool GraphsDLL::AddEdge(std::list<GraphsDLL*> listofN[], int source, int finish) {
	if (listofN[source].size() == 0) {
		GraphsDLL* node = new GraphsDLL(source);
		listofN[source].push_back[node];
	}
	GraphsDLL* nextNode = new GraphsDLL(finish);
	listofN[source].push_back[nextNode];
	node->setNextNode(node, nextNode);
	listofN[finish].push_back[nextNode];
	listofN[finish].push_back[node];
	nextNode->setNextNode(nextNode, node);

	return true;
}

bool GraphsDLL::removeEdge(std::list<GraphsDLL*> listofN[], int source, int finish) {
	
	return false;
}

bool GraphsDLL::hasEdge(std::list<GraphsDLL*> listofN[], int source, int finish) {

	return false;
}

std::list<int> GraphsDLL::outEdges() {

	// return vector
}

std::list<int> GraphsDLL::inEdges() {

	// return vector
}

GraphsDLL::~GraphsDLL() {

}