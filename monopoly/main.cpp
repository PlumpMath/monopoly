/*
 * main.cpp
 *
 *  Created on: May 12, 2016
 *      Author: Wen-Jye
 */

#include "main.h"


#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <queue>
#include "Card.h"
#include "CardDeck.h"
#include "Player.h"
#include "City.h"

using namespace std;
CardDeck cards;
ifstream mfin;
ifstream pfin;
City currentCity;
vector <City> city;
vector <Player> player;
queue <City> path;
int rand_int(int a, int b);
void displayMap();
void createUser();
void createMap();
void cityChecker(int i);
void cardGame(int i);
void owenershipChecker(int i);
void printPath();
void buyCity(int i);
void toll(int i);
void currentlyLocated(int i);
void result();

int main()
{
	int die(0),turn;
	createUser();
	createMap();
	cout<<"Please input the turns you want!(integer): ";
	cin>>turn;
	cout<<turn<<endl;
	for(int t=0;t<turn;t++){
		cout<<"\n********Turn"<<t+1<<"********\n"<<endl;
		displayMap();
		for(int i=0;i<4;i++){
			if(i==0){
				cout<<"\n*****player's turn*****"<<endl;

			}
			else{
				cout<<"\n*****computer's turn*****"<<endl;

			}
			die=rand_int(1,6);
			cout<<"\n\tdie result is: "<<die<<endl;
			currentCity=player[i].move(die,city);
			path=player[i].path(die,city);
			currentlyLocated(i);
			player[i].printPlayer();
			currentCity.printCity();
			printPath();
			cityChecker(i);
			owenershipChecker(i);
			displayMap();
		}
		die=0;
	}
	result();
	system("pause");
	return 0;
}

void createUser()
{
	int id;
	double money;
	string temp,name;
	pfin.open("player.txt");
	if(pfin.fail()){
		cerr<<"error opening input file";
		exit(1);
	}
	getline(pfin, temp);
	while(!pfin.eof()){
	pfin>>id>>name>>money;
	player.push_back(Player (name,money,id));
	}
	pfin.close();
}

void createMap()
{
	int id,x,y;
	double value;
	string temp,name;
	mfin.open("extra.txt");
	if(mfin.fail()){
		cerr<<"error opening input file";
		exit(1);
	}
	getline(mfin, temp);
	while(!mfin.eof())
	{
		mfin>>id>>name>>value>>x>>y;
		city.push_back(City (id,name,value,x,y));
	}
	mfin.close();
}

