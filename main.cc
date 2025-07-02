/* 
*	Silne Veras
*	Mar 2025
*	This is my implementation of 'war'
*/
#include <stdio.h>
#include <stdlib.h>
#include "cardDeck.cc"

int main()
{
	int numPlayers = 0;

	printf("How many entities are engaged in this war?\n");
	scanf("%d", &numPlayers);

	if (numPlayers < 2)
	{
		printf("You must choose at least two players."); //Now you have to add support for kicking out each player as they lose...What you done?
		return -1;
	}

	//divide 52 cards by number of players.
	// cardsPerPlayer = 52 / numPlayers

	//hand out cards until you are out. 

}
