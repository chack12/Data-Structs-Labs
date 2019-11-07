// PriorityQueuesAndHeapsDLL.cpp : Defines the exported functions for the DLL.
//

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cmath>
#include "framework.h"
#include "PriorityQueuesAndHeapsDLL.h"


//******************************
//* Priory Queue using a Queue *
//******************************
bool PriorityQueuesWithQueue::Remove() {
	int temp[3];

	for (int i = 0; i < 3; ++i) {
		temp[i] = queue[i];
	}

	for (int i = 1; i < size; ++i) {
		//Move all the values over
		queue[i - 1] = queue[i];

		if (i + 1 == size) {
			for (int i = 0; i < 3; ++i) {
				temp[i] = queue[i];
			}
			
			queue[size - 1] = -1;
			size--;

			for (int i = 0; i < 3; ++i) {
				temp[i] = queue[i];
			}

			return true;
		}
	}

	// If value is not found, returns false
	return false;
}

bool PriorityQueuesWithQueue::Insert(int value) {
	for (int i = 0; i < size; ++i) {
		//Finding an empty space
		if (queue[i] == -1) {
			//Setting the new value in the queue and then sorting the queue
			queue[i] = value;
			std::sort(queue, queue + size);

			return true;
		}
	}

	//Priority queue is full
	return false;
}

std::string PriorityQueuesWithQueue::PrintQueue() {
	std::stringstream ss;

	for (int i = 0; i < size; ++i) {
		ss << queue[i];
		ss << " ";
	}

	std::string temp = ss.str();
	temp.pop_back();

	return temp;
}

//*****************************
//* Priory Queue using a Heap *
//*****************************
bool PriorityQueuesWithHeap::Remove() {
	int count = 0, last = size - 1;

	//Find the last value
	for (int i = 0; i < size; ++i) {
		if (queue[i] == -1) {
			last = i - 1;
		}
	}

	//Put the last value at the top
	queue[0] = queue[last];
	queue[last] = -1;

	//Loop until
	while (true) {
		//If the left child is bigger than the top
		if (queue[2 * count + 1] > queue[count]) {
			std::swap(queue[2 * count + 1], queue[count]);
		}
		//If the right child is bigger than the top
		else if (queue[2 * count + 2] > queue[count]) {
			std::swap(queue[2 * count + 2], queue[count]);
		}
		//The top if the biggest
		else {
			size--;

			return true;
		}

		if (count == size) {
			return false;
		}

		count++;
	}

	return false;
}

bool PriorityQueuesWithHeap::Insert(int value) {
	for (int i = 0; i < size; ++i) {
		//Find the the empty space at the end of the queue
		if (queue[i] == -1) {
			queue[i] = value;

			//While the parent < the new child swap until the parent is biggest
			while (int(floor((i - 1) / 2)) >= 0 && queue[int(floor((i-1)/2))] < queue[i]) {
				std::swap(queue[int(floor((i - 1) / 2))], queue[i]);
				i--;
			}

			//Return true when the parent is bigger than its children
			return true;
		}
	}

	//If the array is full 
	return false;
}

std::string PriorityQueuesWithHeap::PrintHeap() {
	std::stringstream ss;

	for (int i = 0; i < size; ++i) {
		ss << queue[i];
		ss << " ";
	}

	std::string temp = ss.str();
	temp.pop_back();

	return temp;
}
