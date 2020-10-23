#include <iostream>
#include <math.h>
#include <time.h>
#define cardNumber 4
#define playerCount 2
using namespace std;
//data types 0=suit, 1=colour,2=point value
static int hand[2][4][3]{ };

static void createCard(int player, int cardNum) {

	for (int k = 0; k <= 2; k++) {
		switch (k) {		
		case(0):hand[player][cardNum][k] = (rand() % 6) +1; break;
		case(1):hand[player][cardNum][k] = (rand() % 8) +1;	break;
		case(2):hand[player][cardNum][k] = (rand() % 8) +1 ; break;

			//Declares suit to player		
		}
	}
}
void outputHand(int playerNum,int sizeOfHand) {
		for (int i=0;i<=sizeOfHand;i++){
			cout << hand[0][i][0];
			cout << hand[0][i][1];
			cout << hand[0][i][2];
			cout << "player " << playerNum +1 << "'s ";
			switch (hand[playerNum][i][0]) {
			case(1): cout << "card " << i + 1 << " is suit shield, "; break;
			case(2): cout << "card " << i + 1 << " is suit triagle, "; break;
			case(3): cout << "card " << i + 1 << " is suit elipse, "; break;
			case(4): cout << "card " << i + 1 << " is suit hazard, "; break;
			case(5): cout << "card " << i + 1 << " is suit chevron, "; break;
			case(6): cout << "card " << i + 1 << " is suit eye, "; break;

				
			}
			//Declares color to player
			switch (hand[playerNum][i][1]) {

			case(1): cout << "is Blue, "; break;
			case(2): cout << "is yellow, "; break;
			case(3): cout << "is Pink, "; break;
			case(4): cout << "is Red, "; break;
			case(5): cout << "is Orange, "; break;
			case(6): cout << "is Green, "; break;
			case(7): cout << "is indigo, "; break;
			case(8): cout << "is Violet, "; break;
			}
			//Declares Point value to player
			switch (hand[playerNum][i][2]) {

			case(1): cout << "is 1 point,  \n"; break;
			case(2): cout << "is 2 points, \n"; break;
			case(3): cout << "is 3 points, \n"; break;
			case(4): cout << "is 4 points, \n"; break;
			case(5): cout << "is 5 points, \n"; break;
			case(6): cout << "is 6 points, \n"; break;
			case(7): cout << "is 7 points, \n"; break;
			case(8): cout << "is 8 points, \n"; break;
			}
	}
}
static int gameStart() {

	//assigns values for all players, cards and data types within cards 
	for (int i = 0; i < 2; i++) {
		srand(time(0));
		for (int j = 0; j < 4; j++) {
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
		outputHand(0,3);
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
	
}



