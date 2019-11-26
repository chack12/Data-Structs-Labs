// HashsEXE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <chrono>
#include "../HashsDLL/HashsDLL.h"

typedef std::chrono::high_resolution_clock Clock;

using namespace std;

int main()
{
	//Randomize the time
	srand(time(0));

	//Create the random arrays of numbers
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

	//100% the size
	HashTable fiveTable100(500);
	HashTable thousTable100(1000);
	HashTable twoThousTable100(2000);
	HashTable fiveThousTable100(5000);

	//150% the size
	HashTable fiveTable150(500 * 1.5);
	HashTable thousTable150(1000 * 1.5);
	HashTable twoThousTable150(2000 * 1.5);
	HashTable fiveThousTable150(5000 * 1.5);

	//200% the size
	HashTable fiveTable200(500 * 2);
	HashTable thousTable200(1000 * 2);
	HashTable twoThousTable200(2000 * 2);
	HashTable fiveThousTable200(5000 * 2);

	//500% the size
	HashTable fiveTable500(500 * 5);
	HashTable thousTable500(1000 * 5);
	HashTable twoThousTable500(2000 * 5);
	HashTable fiveThousTable500(5000 * 5);

	HashTable menu;

	int input, input1, input2;

	cout << "Press 1 to add an item" << endl;
	cout << "Press 2 to remove an item" << endl;
	cout << "Press 3 to get a node" << endl;
	cout << "Press 4 to get the size of the hash table" << endl;
	cout << "Press 5 to run the adding test" << endl;

	cin >> input;

	switch (input) {
	case 1:
		cout << "Enter a value: ";
		cin >> input1;

		cout << "Enter a key: ";
		cin >> input2;

		if (menu.addItem(input1, input2)) {
			cout << "Item added" << endl;
		}
		else {
			cout << "Item not added" << endl;
		}
		break;
	case 2:
		cout << "Enter a key: ";
		cin >> input1;

		if (menu.removeItem(input1)) {
			cout << "Item removed" << endl;
		}
		else {
			cout << "Item not removed" << endl;
		}
		break;
	case 3:
		cout << "Enter a key: ";
		cin >> input1;

		if (menu.getNode(input1) != nullptr) {
			cout << "Node found" << endl;
		}
		else {
			cout << "Node not found" << endl;
		}
		break;
	case 4:
		cout << "The size of the menu hash table is " << menu.getLength() << " nodes long" << endl;
		break;
	case 5:
	{
		cout << "100% The size" << endl;
		auto t1 = Clock::now();
		for (int i = 0; i < 500; ++i) {
			fiveTable100.addItem(fiveVector[i], i + 1);
		}
		auto t2 = Clock::now();
		cout << "500 Nodes: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

		t1 = Clock::now();
		for (int i = 0; i < 1000; ++i) {
			thousTable100.addItem(thousVector[i], i + 1);
		}
		t2 = Clock::now();
		cout << "1000 Nodes: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

		t1 = Clock::now();
		for (int i = 0; i < 2000; ++i) {
			twoThousTable100.addItem(twoThousVector[i], i + 1);
		}
		t2 = Clock::now();
		cout << "2000 Nodes: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

		t1 = Clock::now();
		for (int i = 0; i < 5000; ++i) {
			fiveThousTable100.addItem(fiveThousVector[i], i + 1);
		}
		t2 = Clock::now();
		cout << "5000 Nodes: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

		cout << "150% The size" << endl;
		t1 = Clock::now();
		for (int i = 0; i < 500; ++i) {
			fiveTable150.addItem(fiveVector[i], i + 1);
		}
		t2 = Clock::now();
		cout << "500 Nodes: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

		t1 = Clock::now();
		for (int i = 0; i < 1000; ++i) {
			thousTable150.addItem(thousVector[i], i + 1);
		}
		t2 = Clock::now();
		cout << "1000 Nodes: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

		t1 = Clock::now();
		for (int i = 0; i < 2000; ++i) {
			twoThousTable150.addItem(twoThousVector[i], i + 1);
		}
		t2 = Clock::now();
		cout << "2000 Nodes: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

		t1 = Clock::now();
		for (int i = 0; i < 5000; ++i) {
			fiveThousTable150.addItem(fiveThousVector[i], i + 1);
		}
		t2 = Clock::now();
		cout << "5000 Nodes: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

		cout << "200% The size" << endl;
		t1 = Clock::now();
		for (int i = 0; i < 500; ++i) {
			fiveTable200.addItem(fiveVector[i], i + 1);
		}
		t2 = Clock::now();
		cout << "500 Nodes: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

		t1 = Clock::now();
		for (int i = 0; i < 1000; ++i) {
			thousTable200.addItem(thousVector[i], i + 1);
		}
		t2 = Clock::now();
		cout << "1000 Nodes: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

		t1 = Clock::now();
		for (int i = 0; i < 2000; ++i) {
			twoThousTable200.addItem(twoThousVector[i], i + 1);
		}
		t2 = Clock::now();
		cout << "2000 Nodes: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

		t1 = Clock::now();
		for (int i = 0; i < 5000; ++i) {
			fiveThousTable200.addItem(fiveThousVector[i], i + 1);
		}
		t2 = Clock::now();
		cout << "5000 Nodes: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

		cout << "500% The size" << endl;
		t1 = Clock::now();
		for (int i = 0; i < 500; ++i) {
			fiveTable500.addItem(fiveVector[i], i + 1);
		}
		t2 = Clock::now();
		cout << "500 Nodes: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

		t1 = Clock::now();
		for (int i = 0; i < 1000; ++i) {
			thousTable500.addItem(thousVector[i], i + 1);
		}
		t2 = Clock::now();
		cout << "1000 Nodes: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

		t1 = Clock::now();
		for (int i = 0; i < 2000; ++i) {
			twoThousTable500.addItem(twoThousVector[i], i + 1);
		}
		t2 = Clock::now();
		cout << "2000 Nodes: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

		t1 = Clock::now();
		for (int i = 0; i < 5000; ++i) {
			fiveThousTable500.addItem(fiveThousVector[i], i + 1);
		}
		t2 = Clock::now();
		cout << "5000 Nodes: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;
		break;
	}
	default:
		cout << "Not a valid input" << endl;
	}

	
}
