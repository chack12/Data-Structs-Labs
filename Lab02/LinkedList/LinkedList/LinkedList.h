// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the LINKEDLIST_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// LINKEDLIST_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef LINKEDLIST_EXPORTS
#define LINKEDLIST_API __declspec(dllexport)
#else
#define LINKEDLIST_API __declspec(dllimport)
#endif

#include <string>

// This class is exported from the LinkedList.dll
class LINKEDLIST_API ILinkedList {
public:

	ILinkedList();

	/** Returns true  if list is empty, otherwise true */
	virtual bool isEmpty() const = 0;
	/** Adds a value to the LinkedList.  Return true if able to, otherwise false */
	virtual bool add(int val) = 0;
	/** Remove a value to the LinkedList.  Return true if able to, otherwise false.
	Will only remove one entry if there are multiple entries with the same value */
	virtual bool remove(int val) = 0;
	/** Remove  all elements from LinkedList */
	virtual void clear() = 0;

	virtual std::string toString() const = 0;

protected:
	int m_count;

};

class LINKEDLIST_API Node
{
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


class LINKEDLIST_API ArrayBasedLinkedList : public ILinkedList
{
public:
	ArrayBasedLinkedList();
	/** Returns true  if list is empty, otherwise true */
	bool isEmpty() const override;
	/** Adds a value to the LinkedList.  Return true if able to, otherwise false */
	bool add(int val) override;
	/** Remove a value to the LinkedList.  Return true if able to, otherwise false.
	Will only remove one entry if there are multiple entries with the same value */
	bool remove(int val) override;
	/** Remove  all elements from LinkedList */
	void clear() override;
	virtual ~ArrayBasedLinkedList() ;
	std::string toString() const override;
private:
	int m_values[10];
};

class LINKEDLIST_API PointerBasedLinkedList : public ILinkedList
{
public:
	PointerBasedLinkedList();
	void Reverse();
	bool isEmpty() const  override;
	/** Adds a value to the LinkedList.  Return true if able to, otherwise false */
	bool add(int val) override;
	/** Remove a value to the LinkedList.  Return true if able to, otherwise false.
	Will only remove one entry if there are multiple entries with the same value */
	bool remove(int val)  override;
	/** Remove  all elements from LinkedList */
	void clear()  override;
	virtual ~PointerBasedLinkedList();
	std::string toString() const override;
private:
	Node * m_head;
};



