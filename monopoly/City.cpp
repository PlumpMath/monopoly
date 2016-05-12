/*
 * City.cpp
 *
 *  Created on: May 12, 2016
 *      Author: Wen-Jye
 */

#include "City.h"
#include <string>

City::City()
{
}

City::City(int a, string b, double c, int d, int e): id(a), cityname(b), value(c),  xcoord(d), ycoord(e),ownerID(0),charge(value*.2)
{
}

double City::getValue() const{
	return value;

}
double City::getCharge() const{
	return charge;
}
string City::getCityName() const{
	return cityname;
}
string City::getCityOwner() const{
	return owner;
}
int City::getCityID() const{
	return id;
}
int City::getOwnerId() const{
	return ownerID;
}
int City::getX() const{
	return xcoord;
}
int City::getY() const{
	return ycoord;
}

void City::setOwener(int ID,string ownerName){
	ownerID=ID;
	owner=ownerName;
}

void City::printCity()
{
	cout<<"\n\t********"<<cityname<<"********"<<endl;
	cout<<"\tcity id= "<<id<<endl;
	cout<<"\tx: "<<xcoord<<endl;
	cout<<"\ty: "<<ycoord<<endl;
	cout<<"\townerID: "<<ownerID<<endl;
	cout<<"\town by: "<<owner<<endl;
}

