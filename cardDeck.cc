#include <stdlib.h>
#include <iostream>
#include "war_nums.hh"
//so how do we make a card deck? We could iterate over an int with two arrays that lead to face cards and 'numbers'
#include "war_nums.hh"


class Card{
	const SUIT suit;
	const RANK rank;

private:

public:
	Card(int suitInput, int rankInput) : suit((SUIT)suitInput), rank((RANK)rankInput) {}

	~Card()
	{
	}

	void printCard()
	{
		std::cout << rank << " of " << suit << std::endl;	
	}
};

class Deck{
	Card* deck[];


//Moment of inspiration. Try using recursion with the SUITS as i and then use the RANKS to iterate over/through them. Once you hit the final card, return! We can use a linked list for this.
public:
	Deck()
	{
		new
		for (int i = 0; i < 52; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				for (int k = 2; k < 16; ++k)
				{
					deck[i] = Card(j, k);
					deck[i].printCard();

				}
			}
		}
	}

	~Deck()
	{
	}

	//My attempt at implementing the Durstenfield algorithm for shuffling. Found via searching
	void shuffleDeck()
	{

	}
};
