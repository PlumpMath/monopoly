/*
 * Player.cpp
 *
 *  Created on: May 12, 2016
 *      Author: Wen-Jye
 */

#include "Player.h"
#include "City.h"
#include <queue>
#include <iostream>
using namespace std;


Player::Player()
{
}

Player::Player(string a, double b, int c):name(a), money(b),playerID(c),cityX(0), cityY(0)
{
}

void Player::loseMoney(double m){
	money-=m;
}
void Player::gainMoney(double m){
	money+=m;
}


double Player::getMoney() const
{
	return money;
}
string Player::getName() const
{
	return name;
}
vector<int> Player::getCityOwned() const
{
	return cityOwned;
}
int Player::getPlayerID() const
{
	return playerID;
}
int Player::getCityX() const
{
	return cityX;
}
int Player::getCityY() const
{
	return cityY;
}
queue <City> Player::path(int step, vector<City> cityset){
	queue<City> p;
	int loc;
	if((cityX>1&&cityY<5)||cityY==4){
		p=shortcutpath(step, p, cityset);
	}
	else if(cityX<2){
		if((cityX==1&&step<6)||step<5-cityY){
			p=shortcutpath(step, p, cityset);
		}
		else if(cityX==1&&step==6){
			p.push(cityset[15]);
			for(int i=0;i<5;i++){
				p.push(cityset[i]);
			}
			p.push(cityset[16]);
		}
		else if(cityY<5){
			for(int i=cityY;i<5;i++){
				p.push(cityset[i]);
			}
			for(int i=16;i<step+cityY+12;i++){
				p.push(cityset[i]);
			}
		}
		else{
			for(int i=cityY+11;i<step+cityY+12;i++){
				p.push(cityset[i]);
			}
		}
	}
	else if(cityX>0&&cityY==7){
		if(step<=6-cityX){
			for(int i=cityX+18;i<step+cityX+19;i++){
				p.push(cityset[i]);
			}
		}
		else{
			loc=step+cityX+1;
			for(int i=cityX+18;i<24;i++){
				p.push(cityset[i]);
			}
			for(int i=8;i<step+cityX+2;i++){
				p.push(cityset[i]);
			}
		}
	}
	else if(cityY>4&&cityX==4){
		if(cityY==5){
			p.push(cityset[24]);
			for(int i=8;i<step+cityY+3;i++){
				p.push(cityset[i]);
			}
		}
		else if(cityY==6&&step>1){
			p.push(cityset[23]);
			p.push(cityset[24]);
			for(int i=8;i<step+cityY+1;i++){
				p.push(cityset[i]);
			}
		}
		else{
			p.push(cityset[23]);
			p.push(cityset[24]);
		}
	}
	return p;
}
City Player::move(int step, vector<City> cityset){
	int loc;
	if((cityX>1&&cityY<5)||cityY==4){
		loc=shortcut(step);
	}
	else if(cityX<2){
		if((cityX==1&&step<6)||step<5-cityY){
			loc=shortcut(step);
		}
		else if(cityX==1&&step==6){
			loc=16;
		}
		else{
			loc=step+cityY+11;
		}
	}
	else if(cityX>0&&cityY==7){
		if(step<=6-cityX){
			loc=step+cityX+18;
		}
		else{
			loc=step+cityX+1;
		}
	}
	else if(cityY>4&&cityX==4){
		if(cityY==5){
			loc=step+cityY+2;
		}
		else if(cityY==6&&step>1){
			loc=step+cityY;
		}
		else{
			loc=24;
		}
	}
	return cityset[loc];
}
int Player::shortcut(int i){
	int preloc,loc;
	if(cityX<=cityY){
		preloc=cityX+cityY;
	}
	else{
		preloc=16-cityX-cityY;
	}
	loc=preloc+i;
	if(loc>15)loc-=16;
	return loc;
}
queue <City> Player::shortcutpath(int die, queue <City> p, vector<City> cityset){
	int preloc,loc,j;
	if(cityX<=cityY){
		preloc=cityX+cityY;
	}
	else{
		preloc=16-cityX-cityY;
	}
	loc=preloc+die;
	for(int i=preloc;i<=loc;i++){
		j=i;
		if(j>15)j-=16;
		p.push(cityset[j]);
	}
	return p;
}
void Player::setCityX(int x){
	cityX=x;
}
void Player::setCityY(int y){
	cityY=y;
}

void Player::addCity(int cityID){
	cityOwned.push_back(cityID);
}

void Player::printPlayer(){
	cout<<"\n\t********"<<name<<"********"<<endl;
	cout<<"\tplayerID="<<playerID<<endl;
	cout<<"\tplayer_name="<<name<<endl;
	cout<<"\tplayer_money="<<money<<endl;
	cout<<"\tposition=("<<cityX<<','<<cityY<<')'<<endl;
}
