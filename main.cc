/* 
*	Silne Veras
*	Mar 2025
*	This is my implementation of 'war'
*/

//TODO BEFORE SUBMITTING TO KRYSTAL: YOU MUST SIMPLIFY THE #INCLUDES. Make them correct this is ugly.
#include <stdio.h>
#include <stdlib.h>
#include "meaMath.hh" // My custom math helper!
#include "cardDeck.hh" // This creates decks and cards
#include "player.hh" // make player methods
#include "warGame.hh" // USe this to control the actual game, including number of players

int main()
{
	std::cout << std::endl << "!!!WAR IS ON THE HORIZON!!!" << std::endl;
	Deck* deck = new Deck();
	std::cout << "!!! SOLDIERS DRAFTED !!!" << std::endl;
	deck->shuffleDeck();
	std::cout << "!!! Armies are Gathering !!!" << std::endl;

	return 0;
}
