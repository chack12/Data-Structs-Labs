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
	// Removes spaces from word
	word.erase(remove_if(word.begin(), word.end(), isspace), word.end()); //https://stackoverflow.com/questions/16329358/remove-spaces-from-a-string-in-c
	// Checks to make sure the word isn't empty
	if (word.length() <= 0) {
		return false;
	}
	// Checks to see if the word is only 1 letter, therefore it is a palindrome
	else if (word.length() == 1) {
		return true;
	}
	// Checks if word is not a palindrome
	else {
		for (int i = 0; i < word.length(); i++) {
			if (word[i] != word[word.length() - 1 - i]) {
				return false;
			}
		}
	}
	// If word gets through for loop, then it is a palindrome and returns true
	return true;
}

bool PalindromeByRecursion::isPalindrome(string word) {
	// Removes spaces from word
	word.erase(remove_if(word.begin(), word.end(), isspace), word.end()); //https://stackoverflow.com/questions/16329358/remove-spaces-from-a-string-in-c
	// Checks to make sure the word isn't empty
	if (word.length() <= 0) {
		return false;
	}
	// Checks to see if the word is only 1 letter, therefore it is a palindrome
	else if (word.length() == 1) {
		return true;
	}
	// Checks to see if the word is two letter, if they are the same then it is a palindrome
	else if (word.length() == 2) {
		if (word[0] == word[1]) {
			return true;
		}
		else {
			return false;
		}
	}
	// Checks the first and last letter, if same removes them and recursively calls the function
	else {
		if (word[0] == word[word.length() - 1]) {
			word = word.substr(1, word.length() - 2);
			isPalindrome(word);
		}
		else
		{
			// If the letters aren't the same, not a palindrome
			return false;
		}
	}
}

