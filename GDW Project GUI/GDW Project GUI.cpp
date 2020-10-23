#include <iostream>
using namespace std; 

int main()
{
	int numOfPlayers; 
	int timeLimit; 
	int playGame;

	// Space
	cout << "\n";

	// Asking for the number of players required for the game 
	cout << "Insert a number of players (2 - 8 players): "; 
	cin >> numOfPlayers; 

	// While loop that makes sure that the number of players are valid (between 2 - 8) 
	while (numOfPlayers <= 1 || numOfPlayers >= 9) {
		cout << numOfPlayers << " is an invalid amount of players please enter another amount:" << endl;
		cout << "Insert a number of players (2 - 8 players): ";
		cin >> numOfPlayers;
	}

	// Space
	cout << "----------------------------------------------------------------------------------------------------------------------" << "\n";
	cout << "\n";

	// Setting how long the game will be 
	cout << "How long would you like the game to be?: (enter 1 or 2)" << endl;
	cout << "1. 5 - 10 minutes" << endl;
	cout << "2. 10 - 15 minutes" << endl;
	cin >> timeLimit;

	// While loop that makes sure that the player inputs the required number of minutes 
	while (timeLimit != 1 && timeLimit != 2) {
		cout << timeLimit << " is not a valid option try again";
		cout << "How long would you like the game to be?: (enter 1 or 2)" << endl;
		cout << "1. 5 - 10 minutes" << endl;
		cout << "2. 10 - 15 minutes" << endl;
		cin >> timeLimit;
	 }

	// Space
	cout << "----------------------------------------------------------------------------------------------------------------------" << "\n";
	cout << "\n";

	// Starting the game or reading the rules; 
	cout << "Would you like to start the game or read the rules?: (enter 1 or 2) " << endl;
	cout << "1. Start the game" << endl;
	cout << "2. View the rules" << endl;
	cin >> playGame; 

	// While loop that makes sure the player enter 1 or 2; 
	while (playGame != 1 && playGame != 2) {
		cout << playGame << " is not a valid option try again ";
		cout << "Would you like to start the game or read the rules?: (enter 1 or 2) " << endl;
		cout << "1. Start the game" << endl;
		cout << "2. View the rules" << endl;
		cin >> playGame;
	}

	// Space
	cout << "----------------------------------------------------------------------------------------------------------------------" << "\n";
	cout << "\n";

	// if statement to view the rules 
	if (playGame == 2) {
		cout << "RULES: " << endl;
		cout << "Each player chooses 1 of 8 possible colours, when that colour is picked for that player only their starting colour will be worth 20 points." << endl; 
		cout << "Afterwards every player draws 4 cards from the MAIN deck. Each card will have a value from 1 - 8 on them" << endl;
		cout << "player with the highest value goes first)" << endl;

		// Space
		cout << "\n";

		cout << "On your turn you'll move around the board to 1 of the 8 piles of cards (one for each colour)" << endl;
		cout << "You CAN draw 2 cards from the main deck (this is optional) However you MUST draw a challenge card" << endl;
		cout << "When a challenge card is drawn pick up to 3 players to challenge" << endl;
		cout << "(whoever wins the challenge can force the other player to discard their highest value card)" << endl;

		// Space
		cout << "\n";

		cout << "Challenges:" << endl;
		cout << "Bluff or Snuff" << endl;
		cout << "Match or Snatch" << endl;
		cout << "Colors Show!" << endl;

	}
}
// i change 