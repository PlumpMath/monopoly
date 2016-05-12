/*
 * CardDeck.cpp
 *
 *  Created on: May 12, 2016
 *      Author: Wen-Jye
 */

#include "CardDeck.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include "Card.h"
using namespace std;

//Constructors

CardDeck::CardDeck()
{
	for(int i=2;i<=14;i++){
		theDeck.push_back(Card('s', i));
		theDeck.push_back(Card('d', i));
		theDeck.push_back(Card('h', i));
		theDeck.push_back(Card('c', i));
	}
}

//Methods

void CardDeck:: shuffleDeck(){
	random_shuffle( theDeck.begin(), theDeck.end());
}
Card CardDeck:: draw(){
	Card d(theDeck[0].getSuit(),theDeck[0].getRank());
	theDeck.erase(theDeck.begin());
	theDeck.push_back(d);
	return d;
}
