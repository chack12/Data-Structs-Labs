// StackQueues.cpp : Defines the exported functions for the DLL application.
//

#include "header.h"
#include "StackQueues.h"

std::string ArrayBasedStack::peek()
{
	if (this->isEmpty())
	{
		throw "ADT is emtpy";
	}
	else
	{
		return stack[0];
	}
}

std::string ArrayBasedStack::peek()
{
	if (this->isEmpty()) {
		throw "ADT is empty";
	}
	else
	{
		return queue[0];
	}
}

std::string ArrayBasedQueue::peekFront()
{
	if (this->isEmpty())
	{
		throw "ADT is emtpy";
	}
	else
	{
		//TODO
	}


}


bool ArrayBasedQueue::isEmpty(std::string val) const
{
	if (queue[0] == "")
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool ArrayBasedQueue::enQueue(std::string val) {

	for (int i = 0; i < 100; i++) {
		if (queue[i] == "") {
			queue[i] == val;

		}

	}


}

