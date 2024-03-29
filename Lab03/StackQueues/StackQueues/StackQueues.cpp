// StackQueues.cpp : Defines the exported functions for the DLL application.
//

#include "header.h"
#include "StackQueues.h"
#include <iostream>



//ArrayBased Stack

/**
 * The constrcutor for the array based stack
 *
 * @param
 * @return
*/
ArrayBasedStack::ArrayBasedStack() {
	//Fill the stack with -1's
	for (int i = 0; i < 4; i++) {
		stack[i] = -1;
	}
}

/**
 * The destructor for the array based stack
 *
 * @param
 * @return
*/
ArrayBasedStack::~ArrayBasedStack() {

}

/**
 * Determines if the stack is empty or not
 *
 * @param
 * @return true if the stack is empty, false if the stack has values
*/
bool ArrayBasedStack::isEmpty() const {
	if (stack[0] == -1) {
		return true;
	}
	else {
		return false;
	}
}

/**
 * Adds an element to the top of the stack
 *
 * @param int you want to push
 * @return true if the operation succeeded, false if it failed
*/
bool ArrayBasedStack::push(int val) {
	//Start at the end of the stack and go up
	for (int i = 0; i < 4; i++) {
		//If there is an empty spot in the stack put in inputted value there
		if (stack[i] == -1) {
			stack[i] = val;
			return true;
		}
	}

	std::cout << "The stack is full" << std::endl;
	return false;
}

/**
 * Removes an element from the top of the stack
 *
 * @param
 * @return true if the operation succeeded, false if it failed
*/
bool ArrayBasedStack::pop() {
	//Start at the top of the stack and go down
	for (int i = 3; i >= 0; i--) {
		//If there is an item at the top remove it
		if (stack[i] != -1) {
			stack[i] = -1;
			return true;
		}
	}

	std::cout << "The stack is empty" << std::endl;
	return false;
}

/**
 * Returns the value at the top of the stack
 *
 * @param 
 * @return value at the top of stack
*/
int ArrayBasedStack::peek()
{
	//Start at the top of the stack and go up
	for (int i = 3; i >= 0; i--) {
		//If there is a value return it
		if (stack[i] != -1) {
			return stack[i];
		}
	}

	std::cout << "The stack is empty" << std::endl;
	return -1;
}

/**
 * Returns the length of the stack
 *
 * @param
 * @return length of the stack
*/
int ArrayBasedStack::length() {
	int count = 0;
	
	for (int i = 0; i < 4; i++) {
		//If its not equal to -1 increment the counter
		if (stack[i] != -1) {
			count++;
		}
	}

	return count;
}

/**
 * Removes all values from the stack
 *
 * @param 
 * @return 
*/
void ArrayBasedStack::empty() {
	//Fill the stack with -1's
	for (int i = 0; i < 4; i++) {
		stack[i] = -1;
	}
}

/**
* Displays the contents of stack
*
* @param
* @return outputs the content of the stack
*/
void ArrayBasedStack::display() {
	//Display everything in the stack
	for (int i = 3; i >= 0; i--) {
		std::cout << stack[i] << std::endl;
	}
}



//ArrayBasedQueue

/**
 * The constructor for the array based queue
 *
 * @param
 * @return
*/
ArrayBasedQueue::ArrayBasedQueue() {
	//Fill the queue with blank strings
	for (int i = 0; i < 100; i++) {
		queue[i] = "";
	}
}

/**
 * The decontructor for the array based queue
 *
 * @param
 * @return
*/
ArrayBasedQueue::~ArrayBasedQueue() {
	
}

/**
 * Determines if the queue is empty or not
 *
 * @param
 * @return true if the operation succeeded, false if it failed
*/
bool ArrayBasedQueue::isEmpty() const {
	//If the front is empty then the queue is empty
	if (queue[0] == "") {
		return true;
	}
	else {
		return false;
	}
}

/**
 * Adds a value to the end of the queue
 *
 * @param string you want to add to the queue
 * @return true if the operation succeeded, false if it failed
*/
bool ArrayBasedQueue::enQueue(std::string val) {
	//Start at the front of the queue
	for (int i = 0; i < 100; i++) {
		//Find an empty spot in the queue and put the value in it
		if (queue[i] == "") {
			queue[i] = val;
			return true;
		}
	}

	return false;
}

/**
 * Removes a value from the front of the queue
 *
 * @param
 * @return true if the operation succeeded, false if it failed
*/
bool ArrayBasedQueue::deQueue() {
	std::string queueCopy[100];
	
	if (!isEmpty()) {
		//Copy all the values from queue except the front of the queue into a temp
		for (int i = 1; i < 100; i++) {
			queueCopy[i - 1] = queue[i];
		}

		//Copy the values back into queue
		for (int i = 0; i < 100; i++) {
			queue[i] = queueCopy[i];
		}

		return true;
	}
	else {
		return false;
	}
}

/**
 * Returns the value of the thing that is at the front of the queue
 *
 * @param
 * @return the value at the front of the queue
*/
std::string ArrayBasedQueue::peekFront()
{
	if (this->isEmpty())
	{
		throw "ADT is emtpy";
	}
	else
	{
		//Return the first value of the queue
		return queue[0];
	}
}

/**
 * Prints the whole queue in a string
 *
 * @param
 * @return 
*/
std::string ArrayBasedQueue::display() {
	std::string queueString = "";

	//Build a string of everything in the queue (for Tower of Hannoi game)
	for (int i = 0; i < 100; i++) {
		queueString += queue[i] + " ";
	}

	return queueString;
}
