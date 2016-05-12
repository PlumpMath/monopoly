/*
 * Card.cpp
 *
 *  Created on: May 12, 2016
 *      Author: Wen-Jye
 */

#include "Card.h"
#include <string>
#include <iostream>
using namespace std;

Card::Card()
{
}
Card::Card(char a, int b):suit(a), rank(b)
{
}

int Card::getRank() const{
	return rank;
}

char Card::getSuit() const{
	return suit;
}
void Card::displayCard(ostream& outS) const{
	string s;

    switch(suit){
        case 'c': s="Club";
        case 'd': s="Diamond";
        case 'h': s="Heart";
        case 's': s="Spade";
    }
    switch(rank){
        defult: outS<<s<<rank<<endl;
        case 11: outS<<s<<'J'<<endl;
        case 12: outS<<s<<'Q'<<endl;
        case 13: outS<<s<<'K'<<endl;
        case 14: outS<<s<<'A'<<endl;
    }
}
