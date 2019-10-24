// BinarySearchTreesEXE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "../BinarySearchTreesDLL/BinarySearchTreesDLL.h"

using namespace std;

int main()
{
	BinarySearchTrees tree;

	tree.Insert(new Node("Star Wars"));
	tree.Insert(new Node("Star Trek"));
	tree.Insert(new Node("Space Balls"));
	tree.Insert(new Node("Galaxy Quest"));

	vector<string> treeVectorAscending = tree.GetAllAscending();
	vector<string> treeVectorDescending = tree.GetAllDescending();

	cout << "-----Space Tree ascending-----" << endl;

	for (int i = 0; i < treeVectorAscending.size(); ++i) {
		cout << treeVectorAscending[i] << endl;
	}

	cout << endl;
	cout << "-----Space Tree descending-----" << endl;

	for (int i = 0; i < treeVectorDescending.size(); ++i) {
		cout << treeVectorDescending[i] << endl;
	}

	tree.Remove("Star Wars");
	tree.Remove("Star Trek");
	tree.Remove("Space Balls");
	tree.Remove("Galaxy Quest");

	tree.Insert(new Node("Cars"));
	tree.Insert(new Node("Monsters, Inc"));
	tree.Insert(new Node("The Incredibles"));
	tree.Insert(new Node("Wall - E"));

	treeVectorAscending = tree.GetAllAscending();
	treeVectorDescending = tree.GetAllDescending();

	cout << endl;
	cout << "-----Disney Tree ascending-----" << endl;

	for (int i = 0; i < treeVectorAscending.size(); ++i) {
		cout << treeVectorAscending[i] << endl;
	}

	cout << endl;
	cout << "-----Disney Tree descending-----" << endl;

	for (int i = 0; i < treeVectorDescending.size(); ++i) {
		cout << treeVectorDescending[i] << endl;
	}

	tree.Remove("Cars");
	tree.Remove("Monsters, Inc");
	tree.Remove("The Incredibles");
	tree.Remove("Wall - E");

	tree.Insert(new Node("Halloween"));
	tree.Insert(new Node("A Nightmare On Elm Street"));
	tree.Insert(new Node("Hocus Pocus"));
	tree.Insert(new Node("Beetlejuice"));

	treeVectorAscending = tree.GetAllAscending();
	treeVectorDescending = tree.GetAllDescending();

	cout << endl;
	cout << "-----Halloween ascending-----" << endl;

	for (int i = 0; i < treeVectorAscending.size(); ++i) {
		cout << treeVectorAscending[i] << endl;
	}

	cout << endl;
	cout << "-----Halloween descending-----" << endl;

	for (int i = 0; i < treeVectorDescending.size(); ++i) {
		cout << treeVectorDescending[i] << endl;
	}

	Node* beetlejuiceNode = tree.Find("Beetlejuice");

	tree.EmptyTree();
}