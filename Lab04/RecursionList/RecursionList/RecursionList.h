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

extern RECURSIONLIST_API string CallSimpleExceptionMethod(int i);
extern RECURSIONLIST_API string SimpleExceptionMethod(int i);


class RECURSIONLIST_API ChessBoard {
public:
	ChessBoard() {
		for (int i = 0; i < 8; i++) {
			col1.push_back(0);
			col2.push_back(0);
			col3.push_back(0);
			col4.push_back(0);
			col5.push_back(0);
			col6.push_back(0);
			col7.push_back(0);
			col8.push_back(0);
		}
	}

	ChessBoard(vector<int> newcol1, vector<int> newcol2, vector<int> newcol3, vector<int> newcol4,
		vector<int> newcol5, vector<int> newcol6, vector<int> newcol7, vector<int> newcol8) {
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

	vector<int> col1;
	vector<int> col2;
	vector<int> col3;
	vector<int> col4;
	vector<int> col5;
	vector<int> col6;
	vector<int> col7;
	vector<int> col8;
};