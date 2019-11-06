// PriorityQueuesAndHeapsEXE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <vector>
#include <chrono>

typedef std::chrono::high_resolution_clock Clock;

using namespace std;

int main()
{
	srand(time(0));

	vector<int> fiveVector;
	vector<int> thousVector;
	vector<int> twoThousVector;
	vector<int> fiveThousVector;

	for (int i = 0; i < 500; ++i) {
		fiveVector.push_back(rand() % 501);
	}

	for (int i = 0; i < 1000; ++i) {
		thousVector.push_back(rand() % 1001);
	}

	for (int i = 0; i < 2000; ++i) {
		twoThousVector.push_back(rand() % 2001);
	}

	for (int i = 0; i < 5000; ++i) {
		fiveThousVector.push_back(rand() % 5001);
	}

	//******************************
	//* Priory Queue using a Queue *
	//******************************
	cout << "Priory Queue using a Queue" << endl;
    auto t1 = Clock::now();
	for (int i = 0; i < 500; ++i) {
		//something.Insert(fiveVector[i]);
	}
	auto t2 = Clock::now();
	cout << "Array size of 500 took: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	t1 = Clock::now();
	for (int i = 0; i < 1000; ++i) {
		//something.Insert(thousVector[i]);
	}
	t2 = Clock::now();
	cout << "Array size of 1000 took: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	t1 = Clock::now();
	for (int i = 0; i < 2000; ++i) {
		//something.Insert(twoThousVector[i]);
	}
	t2 = Clock::now();
	cout << "Array size of 2000 took: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	t1 = Clock::now();
	for (int i = 0; i < 5000; ++i) {
		//something.Insert(fiveThousVector[i]);
	}
	t2 = Clock::now();
	cout << "Array size of 5000 took: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	//*****************************
	//* Priory Queue using a Heap *
	//*****************************
	cout << "Priory Queue using a Heap" << endl;
    auto t1 = Clock::now();
	for (int i = 0; i < 500; ++i) {
		//something.Insert(fiveVector[i]);
	}
	auto t2 = Clock::now();
	cout << "Array size of 500 took: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	t1 = Clock::now();
	for (int i = 0; i < 1000; ++i) {
		//something.Insert(thousVector[i]);
	}
	t2 = Clock::now();
	cout << "Array size of 1000 took: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	t1 = Clock::now();
	for (int i = 0; i < 2000; ++i) {
		//something.Insert(twoThousVector[i]);
	}
	t2 = Clock::now();
	cout << "Array size of 2000 took: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	t1 = Clock::now();
	for (int i = 0; i < 5000; ++i) {
		//something.Insert(fiveThousVector[i]);
	}
	t2 = Clock::now();
	cout << "Array size of 5000 took: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;
}

