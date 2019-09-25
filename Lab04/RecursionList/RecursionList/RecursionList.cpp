// RecursionList.cpp : Defines the exported functions for the DLL application.
//

#include "header.h"
#include "RecursionList.h"
#include <stack>
#include <stdbool.h>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

bool PalindromeByLoop::isPalindrome(string word) {
	for (int i = 0; i < word.length(); i++) {
		if (word[i] != word[word.length() - 1 - i]) {
			return false;
		}
	}

	return true;
}

bool PalindromeByRecursion::isPalindrome(string word) {
	if (word.length() >= 0) {
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

	return false;
}

bool ChessBoard::CheckSafeQueens(ChessBoard chessBoard, int row, int col) {
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

	return true;
}

string ChessBoard::ToString() {
	string answer = "";

	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			int temp = m_board[i][j];
			stringstream ss;
			ss << temp;
			string str = ss.str();
			answer = answer + str;
		}
		answer = answer + "\n";
	}

	return answer;
}

extern void SimpleExceptionMethod(int i) {
	MyException exception;

	if ((i == 1) || (i == -1)) {
		throw exception;
	}
}

char const* MyException::what() const throw() {
	return "MyException";
}

//Factorial Stuff
int FactorialByLoop::CalculateFactorial(int num) {
	int answer = 1;

	while (num != 1) {
		answer = answer * num;
		num--;
	}

	return answer;
}

int FactorialByRecursion::CalculateFactorial(int num) {
	if (num <= 1) {
		return 1;
	}

	else {
		return num * CalculateFactorial(num - 1);
	}
}

int FactorialByStack::CalculateFactorial(int num) {
	int answer = 1;

		if (num <= 1) {
			return 1;
		}

		while (num > 1) {
			s.push(num);
			num--;
		}
		while(!s.empty()) {
			answer = answer * s.top();
			s.pop();
		}
		return answer;
}