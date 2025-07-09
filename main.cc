/* 
*	Silne Veras
*	Mar 2025
*	This is my implementation of 'war'
*/
#include <stdio.h>
#include <stdlib.h>
#include "meaMath.hh"
#include "cardDeck.cc"

int main()
{
	Deck* deck = new Deck();
	deck->shuffleDeck();
	deck->printDeck();
	return 0;
}
