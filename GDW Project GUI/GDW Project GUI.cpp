#include <iostream>
#include <windows.h>
#include <math.h>
#include <time.h>
using namespace std;
//data types 0=suit, 1=colour,2=point value

int hand[8][8][3]{ };
class Color {
public:
	Color(int desiredColor) {
		consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		color = desiredColor;
	}

	friend ostream& operator<<(ostream& ss, Color obj) {
		SetConsoleTextAttribute(obj.consoleHandle, obj.color);
		return ss;
	}
private:
	int color;
	HANDLE consoleHandle;
};

void challenge1(int playerTurn, int timeLimit) {

	int card1;
	int card2;
	int card3;
	int total=0;

	srand(time(0));
	
		int challengeType = rand() % 100;

	if (challengeType <=45 && challengeType >=0) {


		cout <<"You've received a Bluff or Snuff challenge card\n\n";
		cout << "Choose up to 3 cards to discard, if the value of your cards are higher than your opponents you win! and can force a discard on them.\n\n";

		cout << "Choose your first card if you do not wish to discard a card select type '0'\n";
			cin >> card1;
		cout << "Choose your second card if you do not wish to discard a card select type '0'\n";
			cin >> card2;
		cout << "Choose your third card if you do not wish to discard a card select type '0'\n";
			cin >> card3;

			total += (hand[playerTurn][card1][2] + hand[playerTurn][card2][2] + hand[playerTurn][card3][2]);
	}
	if (challengeType <= 90 && challengeType >= 46) {


		cout << "You've received a suit or boot challenge card\n\n";
		cout << "Choose up to 3 cards to discard, if the value of your cards are higher than your opponents you win! and can force a discard on them.\n\n";

		cout << "Choose your first card if you do not wish to discard a card select type '0'\n";
		cin >> card1;
		cout << "Choose your second card if you do not wish to discard a card select type '0'\n";
		cin >> card2;
		cout << "Choose your third card if you do not wish to discard a card select type '0'\n";
		cin >> card3;

		total += (hand[playerTurn][card1][2] + hand[playerTurn][card2][2] + hand[playerTurn][card3][2]);
	}


}

void createCard(int player, int cardNum) {

	for (int k = 0; k <= 2; k++) {
		switch (k) {
		case(0):hand[player][cardNum][k] = (rand() % 6) + 1; break;
		case(1):hand[player][cardNum][k] = (rand() % 8) + 1; break;
		case(2):hand[player][cardNum][k] = (rand() % 8) + 1; break;
					
		}
	}
}

void discardCard(int player, int cardNum) {

	//resets value for discarded card

	for (int k = 0; k <= 2; k++) {
		switch (k) {
		case(0):hand[player][cardNum][k] = 0; break;
		case(1):hand[player][cardNum][k] = 0; break;
		case(2):hand[player][cardNum][k] = 0; break;

		}
	}
}

