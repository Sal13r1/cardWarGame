/* 
*	Silne Veras
*	Mar 2025
*	This is my implementation of 'war'
*/
#include <stdio.h>
#include <stdlib.h>
#include "meaMath.hh"
#include "cardDeck.hh"
#include "player.hh"

int main()
{

	std::cout << std::endl << "!!!WAR IS ON THE HORIZON!!!" << std::endl;
	Deck* deck = new Deck();
	std::cout << "!!! SOLDIERS DRAFTED !!!" << std::endl;
	deck->shuffleDeck();
	std::cout << "!!! Armies are Gathering !!!" << std::endl;

	return 0;
}
