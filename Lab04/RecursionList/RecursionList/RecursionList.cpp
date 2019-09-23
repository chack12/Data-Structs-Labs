// RecursionList.cpp : Defines the exported functions for the DLL application.
//

#include "header.h"
#include "RecursionList.h"
#include <stack>
#include <stdbool.h>
#include<iostream>
#include<sstream>
#include<string>

using namespace std;

int FactorialByLoop::CalculateFactorial(int num) {

	int answer = 1;

	while (num != 1) {
		answer = answer * num;
		num--;
	}
	return answer;
}

int FactorialByRecursion::CalculateFactorial(int num) {

	if (num <= 1) { return 1; }

	else {
		return num * CalculateFactorial(num - 1);
	}
}

int FactorialByStack::CalculateFactorial(int num) {

	int answer = 1;

		if (num <= 1) { return 1; }

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
		if(m_board[i][j] == 1) { 
			return false; }
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

extern void SimpleExceptionMethod(int i)
{
	MyException exception;

	if ((i == 1) || (i == -1)) {
		throw exception;
	}
}

char const* MyException::what() const throw() {
	return "MyException";
}

string bool isPaladrome(string myPal) {

}