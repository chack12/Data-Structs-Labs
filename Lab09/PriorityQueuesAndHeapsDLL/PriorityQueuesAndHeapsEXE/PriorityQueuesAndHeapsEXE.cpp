// PriorityQueuesAndHeapsEXE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <vector>
#include <chrono>
#include "../PriorityQueuesAndHeapsDLL/PriorityQueuesAndHeapsDLL.h"

typedef std::chrono::high_resolution_clock Clock;

using namespace std;

int main()
{
	srand(time(0));

	int fiveVector[500];
	int thousVector[1000];
	int twoThousVector[2000];
	int fiveThousVector[5000];

	for (int i = 0; i < 500; ++i) {
		fiveVector[i] = rand() % 501;
	}

	for (int i = 0; i < 1000; ++i) {
		thousVector[i] = rand() % 1001;
	}

	for (int i = 0; i < 2000; ++i) {
		twoThousVector[i] = rand() % 2001;
	}

	for (int i = 0; i < 5000; ++i) {
		fiveThousVector[i] = rand() % 5001;
	}

	//********************************
	//* Priority Queue using a Queue *
	//********************************
	PriorityQueuesWithQueue fivePriorityQueueQ(500);
	PriorityQueuesWithQueue thousPriorityQueueQ(1000);
	PriorityQueuesWithQueue twoThousPriorityQueueQ(2000);
	PriorityQueuesWithQueue fiveThousPriorityQueueQ(5000);

	//Inserting
	cout << "Priory Queue using a Queue" << endl;
    auto t1 = Clock::now();
	for (int i = 0; i < 500; ++i) {
		fivePriorityQueueQ.Insert(fiveVector[i]);
	}
	auto t2 = Clock::now();
	cout << "Insert(size 500): " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	t1 = Clock::now();
	for (int i = 0; i < 1000; ++i) {
		thousPriorityQueueQ.Insert(thousVector[i]);
	}
	t2 = Clock::now();
	cout << "Insert(size 1000): " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	t1 = Clock::now();
	for (int i = 0; i < 2000; ++i) {
		twoThousPriorityQueueQ.Insert(twoThousVector[i]);
	}
	t2 = Clock::now();
	cout << "Insert(size 2000): " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	t1 = Clock::now();
	for (int i = 0; i < 5000; ++i) {
		fiveThousPriorityQueueQ.Insert(fiveThousVector[i]);
	}
	t2 = Clock::now();
	cout << "Insert(size 5000): " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	//Removing
	t1 = Clock::now();
	for (int i = 0; i < 500; ++i) {
		fivePriorityQueueQ.Remove();
	}
	t2 = Clock::now();
	cout << "Remove(size 500): " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	t1 = Clock::now();
	for (int i = 0; i < 1000; ++i) {
		thousPriorityQueueQ.Remove();
	}
	t2 = Clock::now();
	cout << "Remove(size 1000): " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	t1 = Clock::now();
	for (int i = 0; i < 2000; ++i) {
		twoThousPriorityQueueQ.Remove();
	}
	t2 = Clock::now();
	cout << "Remove(size 2000): " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	t1 = Clock::now();
	for (int i = 0; i < 5000; ++i) {
		fiveThousPriorityQueueQ.Remove();
	}
	t2 = Clock::now();
	cout << "Remove(size 5000): " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	cout << endl;

	//*******************************
	//* Priority Queue using a Heap *
	//*******************************
	PriorityQueuesWithHeap fivePriorityQueueH(500);
	PriorityQueuesWithHeap thousPriorityQueueH(1000);
	PriorityQueuesWithHeap twoThousPriorityQueueH(2000);
	PriorityQueuesWithHeap fiveThousPriorityQueueH(5000);

	//Inserting
	cout << "Priory Queue using a Heap" << endl;
    t1 = Clock::now();
	for (int i = 0; i < 500; ++i) {
		fivePriorityQueueH.Insert(fiveVector[i]);
	}
	t2 = Clock::now();
	cout << "Insert(size 500): " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	t1 = Clock::now();
	for (int i = 0; i < 1000; ++i) {
		thousPriorityQueueH.Insert(thousVector[i]);
	}
	t2 = Clock::now();
	cout << "Insert(size 1000): " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	t1 = Clock::now();
	for (int i = 0; i < 2000; ++i) {
		twoThousPriorityQueueH.Insert(twoThousVector[i]);
	}
	t2 = Clock::now();
	cout << "Insert(size 2000): " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	t1 = Clock::now();
	for (int i = 0; i < 5000; ++i) {
		fiveThousPriorityQueueH.Insert(fiveThousVector[i]);
	}
	t2 = Clock::now();
	cout << "Insert(size 5000): " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	//Removing
	t1 = Clock::now();
	for (int i = 0; i < 500; ++i) {
		fivePriorityQueueH.Remove();
	}
	t2 = Clock::now();
	cout << "Remove(size 500): " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	t1 = Clock::now();
	for (int i = 0; i < 1000; ++i) {
		thousPriorityQueueH.Remove();
	}
	t2 = Clock::now();
	cout << "Remove(size 1000): " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	t1 = Clock::now();
	for (int i = 0; i < 2000; ++i) {
		twoThousPriorityQueueH.Remove();
	}
	t2 = Clock::now();
	cout << "Remove(size 2000): " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	t1 = Clock::now();
	for (int i = 0; i < 5000; ++i) {
		fiveThousPriorityQueueH.Remove();
	}
	t2 = Clock::now();
	cout << "Remove(size 5000): " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;
}

