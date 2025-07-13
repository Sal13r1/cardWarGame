#include <stdlib.h>
#include <iostream>
#include "meaMath.hh"

enum SUIT {
	HEARTS = 0,
	DIAMONDS,
	CLUB,
	SPADES
};

enum RANK {
	TWO = 2,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN,
	JACK,
	QUEEN,
	KING,
	ACE,
	JOKER
};

class Card {

	SUIT suit;
	RANK rank;

private:

public:
	Card(int nSuit, int nRank)
	{
		suit = static_cast<SUIT>(nSuit);
		rank = static_cast<RANK>(nRank);
	}

	~Card()
	{
	}

	void printCard()
	{
		std::string suitNames[] = {"HEARTS", "DIAMONDS", "CLUB", "SPADES"};
		std::string rankNames[] = {"", "", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE", "TEN", "JACK", 
									"QUEEN", "KING", "ACE", "JOKER"};
		
		std::cout << rankNames[rank] << " of " << suitNames[suit] << std::endl;
	}
};

class Deck {
	Card* deck[52];

public:
	Deck()
	{
		int n = 0;
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 2; j < 16; ++j)
			{
				deck[n] = new Card(i,j);
				n++;
			}
		}
	}

	~Deck()
	{
		for (int i = 0; i < 53; ++i)
		{
			delete deck[i];
		}
	}

	/** printDeck() is mostly used for debugging, it prints the full deck.
	 *	Big O: O(i)
	 */
	void printDeck()
	{
		for (int i = 0; i < 52; ++i)
		{
			deck[i]->printCard();
		}
	}

	void printShuffleMSG()
	{
		std::cout << std::endl << "!!!!!!!!!!!!!!!!!!!" << std::endl << "!!!!!Shuffling!!!!!" << std::endl << "!!!!!!!!!!!!!!!!!!!" << std::endl << std::endl;
	}

	void shuffleDeck()
	{
		printShuffleMSG();
		shuffleArray(deck);
	}
};
