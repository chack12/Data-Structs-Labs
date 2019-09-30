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

	cout << "******************" << endl;
	cout << "* The Game of 13 *" << endl;
	cout << "******************" << endl;
	cout << endl;
	cout << "Rules of the game" << endl;
	cout << "Each player must use the hand they draw from the pile to establish" << endl;
	cout << "a stack in ascending order of cards from Ace to King (1-13). Players can only add" << endl;
	cout << "cards in EXACT order. Each turn begins with the player drawing a card. The max" << endl;
	cout << "amount of cards a player can have in their hand is 6. If the player cannot put a card" << endl;
	cout << "in their stack, their turn is over." << endl;
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
			cout << endl;

			transform(inputS.begin(), inputS.end(), inputS.begin(), ::tolower);
			if (inputS == "place") {
				game.GetPlayer(1)->ShowHand();

				cout << "What card do you want to add on the stack: " << endl;
				cin >> inputI;
				cout << endl;

				if (inputI <= 12 || inputI >= 0) {
					game.GetPlayer(1)->AddCardToStack(game.GetPlayer(1)->GetCard(inputI));

					if (game.GetPlayer(1)->CheckForWin()) {
						endGame = true;
						player1Turn = false;
					}
				}
				else {
					cout << "Invalid input" << endl;
					cout << endl;
				}
			}
			else if (inputS == "discard") {
				game.GetPlayer(1)->ShowHand();

				cout << "What card do you want to discard: " << endl;
				cin >> inputI;
				cout << endl;

				if (inputI <= 12 || inputI >= 0) {
					game.PutToBottom(game.GetPlayer(1)->GetCard(inputI));
				}
				else {
					cout << "Invalid input" << endl;
					cout << endl;
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
				if (game.GetPlayer(1)->GetHandSize() < 6) {
					game.GetPlayer(1)->AddCardToHand(game.PullFromTopofPile());
				}
				else {
					cout << "Too many cards in your hand" << endl;
					cout << endl;
				}
			}
			else {
				cout << "Invalid input" << endl;
				cout << endl;
			}
		}
		
		while (player2Turn) {
			game.GetPlayer(2)->ShowHand();
			cout << "Drawing a card from the top of the pile..." << endl;
			cout << endl;
			game.GetPlayer(2)->AddCardToHand(game.PullFromTopofPile());
			game.GetPlayer(2)->ShowHand();
			game.GetPlayer(2)->ShowStack();

			cout << "Place - add a card from your hand to the stack." << endl;
			cout << "Dump - discard all cards and draw 5 new ones. Ends turn immediately" << endl;
			cout << "Draw - draw a card from the community pile (Max cards in hand is 6)" << endl;
			cout << "Discard - if you cannot place a card on the stack, you must discard to end your turn" << endl;
			cout << "Player 2: Enter your action: ";
			cin >> inputS;
			cout << endl;

			transform(inputS.begin(), inputS.end(), inputS.begin(), ::tolower);
			if (inputS == "place") {
				game.GetPlayer(2)->ShowHand();

				cout << "What card do you want to add on the stack: " << endl;
				cin >> inputI;
				cout << endl;

				if (inputI <= 12 || inputI >= 0) {
					game.GetPlayer(2)->AddCardToStack(game.GetPlayer(2)->GetCard(inputI));

					if (game.GetPlayer(2)->CheckForWin()) {
						endGame = true;
						player2Turn = false;
					}
				}
				else {
					cout << "Invalid input" << endl;
					cout << endl;
				}
			}
			else if (inputS == "discard") {
				game.GetPlayer(2)->ShowHand();

				cout << "What card do you want to discard: " << endl;
				cin >> inputI;
				cout << endl;

				if (inputI <= 12 || inputI >= 0) {
					game.PutToBottom(game.GetPlayer(2)->GetCard(inputI));
				}
				else {
					cout << "Invalid input" << endl;
					cout << endl;
				}
			}
			else if (inputS == "dump") {
				std::vector<Card*> listOfCards = game.GetPlayer(2)->DiscardHand();

				for (int i = 0; i < listOfCards.size(); ++i) {
					game.PutToBottom(listOfCards[i]);
				}

				player2Turn = false;
			}
			else if (inputS == "draw") {
				if (game.GetPlayer(2)->GetHandSize() < 6) {
					game.GetPlayer(2)->AddCardToHand(game.PullFromTopofPile());
				}
				else {
					cout << "Too many cards in your hand" << endl;
					cout << endl;
				}
			}
			else {
				cout << "Invalid input" << endl;
				cout << endl;
			}
		}
	}

	if (game.GetPlayer(1)->CheckForWin()) {
		cout << "Player 1 Wins" << endl;
	}

	if (game.GetPlayer(2)->CheckForWin()) {
		cout << "Player 2 Wins" << endl;
	}

	return 0;
}