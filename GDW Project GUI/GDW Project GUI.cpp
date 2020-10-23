#include <iostream>
#include <math.h>
#include <time.h>
#define cardNumber 4
#define playerCount 2
using namespace std;
//data types 0=suit, 1=colour,2=point value
static int hand[playerCount][cardNumber][3]{ };

static void createCard(int player, int cardNum) {

	for (int k = 0; k <= 2; k++) {
		switch (k) {
		case(0):hand[player][cardNum][k] = (rand() % 6) + 1;
		case(1):hand[player][cardNum][k] = (rand() % 8) + 1;
		case(2):hand[player][cardNum][k] = (rand() % 8) + 1;
		}
	}
}
static int gameStart() {

	//assigns values for all players, cards and data types within cards 
	for (int i = 0; i <= playerCount; i++) {
		for (int j = 0; j <= cardNumber; j++) {
			createCard(i, j);
		}
	}
	return (0);
}


int main()
{
	int numOfPlayers; 
	int timeLimit; 
	int playGame;

	// Space
	std::cout << "\n";

	// Asking for the number of players required for the game 
	std::cout << "Insert a number of players (2 - 8 players): ";
	std::cin >> numOfPlayers;

	// While loop that makes sure that the number of players are valid (between 2 - 8) 
	while (numOfPlayers <= 1 || numOfPlayers >= 9) {
		std::cout << numOfPlayers << " is an invalid amount of players please enter another amount:" << std::endl;
		std::cout << "Insert a number of players (2 - 8 players): ";
		std::cin >> numOfPlayers;
	}

	// Space
	std::cout << "----------------------------------------------------------------------------------------------------------------------" << "\n";
	std::cout << "\n";

	// Setting how long the game will be 
	std::cout << "How long would you like the game to be?: (enter 1 or 2)" << std::endl;
	std::cout << "1. 5 - 10 minutes" << std::endl;
	std::cout << "2. 10 - 15 minutes" << std::endl;
	std::cin >> timeLimit;

	// While loop that makes sure that the player inputs the required number of minutes 
	while (timeLimit != 1 && timeLimit != 2) {
		std::cout << timeLimit << " is not a valid option try again";
		std::cout << "How long would you like the game to be?: (enter 1 or 2)" << std::endl;
		std::cout << "1. 5 - 10 minutes" << std::endl;
		std::cout << "2. 10 - 15 minutes" << std::endl;
		std::cin >> timeLimit;
	 }

	// Space
	std::cout << "----------------------------------------------------------------------------------------------------------------------" << "\n";
	std::cout << "\n";

	// Starting the game or reading the rules; 
	std::cout << "Would you like to start the game or read the rules?: (enter 1 or 2) " << std::endl;
	std::cout << "1. Start the game" << std::endl;
	std::cout << "2. View the rules" << std::endl;
	std::cin >> playGame;

	if (playGame == 1) {

		gameStart();
		
	}

	// While loop that makes sure the player enter 1 or 2; 
	while (playGame != 1 && playGame != 2) {
		std::cout << playGame << " is not a valid option try again ";
		std::cout << "Would you like to start the game or read the rules?: (enter 1 or 2) " << std::endl;
		std::cout << "1. Start the game" << std::endl;
		std::cout << "2. View the rules" << std::endl;
		std::cin >> playGame;
	}

	// Space
	std::cout << "----------------------------------------------------------------------------------------------------------------------" << "\n";
	std::cout << "\n";

	// if statement to view the rules 
	if (playGame == 2) {
		std::cout << "RULES: " << std::endl;
		std::cout << "Each player chooses 1 of 8 possible colours, when that colour is picked for that player only their starting colour will be worth 20 points." << std::endl;
		std::cout << "Afterwards every player draws 4 cards from the MAIN deck. Each card will have a value from 1 - 8 on them" << std::endl;
		std::cout << "player with the highest value goes first)" << std::endl;

		// Space
		std::cout << "\n";

		std::cout << "On your turn you'll move around the board to 1 of the 8 piles of cards (one for each colour)" << std::endl;
		std::cout << "You CAN draw 2 cards from the main deck (this is optional) However you MUST draw a challenge card" << std::endl;
		std::cout << "When a challenge card is drawn pick up to 3 players to challenge" << std::endl;
		std::cout << "(whoever wins the challenge can force the other player to discard their highest value card)" << std::endl;

		// Space
		std::cout << "\n";

		std::cout << "Challenges:" << std::endl;
		std::cout << "Bluff or Snuff" << std::endl;
		std::cout << "Match or Snatch" << std::endl;
		std::cout << "Colors Show!" << std::endl;

	}
	gameStart();
}



