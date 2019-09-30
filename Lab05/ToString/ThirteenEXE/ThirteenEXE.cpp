// ThirteenEXE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <locale>
#include <string>
#include "../ToString/ToString.cpp"

using namespace std;

int main()
{
	Game game;
	string inputS;
	int inputI;
	bool endGame = false, player1Turn = true, player2Turn = true;

	cout << "Welcome to 13" << endl;
	//cout << "Rules of the game" << endl;
	cout << endl;

	for (int i = 0; i < 5; ++i) {
		game.GetPlayer(1)->AddCardToHand(game.PullFromTopofPile());
		game.GetPlayer(2)->AddCardToHand(game.PullFromTopofPile());
	}

	while (!endGame) {
		while (player1Turn) {
			game.GetPlayer(1)->ShowHand();
			cout << "Drawing a card from the top of the pile..." << endl;
			cout << endl;
			game.GetPlayer(1)->AddCardToHand(game.PullFromTopofPile());
			game.GetPlayer(1)->ShowHand();
			game.GetPlayer(1)->ShowStack();

			cout << "Place - add a card from your hand to the stack." << endl;
			cout << "Dump - discard all cards and draw 5 new ones. Ends turn immediately" << endl;
			cout << "Draw - draw a card from the community pile (Max cards in hand is 6)" << endl;
			cout << "Discard - if you cannot place a card on the stack, you must discard to end your turn" << endl;
			cout << "Player 1: Enter your action: ";
			cin >> inputS;

			transform(inputS.begin(), inputS.end(), inputS.begin(), ::tolower);
			if (inputS == "place") {
				game.GetPlayer(1)->ShowHand();

				cout << "What card do you want to add on the stack: " << endl;
				cin >> inputI;

				if (inputI <= 12 || inputI >= 0) {
					game.GetPlayer(1)->AddCardToStack(game.GetPlayer(1)->GetCard(inputI));

					if (game.GetPlayer(1)->CheckForWin()) {
						endGame = true;
						player1Turn = false;
					}
				}
				else {
					cout << "Invalid input" << endl;
				}
			}
			else if (inputS == "discard") {
				game.GetPlayer(1)->ShowHand();

				cout << "What card do you want to discard: " << endl;
				cin >> inputI;

				if (inputI <= 12 || inputI >= 0) {
					game.PutToBottom(game.GetPlayer(1)->GetCard(inputI));
				}
				else {
					cout << "Invalid input" << endl;
				}
			}
			else if (inputS == "dump") {
				std::vector<Card*> listOfCards = game.GetPlayer(1)->DiscardHand();

				for (int i = 0; i < listOfCards.size(); ++i) {
					game.PutToBottom(listOfCards[i]);
				}
				
				player1Turn = false;
			}
			else if (inputS == "draw") {
				//Check for 6 cards
				game.GetPlayer(1)->AddCardToHand();
			}
			else {
				cout << "Invalid input" << endl;
			}
		}
		

		//Players 2 turn
	}

	if (game.GetPlayer(1)->CheckForWin()) {
		cout << "Player 1 Wins" << endl;
	}

	if (game.GetPlayer(2)->CheckForWin()) {
		cout << "Player 2 Wins" << endl;
	}
}
