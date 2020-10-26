#include <iostream>
#include <windows.h>
#include <math.h>
#include <time.h>



//initialization
using namespace std;

int numOfPlayers;

//data types 0 = suit | 1 = colour, | 2 = point value
int cardValue[8][8][3]{ };

//stores chosen color per player
int chosenColour[8]{ 0,0,0,0,0,0,0,0 };

//total for a colors show
int totalShow[8]{ 0,0,0,0,0,0,0,0, };

//stores size of players hands
int handSize[8]{ 0,0,0,0,0,0,0,0 };

//stores how many colors:show a person has won
int colourShowWins[8]{ 0,0,0,0,0,0,0,0 };

bool win = false;
// Color class for color change during cout statements, uses windows preset colors
class Color {
public:

	//initializing Color Object
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
//Color Table
/*
*
0   BLACK
1   BLUE
2   GREEN
3   CYAN
4   RED
5   MAGENTA
6   BROWN
7   LIGHTGRAY
8   DARKGRAY
9   LIGHTBLUE
10  LIGHTGREEN
11  LIGHTCYAN
12  LIGHTRED
13  LIGHTMAGENTA
14  YELLOW
15  WHITE

*/


//creates a new card for desired player whenever called
void createCard(int player, int whichCard) {



	for (int k = 0; k <= 2; k++) {

		switch (k) {

		case(0):cardValue[player][whichCard][k] = (rand() % 6) + 1; break;
		case(1):cardValue[player][whichCard][k] = (rand() % 8) + 1; break;
		case(2):cardValue[player][whichCard][k] = (rand() % 8) + 1; break;

		}
		if (cardValue[player][whichCard][1] == chosenColour[player]) {
			cardValue[player][whichCard][3] = 20;
		}
	}

	//increase total handsize
	handSize[player] += 1;
}

//Resets the values for desired player's card when called.
void discardCard(int player, int whichCard) {

	//resets value for discarded card

	for (int k = 0; k <= 2; k++) {
		switch (k) {

		case(0):cardValue[player][whichCard][k] = 0; break;
		case(1):cardValue[player][whichCard][k] = 0; break;
		case(2):cardValue[player][whichCard][k] = 0; break;

		}
	}

	//decrease total handsize
	handSize[player] = handSize[player] - 1;
}

//Checks if a player won the game on their turn start
void checkWin(int player) {
	int card = 1;
	bool cardThere = false;
	if (colourShowWins[player] >= 2) {
		cout << "  / n" << "  / n" << "  / n" << "  / n";
		cout << "--------------------Player " << player + 1 << "wins!--------------------";
		win = true;
	}

	while (true) {
		for (int i = 0; i < 8; i++) {
			if (cardValue[player][i][1] == card) {
				card++;
				cardThere = true;
				exit(0);
			}
		}
		if (card == 8) {
			cout << "  / n" << "  / n" << "  / n" << "  / n";
			cout << "--------------------Player " << player + 1 << "wins!-----------------------";
			win = true;
			exit(0);
		}
		if (cardThere == false) { break; }
	}
}

//will check if the user has entered a bad input or not
int checkInput(int input) {

	int goodInput;

	while (isdigit(input) == 1) {
		cout << "that was not a valid input, please enter a number.\n";
		cin >> input;
	}

	return(input);
}

//checks if a card exists.
int checkCard(int input, int player) {

	input = input - 1;

	if (input > handSize[player]) {
		cout << "That card doesn't exist! Please select a card in your hand.\n";
		cin >> input;
	}
	else {
		return input;
	}

}

//checks if chosen players exist
int isPlayerValid(int playerChoice) {

	while ((playerChoice > numOfPlayers) || (playerChoice == 0)) {
		cout << "that is an invalid number, please pick a player that exists";
		cin >> (playerChoice);
	}
	return(playerChoice);

}

//Displays the player's hand when called
void outputHand(int player) {
	cout << "------------------------------PLAYER " << player + 1 << "'S HAND------------------------------\n\n";

	for (int i = 0; i < 8; i++) {


		cout << "|PLAYER " << player + 1 << "'s ";

		//Declares suit to player
		switch (cardValue[player][i][0]) {

		case(1): cout << "card " << i + 1 << " is: suit " << Color(7) << "Shield,	" << Color(12); break;
		case(2): cout << "card " << i + 1 << " is: suit " << Color(7) << "Triangle,	" << Color(12); break;
		case(3): cout << "card " << i + 1 << " is: suit " << Color(7) << "Ellipse,	" << Color(12); break;
		case(4): cout << "card " << i + 1 << " is: suit " << Color(7) << "Hazard,	" << Color(12); break;
		case(5): cout << "card " << i + 1 << " is: suit " << Color(7) << "Chevron,	" << Color(12); break;
		case(6): cout << "card " << i + 1 << " is: suit " << Color(7) << "Eye,	" << Color(12); break;


		}

		//Declares color to player
		switch (cardValue[player][i][1]) {

		case(0): cout << "card " << i + 1 << " is: There's nothing here....			     |\n"; break;
		case(1): cout << "is Blue,	"; break;
		case(2): cout << "is yellow,	"; break;
		case(3): cout << "is Pink,	"; break;
		case(4): cout << "is Red,		"; break;
		case(5): cout << "is Orange,	"; break;
		case(6): cout << "is Green,	"; break;
		case(7): cout << "is indigo,	"; break;
		case(8): cout << "is Violet,	"; break;
		}

		//Declares Point value to player
		switch (cardValue[player][i][2]) {

		case(1): cout << "is 1 point,  |\n"; break;
		case(2): cout << "is 2 points, |\n"; break;
		case(3): cout << "is 3 points, |\n"; break;
		case(4): cout << "is 4 points, |\n"; break;
		case(5): cout << "is 5 points, |\n"; break;
		case(6): cout << "is 6 points, |\n"; break;
		case(7): cout << "is 7 points, |\n"; break;
		case(8): cout << "is 8 points, |\n"; break;
		}
	}
}

//displays what colour a player has chosen
void chooseColour(int numOfPlayers) {
	int choice;
	for (int i = 0; i <= numOfPlayers; i++) {
		cout << "What colour do you want player" << i << "? /n";
		while (chosenColour[i] == 0) {
			cin >> choice;
			for (int j = 0; j <= numOfPlayers; j++) {
				if (choice == chosenColour[j]) {
					cout << "Colour has already been chosen, choose again";
				}
				else if ((choice != chosenColour[j]) && (j == 8)) {
					chosenColour[i] = choice;
				}
			}
		}
	}
}

//To be called on once during games start, initializes all values for 4 cards per player randomly
int gameStart() {

	//assigns values for all players, cards and data types within cards 
	for (int i = 0; i < numOfPlayers; i++) {
		for (int j = 0; j < 4; j++) {

			createCard(i, j);

		}
	}
	return (0);
}

//Challenge logic, determines winner of challenges
void challenge(int playerTurn) {

	//initialization
	int card1, card2, card3, card4, card5, card6;
	int total1 = 0, total2 = 0, result = 1;
	int suit1, suit2;
	int challenged;
	int cardDraw;

	srand(time(0));

	//rolls for a % chance
	int challengeType = (rand() % 100) + 1;

	//45% chance for challenge Bluff or Snuff
	if (challengeType <= 45 && challengeType >= 0) {


		cout << "You've received a Bluff or Snuff challenge card\n\n";
		cout << "Choose up to 3 cards to discard, if the value of your cards are higher than your opponents you win!"
			" You can then draw a card and can force a discard on them.\n\n";

		cout << "PLAYER " << playerTurn + 1 << ", Choose your first card if you do not wish to discard a card select '0'\n";
		cin >> card1;
		card1 = checkInput(card1);
		card1 = checkCard(card1, playerTurn);

		cout << "PLAYER " << playerTurn + 1 << ", Choose your second card if you do not wish to discard a card select '0'\n";
		cin >> card2;
		card2 = checkInput(card2);
		card2 = checkCard(card2, playerTurn);

		cout << "PLAYER " << playerTurn + 1 << ", Choose your third card if you do not wish to discard a card select '0'\n";
		cin >> card3;
		card3 = checkInput(card3);
		card3 = checkCard(card3, playerTurn);

		cout << "Choose the player you wish to challenge (1-8)\n\n";
		cin >> challenged;



		//checks if the player chose themselves
		while (challenged == playerTurn + 1) {
			cout << "you've selected yourself, please try again!\n";
			cin >> challenged;
		}

		challenged = isPlayerValid(challenged);


		cout << "PLAYER " << challenged << ", you've been challenged!\n";

		//shows the challenged player their hand
		outputHand(challenged - 1);

		cout << "PLAYER " << challenged << ", Choose your first card if you do not wish to discard a card select '0'\n";
		cin >> card4;
		card4 = checkInput(card4);
		card4 = checkCard(card4, challenged - 1);


		cout << "PLAYER " << challenged << ", Choose your second card if you do not wish to discard a card select type '0'\n";
		cin >> card5;
		card5 = checkInput(card5);
		card5 = checkCard(card5, challenged - 1);


		cout << "PLAYER " << challenged << ", Choose your third card if you do not wish to discard a card select type '0'\n";
		cin >> card6;
		card6 = checkInput(card6);
		card6 = checkCard(card6, challenged - 1);



		//calculates the challenge winner

		total1 += (cardValue[playerTurn][card1][2] + cardValue[playerTurn][card2][2] + cardValue[playerTurn][card3][2]);
		total2 += (cardValue[playerTurn][card4][2] + cardValue[playerTurn][card4][2] + cardValue[playerTurn][card6][2]);

		discardCard(challenged - 1, card4);
		discardCard(challenged - 1, card5);
		discardCard(challenged - 1, card6);

		if (total1 < total2) {

			cout << "PLAYER " << challenged<< " wins! would you like to draw a card? '1' for yes '2' for no";
			cin >> cardDraw;
			cardDraw = checkInput(cardDraw);
			if (cardDraw == 1) {
				createCard(playerTurn, handSize[playerTurn]);
			}
			discardCard(challenged - 1, handSize[challenged - 1]);

		}
		else if (total1 > total2) {
			cout << "PLAYER " << playerTurn + 1 << " Wins! would you like to draw a card? '1' for yes '2' for no";
			cin >> cardDraw;
			cardDraw = checkInput(cardDraw);
			if (cardDraw == 1) {
				createCard(challenged - 1, handSize[challenged - 1]);
			}
			discardCard(playerTurn, handSize[playerTurn]);


		}


	}

	//45% chance Suit and boot
	if (challengeType <= 90 && challengeType >= 46) {

		int challengeSuit = (rand() % 6) + 1;

		cout << "You've received a Suit and Boot challenge card\n\n";
		cout << "Select, which card you'd like to commit to the challenge\n";
		cin >> card1;
		card1 = checkInput(card1);
		card1 = checkCard(card1, playerTurn);

		cout << "Choose the player you wish to challenge (1-8)\n\n";
		cin >> challenged;



		//checks if the player chose themselves
		while (challenged == playerTurn + 1) {
			cout << "you've selected yourself, please try again!\n";
			cin >> challenged;
		}
		challenged = isPlayerValid(challenged);


		cout << "PLAYER " << challenged << ", you've been challenged!\n";
		outputHand(challenged - 1);

		cout << "Select, which card you'd like to commit to the challenge\n";
		cin >> card2;
		card2 = checkInput(card2);
		card2 = checkCard(card2, challenged - 1);



		//Checking for winner
		suit1 = (cardValue[playerTurn][card1][0]);
		suit2 = (cardValue[playerTurn][card2][0]);

		discardCard(challenged - 1, card2);
		discardCard(playerTurn, card1);

		if (suit1 == challengeSuit) {

			cout << "Congrats! PLAYER " << playerTurn + 1 << " you've got the winning suit! \nWould you like to draw a card '1' for yes and '2' for no?\n";
			cin >> cardDraw;
			cardDraw = checkInput(cardDraw);
			if (cardDraw == 1) {
				createCard(playerTurn, handSize[playerTurn]);
			}
			discardCard(challenged - 1, handSize[challenged - 1]);
		}
		else if (suit2 == challengeSuit) {
			cout << "Congrats! PLAYER " << playerTurn + 1 << " you've got the winning suit! \nWould you like to draw a card '1' for yes and '2' for no?\n";
			cin >> cardDraw;
			cardDraw = checkInput(cardDraw);
			if (cardDraw == 1) {
				createCard(challenged - 1, handSize[challenged - 1]);
			}
			discardCard(playerTurn, handSize[playerTurn]);
		}


		else {

			cout << "It seems noone had the winning suit....\n";

		}


	}

	// 10% Chance for Colors:Show
	if (challengeType <= 100 && challengeType >= 91) {
		int winner = 0;
		int winnerTotal = 0;
		int yesOrNo;

		cout << "You've got a " << Color(4) << "C" << Color(14) << "o" << Color(2) << "l" << Color(3) << "o" << Color(1) << "u" << Color(5) << "r" << Color(15) << "s:Show!" << Color(4) << "\n\n";
		cout << "Would you like to initiate a Colors Show? \n"
			"Every player will discard their entire hand and the winner will be decided by the person with the highest point total. '1' for Yes, '0' for No." << Color(12);
		cin >> yesOrNo;
		yesOrNo = checkInput(yesOrNo);

		if (yesOrNo == 1) {

			//Determines winner of colors:Show
			for (int a = 0; a < 8; a++) {
				totalShow[a] = 0;
				for (int b = 0; b < handSize[a]; b++) {

					//adds value of card to total per player
					totalShow[a] += cardValue[a][b][2];

					//if the sum of a players hands point total is greater than the previous highest sum, sets the new sum as player total
					if (b = handSize[a]) {
						cout << "PLAYER " << a << "'s total is" << totalShow[a] << endl << endl;
					}

					if (totalShow[a] >= winnerTotal) {

						winner = a;
						cout << "PLAYER " << winner << " Wins the Colors:Show! With a total of" << totalShow[a] << endl << endl;
						winnerTotal = totalShow[a];



					}

				}

			}

			//resets card value for every player
			for (int i = 0; i < 8; i++) {

				for (int j = 0; j < 8; j++) {

					for (int k = 0; k < 3; k++) {
						cardValue[i][j][k] = 0;
					}

				}

			}

			for (int c = 0; c < 8; c++) {
				totalShow[c] = 0;
			}

			//resets all player hands
			gameStart();

		}



		// increases the winners win counter by 1
		colourShowWins[winner] += 1;
	}
}




int main()
{

	int timeLimit;
	int playGame;
	int playerTurn = 0;

	system("Color 0C");
	// Space
	std::cout << "\n";

	// Asking for the number of players required for the game 
	std::cout << "Insert a number of players (2 - 8 players): ";
	std::cin >> numOfPlayers;
	numOfPlayers = checkInput(numOfPlayers);

	// While loop that makes sure that the number of players are valid (between 2 - 8) 
	while (numOfPlayers <= 1 || numOfPlayers >= 9) {
		std::cout << numOfPlayers << " is an invalid amount of players please enter another amount:\n";
		std::cout << "Insert a number of players (2 - 8 players): \n";
		std::cin >> numOfPlayers;
		numOfPlayers = checkInput(numOfPlayers);
	}

	cout << "-------------------------------------------------------------------------\n\n";


	// Starting the game or reading the rules; 
	std::cout << "Would you like to start the game or read the rules?: (enter 1 or 2)\n";
	std::cout << "	1. Start the game\n";
	std::cout << "	2. View the rules\n";
	std::cin >> playGame;
	playGame = checkInput(playGame);


	// While loop that makes sure the player enter 1 or 2; 
	while (playGame != 1 && playGame != 2) {
		std::cout << playGame << " is not a valid option try again\n";
		std::cout << "Would you like to start the game or read the rules?: (enter 1 or 2)\n";
		std::cout << "		1. Start the game\n";
		std::cout << "		2. View the rules\n";
		std::cin >> playGame;
		playGame = checkInput(playGame);
	}

	// Space
	cout << "-------------------------------------------------------------------------\n";

	// if statement to view the rules 
	while (playGame == 2) {
		std::cout << "RULES: \n";
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
		std::cout << "	1. Start the game\n";
		std::cout << "	2. View the rules\n";

		std::cin >> playGame;
		playGame = checkInput(playGame);

	}

	//Starts the game when player chooses
	if (playGame == 1) {
		int cardDraw;

		(numOfPlayers);

		gameStart();
	while (win==false) {


			checkWin(playerTurn);

			cout << "It's player " << playerTurn + 1 << "'s turn:\n";
			cout << "How many cards would you like to draw?\n'0' for none \n'1' for one \n'2' for two";

			cin >> cardDraw;
			for (int z = 0; z < cardDraw; z++) {
				createCard(playerTurn, handSize[playerTurn]);
			}

			cout << "It's PLAYER " << playerTurn + 1 << "'s turn: Your hand is : \n";
			outputHand(playerTurn);


			cout << "-------------------------------------------------------------------------\n\n";

			cout << "Time to draw a challenge card!\n";
			challenge(playerTurn);

		
			playerTurn++;
		}
	}
}


