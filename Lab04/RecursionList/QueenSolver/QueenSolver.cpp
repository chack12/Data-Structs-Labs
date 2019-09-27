// QueenSolver.cpp : Defines the entry point for the console application.
//

#include "..\RecursionList\RecursionList.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
	ChessBoard chessBoard;

	chessBoard.Solve(chessBoard,0);
	string output = chessBoard.ToString();
	cout << output;

	return 0;
}

