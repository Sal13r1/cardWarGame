#include <stdlib.h>
#include <iostream>
#include "meaMath.hh"
#include "vector.hh"

#pragma once
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
	ACE = 14, // or 1
	JOKER
};

class Card {

	SUIT suit;
	RANK rank;

private:

public:
	Card()
	{
		suit = static_cast<SUIT>(0);
		rank = static_cast<RANK>(0);
	}
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
	Vector<Card> deck;

public:
	Deck()
	{
	}

	~Deck()
	{
	}

	void fillDeck()
	{
		for (int suit = 0; suit < 4; ++suit)
		{
			for (int rank = 2; rank <= 14; ++rank)
			{
				Card card(suit, rank);
				deck.pushBack(card);
			}
		}
	}

	void splitDeck(Deck* deckA, Deck* deckB)
	{

	}

	void printShuffleMessage()
	{
		std::cout << std::endl << "!!!!!!!!!!!!!!!!!!!" << std::endl << "!!!!!Shuffling!!!!!" << std::endl << "!!!!!!!!!!!!!!!!!!!" << std::endl << std::endl;
	}

	void shuffleDeck()
	{
		printShuffleMessage();
		shuffleVector(deck);
	}

	Card dealCard()
	{
		return deck.popFront();
	}

	void takeCard(Card card)
	{
		deck.pushBack(card);
	}

	size_t deckSize()
	{
		return deck.Size();
	}

	/** printDeck() is mostly used for debugging, it prints the full deck.
	 *	Big O: O()
	 */
	void printDeck()
	{
		for (int i = 0; i < deckSize(); ++i)
			{
				std::cout << "Card [" << i+1 << "]: ";
				deck[i].printCard();
			}		
	}
};
