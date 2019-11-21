#include "framework.h"
#include "Node.h"

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

Node* Node::getNext() const
{
	return m_next;
}