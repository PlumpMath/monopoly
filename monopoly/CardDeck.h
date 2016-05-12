/*
 * CardDeck.h
 *
 *  Created on: May 12, 2016
 *      Author: Wen-Jye
 */

#ifndef CARDDECK_H_
#define CARDDECK_H_
#include <iostream>
#include <vector>
#include "Card.h"
using namespace std;
class CardDeck {
private:
	vector<Card>theDeck;
public:
	CardDeck();
	void shuffleDeck();
	Card draw();
};

#endif /* CARDDECK_H_ */
