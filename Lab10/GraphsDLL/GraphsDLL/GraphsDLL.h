// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the GRAPHSDLL_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// GRAPHSDLL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.

#include <vector>;
#ifdef GRAPHSDLL_EXPORTS
#define GRAPHSDLL_API __declspec(dllexport)
#else
#define GRAPHSDLL_API __declspec(dllimport)
#endif

class GRAPHSDLL_API GraphsDLL {
public:
	GraphsDLL() {}
	GraphsDLL* newNode(int finish);
	bool AddEdge(int source, int finish);
	bool removeEdge(int source, int finish);
	bool hasEdge(int source, int finish);
	std::vector<int> outEdges();
	std::vector<int> inEdges();	
	int getXVertices();
	int getYVertices();
	int getXEdges();
	int getYEdges();
	~GraphsDLL() {}
private:
	int start;
	int finish;
	GraphsDLL* node;
	std::vector<GraphsDLL*> vectorofNodes;

};

class GRAPHSDLL_API Node {
private:
	int m_value;
	Node * m_next;

public:
	Node();
	Node(int val);
	Node(int val, Node * nextNode);
	void setItem(const int& val);
	void setNext(Node* nextNodePtr);
	int getItem() const;
	Node * getNext() const;
	virtual ~Node();
	
};