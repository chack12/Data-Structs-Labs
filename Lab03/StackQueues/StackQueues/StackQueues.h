// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the STACKQUEUES_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// STACKQUEUES_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef STACKQUEUES_EXPORTS
#define STACKQUEUES_API __declspec(dllexport)
#else
#define STACKQUEUES_API __declspec(dllimport)
#endif

#include <string>

class STACKQUEUES_API IStack {
public:
	virtual bool isEmpty() const = 0;
	virtual bool push(int val) = 0;
	virtual bool pop() = 0;
	//If the ADT is empty throw an exception indicating this
	virtual int peek() = 0;
private:

};



class STACKQUEUES_API ArrayBasedStack : IStack {
public:
	/**
	* The constrcutor for the array based stack
	*
	* @param
	* @return
	*/
	ArrayBasedStack(void);
	/**
	* The destructor for the array based stack
	*
	* @param
	* @return
	*/
	virtual ~ArrayBasedStack();
	/**
	* Determines if the stack is empty or not
	*
	* @param
	* @return true if the stack is empty, false if the stack has values
	*/
	bool isEmpty() const override;
	/**
	* Adds an element to the top of the stack
	*
	* @param int you want to push
	* @return true if the operation succeeded, false if it failed
	*/
	bool push(int val) override;
	/**
	* Removes an element from the top of the stack
	*
	* @param
	* @return true if the operation succeeded, false if it failed
	*/
	bool pop() override;
	/**
	* Returns the value at the top of the stack
	*
	* @param
	* @return value at the top of stack
	*/
	int peek() override;
	/**
	* Returns the length of the stack
	*
	* @param
	* @return length of the stack
	*/
	int length();
	/**
	* Removes all values from the stack
	*
	* @param
	* @return
	*/
	void empty();
	/**
	* Displays the contents of stack
	*
	* @param
	* @return outputs the content of the stack
	*/
	void display();
private:
	int stack[4];
};


class STACKQUEUES_API IQueue {
public:
	virtual bool isEmpty() const = 0;
	virtual bool enQueue(std::string val) = 0;
	virtual bool deQueue() = 0;
	//If the ADT is empty throw an exception indicating this
	virtual std::string peekFront() = 0;
private:

};



class STACKQUEUES_API ArrayBasedQueue : IQueue {
public:
	/**
	* The constructor for the array based queue
	*
	* @param
	* @return
	*/
	ArrayBasedQueue(void);
	/**
	* The decontructor for the array based queue
	*
	* @param
	* @return
	*/
	virtual ~ArrayBasedQueue();
	/**
	* Determines if the queue is empty or not
	*
	* @param
	* @return true if the operation succeeded, false if it failed
	*/
	bool isEmpty() const override;
	/**
	* Adds a value to the end of the queue
	*
	* @param string you want to add to the queue
	* @return true if the operation succeeded, false if it failed
	*/
	bool enQueue(std::string val) override;
	/**
	* Removes a value from the front of the queue
	*
	* @param
	* @return true if the operation succeeded, false if it failed
	*/
	bool deQueue() override;
	/**
	* Returns the value of the thing that is at the front of the queue
	*
	* @param
	* @return the value at the front of the queue
	*/
	std::string peekFront() override;
	/**
	* Prints the whole queue in a string
	*
	* @param
	* @return
	*/
	std::string display();
private:
	std::string queue[100];
};










