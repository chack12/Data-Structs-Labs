// TowerHannoiGame.cpp : Defines the entry point for the console application.
//

// TODO you will need to uncomment the line below
#include "..\StackQueues\StackQueues.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TowersOfHannoiGame
{
public:
	TowersOfHannoiGame() : m_GameEnded(false)
	{
		stackLeft.push(4);
		stackLeft.push(3);
		stackLeft.push(2);
		stackLeft.push(1);
	}

	bool IsGameEnded() {
		ArrayBasedStack temp = stackRight;

		//Peek and pop all the way to the bottom of the stack
		//Make sure it is 1 2 3 4
		if (temp.peek() == 1) {
			temp.pop();
			if (temp.peek() == 2) {
				temp.pop();
				if (temp.peek() == 3) {
					temp.pop();
					if (temp.peek() == 4) {
						m_GameEnded = true;
						PrintTowers();
						PrintMoves();
						cout << "You win!" << endl;
					}
				}
			}
		}
		return m_GameEnded; 
	}

	void PrintMoves() {
		cout << moves.display() << endl;
	}

	ArrayBasedStack &GetPole(int poleId) {
		if (poleId == 1) {
			return stackLeft;
		}
		else if (poleId == 2) {
			return stackMiddle;
		}
		else {
			return stackRight;
		}
	}

	ArrayBasedQueue &GetMoves() {
		return moves;
	}

	void PrintTowers() {
		cout << endl;

		stackLeft.display();
		cout << "Left" << endl;

		stackMiddle.display();
		cout << "Middle" << endl;

		stackRight.display();
		cout << "Right" << endl;

		cout << endl;
	}

private:
	bool m_GameEnded;
	ArrayBasedStack stackLeft, stackMiddle, stackRight;
	ArrayBasedQueue moves;
};

int main()
{
	cout << "Enter in moves to make for Towers of Hannoi" << endl;
	cout << "Progam will exit once towers have been successfully moved of" << endl;
	cout << "or string of -1 is entered. Moves must be entired in format of" << endl;
	cout << "<disk>,<column from>,<column to> no spaces" << endl;
	cout << "Only use disks 1-4 and columns 1-3" << endl;

	TowersOfHannoiGame game;

	bool receivedEndToken = false;

	while (!(receivedEndToken || game.IsGameEnded()))
	{
		std::string inputLine;
		game.PrintTowers();
		cout << "<disk>,<column from>,<column to>" << endl;
		cout << "Enter Move: ";
		getline(cin, inputLine);
		if (inputLine == "-1")
		{
			receivedEndToken = true;
		}
		else
		{
			std::vector<std::string> output;
			std::string::size_type prev_pos = 0, pos = 0;
			// Snippet from https://stackoverflow.com/questions/5167625/splitting-a-c-stdstring-using-tokens-e-g
			// tokenizing a string
			while ((pos = inputLine.find(",", pos)) != std::string::npos)
			{
				std::string substring(inputLine.substr(prev_pos, pos - prev_pos));
				output.push_back(substring);
				prev_pos = ++pos;
			}
			//Need to get last token
			output.push_back(inputLine.substr(prev_pos, pos - prev_pos)); // Last word

			if (output.size() != 3)
			{
				receivedEndToken = true;
				cout << "Invalid input recieved = " + inputLine << endl;
			}
			else
			{
				std::string disk = output[0];
				std::string from = output[1];
				std::string to = output[2];

				if (disk.size() == 0 || from.size() == 0 || to.size() == 0) {
					receivedEndToken = true;
					cout << "Invalid input received = " + inputLine << endl;
				}

				int diskId = atoi(disk.c_str());
				int fromId = atoi(from.c_str());
				int toId = atoi(to.c_str());

				//Check for invalid numbers
				if (diskId == 0 || fromId == 0 || toId == 0 || fromId == toId || diskId < 0 || 
					diskId > 5 || fromId < 0  || fromId > 4 || toId < 0 || toId > 4)
				{
					receivedEndToken = true;
					cout << "Invalid input received = " + inputLine << endl;
				}
				else {
					//Check for invalid moves
					if (game.GetPole(toId).peek() == -1 || game.GetPole(toId).peek() > diskId) {
						//Add the move to the moves queue
						game.GetMoves().enQueue(inputLine);

						//Move the disk
						game.GetPole(fromId).pop();
						game.GetPole(toId).push(diskId);

						cout << "Disk " << diskId << " From " << fromId << " To " << toId << endl;
					}
					else {
						receivedEndToken = true;
						cout << "Invalid input received = " + inputLine << endl;
					}
				}
			}
		}
	}

    return 0;
}