bool PalindromeByStack::isPalindrome(string word) {
	// Removes spaces from word
	word.erase(remove_if(word.begin(), word.end(), isspace), word.end()); //https://stackoverflow.com/questions/16329358/remove-spaces-from-a-string-in-c

	// Creates a string 
	string reversed = "";

	// Pushes each letter into the stack
	for (int i = 0; i < word.length(); i++) {
		s.push(word[i]);
	}

	// While the stack isn't empty, will add the top letter to the reverse string then pop off that from the stack
	while (!s.empty()) {
		reversed += s.top();
		s.pop();
	}

	// If the word is equal to the reversed word, then the word is a palindrome
	if (word.compare(reversed) == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool ChessBoard::Solve(ChessBoard chessBoard, int col) {
	// If col >= 8 then the solution is solved
	if (col >= 8) {
		return true;
	}
	
	// If the queen is safe, the switch statement will put the queen in the correct spot
	for (int i = 7; i >= 0; --i) {
		if (CheckSafeQueens(chessBoard, i, col)) {
			switch (col) {
			case 0:
				col1[i] = 1;
				break;
			case 1:
				col2[i] = 1;
				break;
			case 2:
				col3[i] = 1;
				break;
			case 3:
				col4[i] = 1;
				break;
			case 4:
				col5[i] = 1;
				break;
			case 5:
				col6[i] = 1;
				break;
			case 6:
				col7[i] = 1;
				break;
			case 7:
				col8[i] = 1;
				break;
			}

			if (Solve(chessBoard, col + 1) == true)
				return true;

			switch (col) {
			case 0:
				col1[i] = 0;
				break;
			case 1:
				col2[i] = 0;
				break;
			case 2:
				col3[i] = 0;
				break;
			case 3:
				col4[i] = 0;
				break;
			case 4:
				col5[i] = 0;
				break;
			case 5:
				col6[i] = 0;
				break;
			case 6:
				col7[i] = 0;
				break;
			case 7:
				col8[i] = 0;
				break;
			}
		}
	}

	return false;
}

bool ChessBoard::CheckSafeQueens(ChessBoard chessBoard, int row, int col) {
	//Check horizontal
	//Check vertical
	//Check diagonal

	//Checking horizontal
	for (int i = 0; i < col; ++i) {
		switch (i) {
		case 0:
			if (col1[row] == 1) {
				return false;
			}
			break;
		case 1:
			if (col2[row] == 1) {
				return false;
			}
			break;
		case 2:
			if (col3[row] == 1) {
				return false;
			}
			break;
		case 3:
			if (col4[row] == 1) {
				return false;
			}
			break;
		case 4:
			if (col5[row] == 1) {
				return false;
			}
			break;
		case 5:
			if (col6[row] == 1) {
				return false;
			}
			break;
		case 6:
			if (col7[row] == 1) {
				return false;
			}
			break;
		case 7:
			if (col8[row] == 1) {
				return false;
			}
			break;
		}
	}

	//Checking vertical
	for (int i = 0; i < 8; ++i) {
		switch (col) {
		case 0:
			if (col1[i] == 1) {
				return false;
			}
			break;
		case 1:
			if (col2[i] == 1) {
				return false;
			}
			break;
		case 2:
			if (col3[i] == 1) {
				return false;
			}
			break;
		case 3:
			if (col4[i] == 1) {
				return false;
			}
			break;
		case 4:
			if (col5[i] == 1) {
				return false;
			}
			break;
		case 5:
			if (col6[i] == 1) {
				return false;
			}
			break;
		case 6:
			if (col7[i] == 1) {
				return false;
			}
			break;
		case 7:
			if (col8[i] == 1) {
				return false;
			}
			break;
		}
	}

	//Checking upper right diagonal
	int j = col + 1;
	for (int i = row - 1; i >= 0; --i) {
		switch (j) {
		case 0:
			if (col1[i] == 1) {
				return false;
			}
			break;
		case 1:
			if (col2[i] == 1) {
				return false;
			}
			break;
		case 2:
			if (col3[i] == 1) {
				return false;
			}
			break;
		case 3:
			if (col4[i] == 1) {
				return false;
			}
			break;
		case 4:
			if (col5[i] == 1) {
				return false;
			}
			break;
		case 5:
			if (col6[i] == 1) {
				return false;
			}
			break;
		case 6:
			if (col7[i] == 1) {
				return false;
			}
			break;
		case 7:
			if (col8[i] == 1) {
				return false;
			}
			break;
		}

		j++;
	}

	//Checking lower left diagonal
	j = col - 1;
	for (int i = row + 1; i < 8; ++i) {
		switch (j) {
		case 0:
			if (col1[i] == 1) {
				return false;
			}
			break;
		case 1:
			if (col2[i] == 1) {
				return false;
			}
			break;
		case 2:
			if (col3[i] == 1) {
				return false;
			}
			break;
		case 3:
			if (col4[i] == 1) {
				return false;
			}
			break;
		case 4:
			if (col5[i] == 1) {
				return false;
			}
			break;
		case 5:
			if (col6[i] == 1) {
				return false;
			}
			break;
		case 6:
			if (col7[i] == 1) {
				return false;
			}
			break;
		case 7:
			if (col8[i] == 1) {
				return false;
			}
			break;
		}

		j--;
	}

	//Checking upper left
	j = col - 1;
	for (int i = row - 1; i >= 0; --i) {
		switch (j) {
		case 0:
			if (col1[i] == 1) {
				return false;
			}
			break;
		case 1:
			if (col2[i] == 1) {
				return false;
			}
			break;
		case 2:
			if (col3[i] == 1) {
				return false;
			}
			break;
		case 3:
			if (col4[i] == 1) {
				return false;
			}
			break;
		case 4:
			if (col5[i] == 1) {
				return false;
			}
			break;
		case 5:
			if (col6[i] == 1) {
				return false;
			}
			break;
		case 6:
			if (col7[i] == 1) {
				return false;
			}
			break;
		case 7:
			if (col8[i] == 1) {
				return false;
			}
			break;
		}

		j--;
	}

	//Checking lower right diagonal
	j = col + 1;
	for (int i = row + 1; i < 8; ++i) {
		switch (j) {
		case 0:
			if (col1[i] == 1) {
				return false;
			}
			break;
		case 1:
			if (col2[i] == 1) {
				return false;
			}
			break;
		case 2:
			if (col3[i] == 1) {
				return false;
			}
			break;
		case 3:
			if (col4[i] == 1) {
				return false;
			}
			break;
		case 4:
			if (col5[i] == 1) {
				return false;
			}
			break;
		case 5:
			if (col6[i] == 1) {
				return false;
			}
			break;
		case 6:
			if (col7[i] == 1) {
				return false;
			}
			break;
		case 7:
			if (col8[i] == 1) {
				return false;
			}
			break;
		}

		j++;
	}
	return true;
}

string ChessBoard::ToString() {
	string answer = "";
	// Displaying board
	for (int i = 0; i < 8; ++i) {
		stringstream ss;
		ss << col1[i];
		ss << col2[i];
		ss << col3[i];
		ss << col4[i];
		ss << col5[i];
		ss << col6[i];
		ss << col7[i];
		ss << col8[i];

		string str = ss.str();
		answer += str + "\n";
	}

	return answer;
}

extern std::string CallSimpleExceptionMethod(int i)
{
	std::string retVal;
	// Creating pointer of myFakeClass
	MyFakeClass* resourceThatNeedsToBeCleanedup = new MyFakeClass();
	// Calls deconstructor
	delete resourceThatNeedsToBeCleanedup;
	// Exception value retur
	retVal = SimpleExceptionMethod(i);

	return retVal;
}

extern string SimpleExceptionMethod(int i) {
	// Throw exception 1
	if (i == 1)
	{
		try {
			throw MyException1();
		}
		catch(MyException1 e) {
			return e.what();
		}
	}
	// Throw exception 2
	else if (i == 2)
	{
		try {
			throw MyException2();
		}
		catch(MyException2 e) {
			return e.what();
		}

	}
	// Throw exception 3
	else if (i == 3)
	{
		try {
			throw MyException3();
		}
		catch (MyException3 e) {
			return e.what();
		}
	}
	// No exception thrown
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