// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the GRAPHSDLL_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// GRAPHSDLL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.

#include <list>;
#ifdef GRAPHSDLL_EXPORTS
#define GRAPHSDLL_API __declspec(dllexport)
#else
#define GRAPHSDLL_API __declspec(dllimport)
#endif

class GRAPHSDLL_API GraphsDLL {
public:
	/**
	* The default constructor
	*
	* @param
	* @return
	*/
	GraphsDLL() {}

	/**
	* The constructor for the adjacency list node
	*
	* @param
	* @return
	*/
	GraphsDLL(int val) : value(val), node(nullptr) {}

	/**
	* The constructor for the adjacency list node
	*
	* @param
	* @return
	*/
	GraphsDLL(int val, GraphsDLL* nextNode) : value(val), node(nextNode) {}

	/**
	* Sets the next node
	*
	* @param		
	* @return				
	*/
	void setNextNode(GraphsDLL* node, GraphsDLL* nextNodePtr);

	/**
	* Adds an edge to the adjacency list
	*
	* @param		listofN[]		the adjacency list
					source			vertex you're adding edge to
					finish			vertex you're finishing edge to
	* @return						conditional
	*/
	bool AddEdge(std::list<GraphsDLL*> listofN[], int source, int finish);

	/**
	* Removes an edge from the adjacency list
	*
	* @param		
	* @return
	*/
	bool removeEdge(std::list<GraphsDLL*> listofN[], int source, int finish);

	/**
	* Checks to see if there is an edge between the two points
	*
	* @param		
	* @return
	*/
	bool hasEdge(std::list<GraphsDLL*> listofN[], int source, int finish);

	/**
	* Return a list of all integers j such that edge (i,j) 
	*
	* @param		
	* @return
	*/
	std::list<int> outEdges();

	/**
	* Return a list of all integers j such that edge (j,i) 
	*
	* @param		
	* @return
	*/
	std::list<int> inEdges();	
	/*int getXVertices();
	int getYVertices();
	int getXEdges();
	int getYEdges();
	*/
	~GraphsDLL() {}
private:
	GraphsDLL* node;
	std::list<GraphsDLL*> listofN;
	int value;
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