// BinarySearchTreesEXE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "../BinarySearchTreesDLL/BinarySearchTreesDLL.h"

using namespace std;

int main()
{
	BinarySearchTrees tree1;

	tree1.Insert(new Node("Star Wars"));
	tree1.Insert(new Node("Star Trek"));
	tree1.Insert(new Node("Space Balls"));
	tree1.Insert(new Node("Galaxy Quest"));

	BinarySearchTrees tree2;
	tree2.Insert(new Node("Cars"));
	tree2.Insert(new Node("Monsters, Inc"));
	tree2.Insert(new Node("The Incredibles"));
	tree2.Insert(new Node("Wall - E"));

	BinarySearchTrees tree3;
	tree3.Insert(new Node("Halloween"));
	tree3.Insert(new Node("A Nightmare On Elm Street"));
	tree3.Insert(new Node("Hocus Pocus"));
	tree3.Insert(new Node("Beetlejuice"));

	vector<string> tree1VectorAscending = tree1.GetAllAscending();
	vector<string> tree1VectorDescending = tree1.GetAllDescending();

	cout << "-----Tree 1 ascending-----" << endl;

	for (int i = 0; i < tree1VectorAscending.size(); ++i) {
		cout << tree1VectorAscending[i] << endl;
	}

	cout << endl;
	cout << "-----Tree 1 descending-----" << endl;

	for (int i = 0; i < tree1VectorDescending.size(); ++i) {
		cout << tree1VectorDescending[i] << endl;
	}

	vector<string> tree2VectorAscending = tree2.GetAllAscending();
	vector<string> tree2VectorDescending = tree2.GetAllDescending();

	cout << endl;
	cout << "-----Tree 2 ascending-----" << endl;

	for (int i = 0; i < tree2VectorAscending.size(); ++i) {
		cout << tree2VectorAscending[i] << endl;
	}

	cout << endl;
	cout << "-----Tree 2 descending-----" << endl;

	for (int i = 0; i < tree2VectorDescending.size(); ++i) {
		cout << tree2VectorDescending[i] << endl;
	}

	vector<string> tree3VectorAscending = tree3.GetAllAscending();
	vector<string> tree3VectorDescending = tree3.GetAllDescending();

	cout << endl;
	cout << "-----Tree 3 ascending-----" << endl;

	for (int i = 0; i < tree3VectorAscending.size(); ++i) {
		cout << tree3VectorAscending[i] << endl;
	}

	cout << endl;
	cout << "-----Tree 3 descending-----" << endl;

	for (int i = 0; i < tree3VectorDescending.size(); ++i) {
		cout << tree3VectorDescending[i] << endl;
	}
}