#pragma once

#include <iostream>

#ifdef GRAPHSDLL_EXPORTS
#define GRAPHSDLL_API __declspec(dllexport)
#else
#define GRAPHSDLL_API __declspec(dllimport)
#endif

//Node Class for another lab
class GRAPHSDLL_API Node {
private:
	int m_value;
	Node* m_next;
	
public:
	Node() : m_value(-1), m_next(nullptr) { }
	Node(int val) : m_value(val), m_next(nullptr) { }
	Node(int val, Node* nextNode) : m_value(val), m_next(nextNode) { }
	void setItem(const int& val);
	void setNext(Node* nextNodePtr);
	int getItem() const;
	Node* getNext() const;
	virtual ~Node() {
		std::cout << "Deleting node with value " << m_value << std::endl;
		delete m_next;
	}
};