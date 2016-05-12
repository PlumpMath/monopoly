/*
 * Card.h
 *
 *  Created on: May 12, 2016
 *      Author: Wen-Jye
 */

#ifndef CARD_H_
#define CARD_H_
#include <iostream>
using namespace std;
class Card {
private:
	char suit;
	int rank;
public:
	Card();
	Card(char suit, int rand);
	int getRank() const;
	char getSuit() const;
	void displayCard(ostream &outS) const;
};

#endif /* CARD_H_ */
