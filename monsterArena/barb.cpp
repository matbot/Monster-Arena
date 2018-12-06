/*********************************************
 * *Author: Mathew McDade
 * *Date: Sat Nov 19 20:34:40 PST 2016
 * *Description: Barbarian class implementation.
 * *********************************************/
#include "barb.hpp"
#include "utils.hpp"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

/*************************
 * Barbarian Constructor
 * **********************/
Barb::Barb(string n, string t):Creature(0,12,n,t){}

/************************
 * Barbarian Destructor
 * *********************/
Barb::~Barb(){}

/*****************
 * getCreature()
 * **************/
string Barb::getCreature()
{
	return "Barbarian";
}

/************
 * attack()
 * *********/
int Barb::attack()
{
	int attackVal = (randInt(1,6) + randInt(1,6));
	cout << "Barbarian rolls a " << attackVal << " attack!" << endl;
	return attackVal;
}

/***********
 * defend()
 * ********/
void Barb::defend(int opponentAttack)
{
	int defense = (randInt(1,6) + randInt(1,6));
	int damage = (opponentAttack - defense);
	cout << "Barbarian rolls a " << defense << " defense, and takes ";
	if(damage>0)
	{
		cout << damage << " damage." << endl;
		strength -= damage;
	}
	else if(damage<1)
		cout << "0 damage." << endl;
	return;
}

