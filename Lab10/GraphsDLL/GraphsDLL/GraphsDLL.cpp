// GraphsDLL.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "GraphsDLL.h"

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
GraphsDLL::GraphsDLL() {

}

GraphsDLL* newNode(int finish) {
	GraphsDLL* newNode = new GraphsDLL;
	newNode->finish = finish;
	return newNode;
}

bool GraphsDLL::AddEdge(int source, int finish) {
	GraphsDLL 


	return false;
}

bool GraphsDLL::removeEdge(int source, int finish) {
	
	return false;
}

bool GraphsDLL::hasEdge(int source, int finish) {

	return false;
}

int GraphsDLL::getXVertices() {

	return 0;
}

int GraphsDLL::getYVertices() {

	return 0;
}

int GraphsDLL::getXEdges() {

	return 0;
}

int GraphsDLL::getYEdges() {

	return 0;
}

std::vector<int> GraphsDLL::outEdges() {

	// return vector
}

std::vector<int> GraphsDLL::inEdges() {

	// return vector
}

GraphsDLL::~GraphsDLL() {

}