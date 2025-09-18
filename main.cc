/* 
*	Silne Veras
*	Mar 2025
*	This is my implementation of the card game 'war'
*/

//TODO BEFORE SUBMITTING TO KRYSTAL: YOU MUST SIMPLIFY THE #INCLUDES. Make them correct this is ugly.
#include <stdio.h>
#include <stdlib.h>
#include "meaMath.hh" // My custom math helper!
#include "cardDeck.hh" // This creates decks and cards
#include "player.hh" // make player methods
#include "warGame.hh" // Use this to control the actual game, including number of players


// We'll need to make a player class that owns a deck array of our length. We should use vectors
//4 players is the max per deck. 4 Players get 52/4
int main()
{

	//NEXT STEPS SOLVE TYPE COMPARISON ISSUE AND THEN SEE IF WE CAN MAKE A DECK
	int numOfPlayers = 2; // 2 is default
	std::cout << "How many Players? (This version supports 2-4)" << std::endl;
	//std::cin >> numOfPlayers;

	switch(numOfPlayers) {
		case 1:
			//call war with num of players.
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		default:
			std::cout << "The valid range is 1-4 players." << std::endl;
	}

	std::cout << std::endl << "!!!WAR IS ON THE HORIZON!!!" << std::endl;
	Deck* deck = new Deck();
	deck->fillDeck();
	std::cout << "!!! SOLDIERS DRAFTED !!!" << std::endl;
	deck->shuffleDeck();
	deck->printDeck();

	Player player1;
	Player player2;

	std::cout << "!!! GENERALS CHOSEN !!!" << std::endl;

	player1.takeCard(*deck);
	player2.takeCard(*deck);

	std::cout << "!!! FIRST SOLDERS GATHERED !!!" << std::endl;

	Deck* fieldOfWar;

	std::cout << "Player 1's deck: " << std::endl;

	player1.printCards();


	std::cout << "Player 2's deck: " << std::endl;
	player2.printCards();

	std::cout << "!!! Armies are Gathering !!!" << std::endl;

	return 0;
}
