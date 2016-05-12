/*
 * Player.h
 *
 *  Created on: May 12, 2016
 *      Author: Wen-Jye
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "City.h"
using namespace std;
class Player {
private:
	int cityX, cityY, cityID, playerID;
	double money;
	vector<int> cityOwned;
	string name;
	int shortcut(int i);
	queue <City> shortcutpath(int i, queue <City> p, vector<City> cityset);
public:
	Player();
	Player(string name, double money, int playerID);
	double getMoney() const;
	string getName() const;
	vector <int> getCityOwned() const;
	int getPlayerID() const;
	int getCityX() const;
	int getCityY() const;

	void setCityX(int x);
	void setCityY(int y);

	void loseMoney(double m);
	void gainMoney(double m);
	void addCity(int cityID);
	queue <City> path(int step, vector<City> cityset);
	City move(int step, vector<City> cityset);
	void printPlayer();
};

#endif /* PLAYER_H_ */