void cardGame(int i){
	cards.shuffleDeck();
	Card c1=cards.draw();
	Card c2=cards.draw();
	int r1(c1.getRank()),r2(c2.getRank());
	char s1(c1.getSuit()),s2(c2.getSuit());
	cout<<"\t********Card Game********"<<endl;
	cout<<"\nThe first card you drew is: ";
	c1.displayCard(cout);
	cout<<"The second card you drew is: ";
	c2.displayCard(cout);
	int m(100*(r1+r2));
	if((s1=='c'||s1=='s')&&(s2=='c'||s2=='s')){
		player[i].gainMoney(100*(r1+r2));
		cout<<"\n\t***Two cards have black color, you win "<<m<<"!***"<<endl;
	}
	else if((s1=='h'||s1=='d')&&(s2=='h'||s2=='d')){
		cout<<"\n\t***Two cards have red color,you win "<<m<<"!***"<<endl;
		player[i].gainMoney(100*(r1+r2));
	}
	else{
		cout<<"\n\t***Two cards have different color, you lose card game!***"<<endl;
	}
}
void displayMap(){
	int x1(player[0].getCityX()),
		x2(player[1].getCityX()),
		x3(player[2].getCityX()),
		x4(player[3].getCityX()),
		y1(player[0].getCityY()),
		y2(player[1].getCityY()),
		y3(player[2].getCityY()),
		y4(player[3].getCityY());
	for(int j=0;j<5;j++){
		for(int k=0;k<8;k++){
			if(j==0||j==4||k==0||k==4||k==7){
				if(j==x1 && k==y1){
					cout<<"1";
				}
				else if(j==x2 && k==y2){
					cout<<"2";
				}
				else if(j==x3 && k==y3){
					cout<<"3";
				}
				else if(j==x4 && k==y4){
					cout<<"4";
				}
				else{
					cout<<'*';
				}
			}
			else if(k==1){
					cout<<"   ";
			}
			else if(k==5){
					cout<<"  ";
			}
		}
		cout<<endl;
	}
}
void cityChecker(int i){
	int x(currentCity.getX()),
		y(currentCity.getY());
	if((x==0&&y==1)||(x==1&&y==4)||(x==4&&y==3)||(x==3&&y==0)){
		cout<<"\nYou are in the good city, play card game!\n"<<endl;
		cardGame(i);
	}
	else if((x==0&&y==2)||(x==2&&y==4)||(x==4&&y==2)||(x==2&&y==0)){
		double m(500);
		cout<<"\n\t***You are in the bad city, you lose "<<m<<"!***"<<endl;
		player[i].loseMoney(m);
	}
}
void owenershipChecker(int i){
	if(currentCity.getOwnerId()==0){
		cout<<"\nThis city does not have owner."<<endl;
		cout<<"It is worth "<<currentCity.getValue()<<endl;
		if(i==0){
			if(player[i].getMoney()<currentCity.getValue()){
				cout<<"\n\t***You do not have money to buy this city!***"<<endl;
			}
			else{
				char a;
				cout<<"\n\tDo you want to buy it? (input 'y' or 'n') ";
				cin>>a;
				if (isupper(a)) a=tolower(a);
				if(a=='y'){
					cout<<"\n\t***You just bought "<<currentCity.getCityName()<<"!***\n"<<endl;
					buyCity(i);
				}
				else{
					cout<<"\n\t***You did not buy "<<currentCity.getCityName()<<"!***\n"<<endl;
				}
			}
		}
		else{
			int buy=rand_int(1,2);
			if(buy==1){
				cout<<"\n\t***"<<player[i].getName()<<" just bought "<<currentCity.getCityName()<<"!***\n"<<endl;
				buyCity(i);
			}
			else{
				cout<<"\n\t***"<<player[i].getName()<<" did not buy "<<currentCity.getCityName()<<"!***\n"<<endl;
			}
		}
	}
	else{
		cout<<"\n\t***"<<currentCity.getCityName()<<" is "<<currentCity.getCityOwner()<<"'s city!***\n"<<endl;
		toll(i);
	}
}
void buyCity(int i){
	city[currentCity.getCityID()-1].setOwener(player[i].getPlayerID(),player[i].getName());
	player[i].addCity(currentCity.getCityID());
	player[i].loseMoney(currentCity.getValue());
}
void toll(int i){
	player[i].loseMoney(currentCity.getCharge());
	player[currentCity.getOwnerId()-1].gainMoney(currentCity.getCharge());
	cout<<"Player "<<player[i].getName()<<" lose "<<currentCity.getCharge()<<" at "<<currentCity.getCityName()<<endl;
	cout<<"Player "<<player[currentCity.getOwnerId()-1].getName()<<" get "<<currentCity.getCharge()<<" at "<<currentCity.getCityName()<<"\n"<<endl;
}
void currentlyLocated(int i){
	player[i].setCityX(currentCity.getX());
	player[i].setCityY(currentCity.getY());
}
void result(){
	vector<int> a;

	int x(0);
	cout<<"\n\t********RESULT!********"<<endl;
	for(int i=0; i<4;i++){
		a=player[i].getCityOwned();
		player[i].printPlayer();
		cout<<"\n\tcity owned:";
		while(x<a.size()){
			cout<<city[a[x]-1].getCityName()<<". ";
			x++;
		}
		cout<<"\n"<<endl;
		x=0;
	}
}
void printPath(){
	cout<<"\n\t********PATH********"<<endl;
	while (!path.empty() ) {
		cout<<"\t"<<path.front().getCityName() << endl;
		path.pop();
	}
}
int rand_int(int a, int b){
	return rand()%(b-a+1)+a;
}
