// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the TOSTRINGDLL_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// TOSTRINGDLL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef TOSTRINGDLL_EXPORTS
#define TOSTRINGDLL_API __declspec(dllexport)
#else
#define TOSTRINGDLL_API __declspec(dllimport)
#endif

#include <list>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <sstream>
#include <ctime>

class TOSTRINGDLL_API Card
{
public:
	//Card constructor
	Card(int myRank) {
		rank = myRank;
	}

	//Card deconstructor
	~Card() { }

	//Returns the cards rank
	int GetRank();

private:
	int rank;
};

class TOSTRINGDLL_API Deck
{
public:
	//Deck constructor
	Deck() {
		int ranks[13] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };

		for (int i = 0; i < 52; ++i) {
			int temp = ranks[i % 13];
			deck.push_back(new Card(ranks[i % 13]));
		}
	}

	~Deck() { 
		std::cout << "Deleting the deck" << std::endl;

		for (int i = 0; i < deck.size(); i++) {
			delete deck[i];
		}
	}

	//Returns the card at the inputted index 
	Card* CardAt(int index);

private:
	std::vector<Card*> deck;
};

class TOSTRINGDLL_API Player
{
public:
	//Player constructor
	Player(std::string name)
	{
		m_name = name;
	}

	//Player deconstructor
	virtual ~Player()
	{
		std::cout << "Deleting " << m_name << std::endl;
	}

	//Returns the name of the player
	std::string GetName();

	//Adds the inputted card to the hand of the player
	void AddCardToHand(Card* card);

	//Adds the card to the players stack
	void AddCardToStack(Card* card);

	//Gets the card assoicated with an input and removes it from the list
	Card* GetAndRemoveCard(int input);

	//Shows the inputted card
	Card* GetCard(int input);

	//Returns the size of the stack
	int GetStackSize();

	//Returns the card at the top of the stack
	Card* ShowTopOfStack();

	//Returns the size of the hand
	int GetHandSize();

	//Discards players deck
	std::vector<Card*> DiscardHand();

	//Returns a string of what is in the hand
	std::string ShowHand();

	//Show the players stack
	std::string ShowStack();

	//Checks for win condition
	bool CheckForWin();

private:
	std::string m_name;
	std::vector<Card*> m_stackOfCards;
	std::vector<Card*> m_listOfCards;
};

class TOSTRINGDLL_API Game
{
public:
	//Game constructor
	Game()
	{
		srand(time(NULL));

		deck = new Deck();

		m_player1 = new Player("Player1");
		m_player2 = new Player("Player2");

		//Add cards from the Deck to the masterCardList
		for (int i = 0; i < 52; ++i) {
			m_masterCardList.push_back(deck->CardAt(i));
		}

		//Move cards from the masterCardList to the communityPile
		for (int i = 0; i < 52; ++i) {
			int position = rand() % m_masterCardList.size();
			m_communityPile.push_back(m_masterCardList[position]);
			m_masterCardList.erase(m_masterCardList.begin() + position);
		}
	}

	//Game deconstructor
	~Game()
	{
		//Deletes player and player's hands.
		std::cout << "Deleting the game" << std::endl;

		delete deck;

		delete m_player1;
		delete m_player2;
	}

	//Returns a card from the top of the pile
	Card* PullFromTopofPile();

	//Adds discarded card to the bottom of the deck
	void PutToBottom(Card* card);

	//Return the player
	Player* GetPlayer(int i);

	//Returns the card at the top of the community pile
	Card* GetTopOfPile();

private:
	Player* m_player1;
	Player* m_player2;
	Deck* deck;
	std::vector<Card*> m_communityPile;
	std::vector<Card*> m_masterCardList;
};
