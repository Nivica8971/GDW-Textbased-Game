#include <iostream>
#include <math.h>
#include <time.h>
#define cardNumber 4
#define playerCount 2

using namespace std;

//data types 0=suit, 1=colour,2=point value
int main() {
	static int hand[playerCount][cardNumber][3]{ };
	for (int i = 0; i <= playerCount; i++) {
		for (int j = 0; j <= cardNumber; j++) {
			for (int k = 0; k <= 2; k++) {
				switch (k) {
				case(0):hand[i][j][k] = (rand() % 6) + 1;
				case(1):hand[i][j][k] = (rand() % 8) + 1;
				case(2):hand[i][j][k] = (rand() % 8) + 1;

				}
			}
		}
	}
	cout << hand[1][3][2] << endl;
	cout << hand[0][1][0] << endl;
	cout << hand[1][2][0] << endl;
	return (0);
}

