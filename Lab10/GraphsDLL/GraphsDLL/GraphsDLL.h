// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the GRAPHSDLL_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// GRAPHSDLL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.

#ifdef GRAPHSDLL_EXPORTS
#define GRAPHSDLL_API __declspec(dllexport)
#else
#define GRAPHSDLL_API __declspec(dllimport)
#endif

#include <vector>;
#include "Node.h"

class GRAPHSDLL_API Graphs {
public:
	/**
	* The default constructor
	*
	* @param
	* @return
	*/
	Graphs() {
		numOfVer = 0;
	}

	/**
	* The constructor for the adjacency list node
	*
	* @param
	* @return
	*/
	Graphs(int vNum) : numOfVer(vNum) {
		for (int i = 0; i< numOfVer; ++i) {
			graph.push_back(new Node(i));
		}
	}

	/**
	* Adds an edge to the adjacency list
	*
	* @param		listofN[]		the adjacency list
					first			vertex you're adding edge to
					second			vertex you're finishing edge to
	* @return						conditional
	*/
	bool AddEdge(int first, int second);

	/**
	* Adds an edge to the adjacency list
	*
	* @param		listofN[]		the adjacency list
					first			vertex you're adding edge to
					second			vertex you're finishing edge to
	* @return						conditional
	*/
	bool addNode(Node* node, int val);
	/**
	* Removes an edge from the adjacency list
	*
	* @param		
	* @return
	*/
	bool removeEdge(int first, int second);

	/**		
	* Removes an edge from the adjacency list
	*
	* @param
	* @return
	*/
	bool removeNode(Node* m_head, int val);

	/**
	* Checks to see if there is an edge between the two points
	*
	* @param		
	* @return
	*/
	bool hasEdge(int first, int second);

	/**
	* Return a list of all integers j such that edge (i,j) 
	*
	* @param		
	* @return
	*/
	std::vector<int> outEdges();

	/**
	* Return a list of all integers j such that edge (j,i) 
	*
	* @param		
	* @return
	*/
	std::vector<int> inEdges();	
	/*int getXVertices();
	int getYVertices();
	int getXEdges();
	int getYEdges();
	*/
	~Graphs() {}
private:
	std::vector<Node*> graph;
	int numOfVer;
};