// GraphsEXE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "../GraphsDLL/GraphsDLL.h"

using namespace std;

int main()
{
	int commandInput, input1, input2;
	vector<int> temp;
	Graphs graph;
	bool runFlag = true;

	while (runFlag) {
		cout << "Press 1 to add an edge to graph" << endl;
		cout << "Press 2 remove an edge from graph" << endl;
		cout << "Press 3 Find an edge in the graph" << endl;
		cout << "Press 4 Find the out edges of a vertices" << endl;
		cout << "Press 5 Find the in edges of a vertices" << endl;
		cout << "Press 6 To Print out Adjacency Matrix" << endl;
		cout << "Press 7 to quit" << endl;
		cin >> commandInput;

		switch (commandInput) {
			case 1:
				cout << "Enter the first node value: ";
				cin >> input1;
				cout << "Enter the second node value: ";
				cin >> input2;
				
				if (graph.AddEdge(input1, input2)) {
					cout << "Edge added" << endl;	
				}
				else {
					cout << "Unable to add edge" << endl;
				}
				
				
				break;
			case 2:
				cout << "Enter the first node value: ";
				cin >> input1;
				cout << "Enter the second node value: ";
				cin >> input2;

				if (graph.removeEdge(input1, input2)) {
					cout << "Edge removed" << endl;
				}
				else {
					cout << "No edge exists" << endl;
				}
				
				break;
			case 3:
				cout << "Enter the first node value: ";
				cin >> input1;
				cout << "Enter the second node value: ";
				cin >> input2;

				if (graph.hasEdge(input1, input2)) {
					cout << "There is an edge" << endl;
				}
				else {
					cout << "There is not an edge" << endl;
				}

				break;
			case 4:
				cout << "Enter the out edge value: ";
				cin >> input1;
				
				temp = graph.outEdges(input1);

				if (temp.size() > 0) {
					for (int i = 0; i < temp.size(); ++i) {
						cout << temp[i] << " " << endl;
					}
				}
				else {
					cout << "Out edge failed" << endl;
				}

				break;
			case 5:
				cout << "Enter the in edge value: ";
				cin >> input1;

				temp = graph.inEdges(input1);

				if (temp.size() > 0) {
					for (int i = 0; i < temp.size(); ++i) {
						cout << temp[i] + " " << endl;
					}
				}
				else {
					cout << "In edge failed" << endl;
				}

				break;
			case 6:
				graph.print();

				break;
			case 7:
				runFlag = false;
				break;
		}
	}
	
}
