// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the RECURSIONLIST_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// RECURSIONLIST_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef RECURSIONLIST_EXPORTS
#define RECURSIONLIST_API __declspec(dllexport)
#else
#define RECURSIONLIST_API __declspec(dllimport)
#endif
#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class RECURSIONLIST_API IPalindromeComputer
{
public:
	IPalindromeComputer() {};
	virtual bool isPalindrome(string word) = 0;
};

class RECURSIONLIST_API PalindromeByLoop : public IPalindromeComputer
{
public:
	PalindromeByLoop() {};
	bool isPalindrome(string word);
};

class RECURSIONLIST_API PalindromeByRecursion : public IPalindromeComputer
{
public:
	PalindromeByRecursion() {};
	bool isPalindrome(string word);
};

class RECURSIONLIST_API PalindromeByStack : public IPalindromeComputer
{
public:
	PalindromeByStack() {};
	bool isPalindrome(string word);

private:
	stack<char> s;
};

class RECURSIONLIST_API MyFakeClass
{
public:
	MyFakeClass() {}
	~MyFakeClass() { 
		std::cout << "Destructor for MyFakeClass was called" << std::endl; 
	}

};

class RECURSIONLIST_API MyBaseException : public std::exception
{
public:
	virtual char const* what() const throw();
};

class RECURSIONLIST_API MyException1 : MyBaseException
{
public:
	virtual char const* what() const throw();
};


class RECURSIONLIST_API MyException2 : MyBaseException
{
public:
	virtual char const* what() const throw();
};

class RECURSIONLIST_API MyException3 : MyBaseException
{
public:
	virtual char const* what() const throw();
};

extern RECURSIONLIST_API std::string CallSimpleExceptionMethod(int i);
extern RECURSIONLIST_API void SimpleExceptionMethod(int i);


class RECURSIONLIST_API ChessBoard {
public:
	ChessBoard() {
		for (int i = 0; i < 8; i++) {
			col1.push(0);
			col2.push(0);
			col3.push(0);
			col4.push(0);
			col5.push(0);
			col6.push(0);
			col7.push(0);
			col8.push(0);
		}
	}

	ChessBoard(stack<int> newcol1, stack<int> newcol2, stack<int> newcol3, stack<int> newcol4, 
		stack<int> newcol5, stack<int> newcol6, stack<int> newcol7, stack<int> newcol8) {
		newcol1.swap(col1);
		newcol2.swap(col2);
		newcol3.swap(col3);
		newcol4.swap(col4);
		newcol5.swap(col5);
		newcol6.swap(col6);
		newcol7.swap(col7);
		newcol8.swap(col8);
	}

	std::string ToString();
	
	bool Solve(ChessBoard chessboard, int col);

private:
    bool CheckSafeQueens(ChessBoard chessBoard, int i, int col);

	stack<int> col1;
	stack<int> col2;
	stack<int> col3;
	stack<int> col4;
	stack<int> col5;
	stack<int> col6;
	stack<int> col7;
	stack<int> col8;
};