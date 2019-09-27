// RecursionList.cpp : Defines the exported functions for the DLL application.
//

#include "header.h"
#include "RecursionList.h"
#include <stack>
#include <stdbool.h>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

bool PalindromeByLoop::isPalindrome(string word) {
	word.erase(remove_if(word.begin(), word.end(), isspace), word.end()); //https://stackoverflow.com/questions/16329358/remove-spaces-from-a-string-in-c

	if (word.length() <= 0) {
		return false;
	}
	else if (word.length() == 1) {
		return true;
	}
	else {
		for (int i = 0; i < word.length(); i++) {
			if (word[i] != word[word.length() - 1 - i]) {
				return false;
			}
		}
	}

	return true;
}

bool PalindromeByRecursion::isPalindrome(string word) {
	word.erase(remove_if(word.begin(), word.end(), isspace), word.end()); //https://stackoverflow.com/questions/16329358/remove-spaces-from-a-string-in-c

	if (word.length() <= 0) {
		return false;
	}
	else if (word.length() == 1) {
		return true;
	}
	else if (word.length() == 2) {
		if (word[0] == word[1]) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if (word[0] == word[word.length() - 1]) {
			word = word.substr(1, word.length() - 2);
			isPalindrome(word);
		}
	}
}

bool PalindromeByStack::isPalindrome(string word) {
	word.erase(remove_if(word.begin(), word.end(), isspace), word.end()); //https://stackoverflow.com/questions/16329358/remove-spaces-from-a-string-in-c

	string reversed = "";

	for (int i = 0; i < word.length(); i++) {
		s.push(word[i]);
	}

	while (!s.empty()) {
		reversed += s.top();
		s.pop();
	}

	if (word.compare(reversed) == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool ChessBoard::Solve(ChessBoard chessBoard, int col) {
	/*
	if (col >= 8) {
		return true;
	}
	
	for (int i = 0; i < 8; ++i) {
		if (CheckSafeQueens(chessBoard, i, col)) {
			m_board[i][col] = 1;

			if (Solve(chessBoard, col + 1) == true)
				return true;

			m_board[i][col] = 0;
		}
	}
	*/

	return false;
}

bool ChessBoard::CheckSafeQueens(ChessBoard chessBoard, int row, int col) {
	//Check horizontal
	//Check vertical
	//Check diagonal

	/*
	int i;
	int j;

	for (i = 0; i < col; ++i) {
		if (m_board[row][i] == 1) {
			return false;
		}
	}

	i = row; j = col;

	while (i >= 0 && j >= 0) {
		if (m_board[i][j] == 1) {
			return false;
		}
		i--; j--;
	}

	i = row; j = col;

	while (i < 8 && j >= 0) {
		if (m_board[i][j] == 1) {
			return false;
		}
		j--; i++;
	}
	*/

	return true;
}

string ChessBoard::ToString() {
	string answer = "";

	for (int i = 0; i < 8; ++i) {
		stringstream ss;
		ss << col1.top();
		ss << col2.top();
		ss << col3.top();
		ss << col4.top();
		ss << col5.top();
		ss << col6.top();
		ss << col7.top();
		ss << col8.top();

		string str = ss.str();
		answer += str + "\n";

		col1.pop();
		col2.pop();
		col3.pop();
		col4.pop();
		col5.pop();
		col6.pop();
		col7.pop();
		col8.pop();
	}

	return answer;
}

extern std::string CallSimpleExceptionMethod(int i)
{
	std::string retVal;

	MyFakeClass* resourceThatNeedsToBeCleanedup = new MyFakeClass();

	delete resourceThatNeedsToBeCleanedup;
	
	retVal = SimpleExceptionMethod(i);

	return retVal;
}

extern string SimpleExceptionMethod(int i) {
	if (i == 1)
	{
		try {
			throw MyException1();
		}
		catch(MyException1 e) {
			return e.what();
		}
	}
	else if (i == 2)
	{
		try {
			throw MyException2();
		}
		catch(MyException2 e) {
			return e.what();
		}

	}
	else if (i == 3)
	{
		try {
			throw MyException3();
		}
		catch (MyException3 e) {
			return e.what();
		}
	}
	else
	{
		return "I did not get an Exception";
	}
}

char const* MyBaseException::what() const throw() {
	return "MyBaseException";
}

char const* MyException1::what() const throw() {
	return "I got Exception 1";
}

char const* MyException2::what() const throw() {
	return "I got Exception 2";
}

char const* MyException3::what() const throw() {
	return "I got Exception 3";
}