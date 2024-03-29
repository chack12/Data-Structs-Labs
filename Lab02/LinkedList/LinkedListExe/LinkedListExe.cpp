// LinkedListExe.cpp : Defines the entry point for the console application.
//

#include "..\..\LinkedList\LinkedList\LinkedList.h"


void FreeNodeList(Node * n)
{
	if (n->getNext() == nullptr)
	{
		delete n;
	}
	else
	{
		Node * cur = n->getNext();
		n->setNext(nullptr);
		delete n;
		FreeNodeList(cur);
	}
}

int main()
{
	PointerBasedLinkedList linkedList;

	linkedList.add(1);
	linkedList.add(2);
	linkedList.add(3);

	linkedList.Reverse();

	linkedList.clear();

	Node * head = nullptr;

	Node * cur = nullptr;

	head = new Node(1);

	cur = head;

	Node * temp = new Node(2);

	cur->setNext(temp);

	cur = cur->getNext();

	temp = nullptr;
	temp = new Node(3);

	cur->setNext(temp);

	cur = cur->getNext();

	//Now delete the memory

	FreeNodeList(head);

	

    return 0;
}

