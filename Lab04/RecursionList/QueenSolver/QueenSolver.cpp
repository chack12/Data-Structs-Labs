// QueenSolver.cpp : Defines the entry point for the console application.
//

#include "..\RecursionList\RecursionList.h"
#include <iostream>
#include <string>


int main()
{
	ChessBoard chessBoard;
	int board[8][8];
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			board[i][j] = 0;
		}
	}
	chessBoard.Solve(chessBoard,0);
	std::string output = chessBoard.ToString();
	std::cout << output;
	return 0;
}

