/*
 * City.h
 *
 *  Created on: May 12, 2016
 *      Author: Wen-Jye
 */

#ifndef CITY_H_
#define CITY_H_
#include <iostream>
#include <string>
using namespace std;
class City {
private:
	int id, ownerID, xcoord, ycoord;
	double value, charge;
	string cityname, owner;
	City *nextCity;
public:
	City();
	City(int id, string nextCity, double value, int x, int y );

	double getValue() const;
	double getCharge() const;
	string getCityName() const;
	string getCityOwner() const;
	int getCityID() const;
	int getOwnerId() const;
	int getX() const;
	int getY() const;

	void setOwener(int id,string owner);

	void printCity();
};

#endif /* CITY_H_ */
