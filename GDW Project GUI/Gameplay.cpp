#include <iostream>
#include <math.h>
#include <time.h>
#include "Gameplay.h"
#define cardNumber 4
#define playerCount 2

using namespace std;

//data types 0=suit, 1=colour,2=point value
static int hand[playerCount][cardNumber][3]{ };
void createCard(int player,int cardNum) {
	for (int k = 0; k <= 2; k++) {
		switch (k) {
		case(0):hand[player][cardNum][k] = (rand() % 6) + 1;
		case(1):hand[player][cardNum][k] = (rand() % 8) + 1;
		case(2):hand[player][cardNum][k] = (rand() % 8) + 1;
		}
	}
}
int gameStart() {
	
	//assigns values for all players, cards and data types within cards 
	for (int i = 0; i <= playerCount; i++) {
		for (int j = 0; j <= cardNumber; j++) {
			createCard(i, j);
		}
	}
	return (0);
}