void outputHand(int playerNum, int sizeOfHand) {
	for (int i = 0; i <= sizeOfHand; i++) {
		cout << "player " << playerNum + 1 << "'s ";
		//Declares suit to player
		switch (hand[playerNum][i][0]) {
		case(1): cout << "card " << i + 1 << " is suit " << Color(1) <<"Shield, " << Color(3); break;
		case(2): cout << "card " << i + 1 << " is suit " << Color(1) <<"Triangle, " << Color(3); break;
		case(3): cout << "card " << i + 1 << " is suit " << Color(1) << "Ellipse, " << Color(3); break;
		case(4): cout << "card " << i + 1 << " is suit " << Color(1) << "Hazard, " << Color(3); break;
		case(5): cout << "card " << i + 1 << " is suit " << Color(1) << "Chevron, " << Color(3); break;
		case(6): cout << "card " << i + 1 << " is suit " << Color(1) << "Eye, " << Color(3); break;


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

static int gameStart(int numOfPlayers) {

	//assigns values for all players, cards and data types within cards 
	for (int i = 0; i < numOfPlayers; i++) {
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
	int handSize=4;
	int playerTurn= 1;
	system("Color 7C");
	// Space
	std::cout << "\n";

	// Asking for the number of players required for the game 
	std::cout << "Insert a number of players (2 - 8 players): ";
	std::cin >> numOfPlayers;

	// While loop that makes sure that the number of players are valid (between 2 - 8) 
	while (numOfPlayers <= 1 || numOfPlayers >= 9) {
		std::cout << numOfPlayers << " is an invalid amount of players please enter another amount:\n";
		std::cout << "Insert a number of players (2 - 8 players): ";
		std::cin >> numOfPlayers;
	}

	// Space
	std::cout << "----------------------------------------------------------------------------------------------------------------------" << "\n";
	std::cout << "\n";

	// Setting how long the game will be 
	std::cout << "How long would you like the game to be?: (enter 1 or 2)\n";
	std::cout << "1. 5 - 10 minutes\n";
	std::cout << "2. 10 - 15 minutes\n";
	std::cin >> timeLimit;

	// While loop that makes sure that the player inputs the required number of minutes 
	while (timeLimit != 1 && timeLimit != 2) {
		std::cout << timeLimit << " is not a valid option try again\n";
		std::cout << "How long would you like the game to be?: (enter 1 or 2)\n";
		std::cout << "1. 5 - 10 minutes\n";
		std::cout << "2. 10 - 15 minutes\n";
		std::cin >> timeLimit;
	}

	// Space
	std::cout << "----------------------------------------------------------------------------------------------------------------------" << "\n";
	std::cout << "\n";

	// Starting the game or reading the rules; 
	std::cout << "Would you like to start the game or read the rules?: (enter 1 or 2)\n";
	std::cout << "1. Start the game\n";
	std::cout << "2. View the rules\n";
	std::cin >> playGame;

	if (playGame == 1) {
	
		for (int i = 0; i <= numOfPlayers; i++) {


			gameStart(numOfPlayers);
			cout << "it's player " << playerTurn << "'s turn: Your hand is:\n";

			outputHand(playerTurn-1, handSize);

			cout << "\n-----------------------------------------------------------------------------------------------------------------\n";
		
			cout << "Draw a challenge card:\n";
			challenge1(playerTurn, timeLimit);

		}
	}

	// While loop that makes sure the player enter 1 or 2; 
	while (playGame != 1 && playGame != 2) {
		std::cout << playGame << " is not a valid option try again\n";
		std::cout << "Would you like to start the game or read the rules?: (enter 1 or 2)\n";
		std::cout << "1. Start the game\n";
		std::cout << "2. View the rules\n";
		std::cin >> playGame;
	}

	// Space
	std::cout << "----------------------------------------------------------------------------------------------------------------------" << "\n";
	std::cout << "\n";

	// if statement to view the rules 
	while (playGame == 2) {
		std::cout << "RULES: " << std::endl;
		std::cout << "Each player chooses 1 of 8 possible colours, when that colour is picked for that player only their starting colour will be worth 20 points.\n";
		std::cout << "Afterwards every player draws 4 cards from the MAIN deck. Each card will have a value from 1 - 8 on them\n";
		std::cout << "player with the highest value goes first)\n";

		// Space
		std::cout << "\n";

		std::cout << "On your turn you'll move around the board to 1 of the 8 piles of cards (one for each colour)\n";
		std::cout << "You CAN draw 2 cards from the main deck (this is optional) However you MUST draw a challenge card\n";
		std::cout << "When a challenge card is drawn pick up to 3 players to challenge\n";
		std::cout << "(whoever wins the challenge can force the other player to discard their highest value card)\n";

		// Space
		std::cout << "\n";

		std::cout << "Challenges:\n";
		std::cout << "Bluff or Snuff\n";
		std::cout << "Match or Snatch\n";
		std::cout << "Colors Show!\n";

		// Space
		std::cout << "\n";

		// Asking the players if they want to view the rules again or start the game 
		std::cout << "Would you like to start the game or read the rules again?: (enter 1 or 2) \n";
		std::cout << "1. Start the game\n";
		std::cout << "2. View the rules\n";
		std::cin >> playGame;

		// Space
		std::cout << "\n";
	}

}
