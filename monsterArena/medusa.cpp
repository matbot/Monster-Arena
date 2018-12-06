/*********************************************
 * *Author: Mathew McDade
 * *Date: Sat Nov 19 21:01:18 PST 2016
 * *Description: Medusa class implementation.
 * *********************************************/
#include "medusa.hpp"
#include "utils.hpp"
#include <iostream>
using std::cout;
using std::endl;
using std::string;

/*********************
 * Medusa Constructor
 * ******************/
Medusa::Medusa(string n, string t):Creature(3,8,n,t){}

/********************
 * Medusa Destructor
 * *****************/
Medusa::~Medusa(){}

/*****************
 * getCreature()
 * **************/
string Medusa::getCreature()
{
	return "Medusa";
}

/***********
 * attack()
 * ********/
int Medusa::attack()
{
	int attackVal = (randInt(1,6) + randInt(1,6));
	if(attackVal==12) //if a 12 is rolled, the *glare* special ability is used.
	{
		cout << "Medusa glares! Her opponent turns to stone!" << endl;
		return 0; //a zero is passed to the calling function to indicate the special ability.
	}			//0 works because it will never be a valid die roll.
	else
	{
		cout << "Medusa rolls a " << attackVal << " attack!" << endl;
		return attackVal;
	}
}

/***********
 * defend()
 * ********/
void Medusa::defend(int opponentAttack)
{
	int defense = (randInt(1,6));
	int damage = (opponentAttack - (defense + armor));
	cout << "Medusa rolls a " << defense << " defense, has " << armor << " armor, and takes ";
	if(damage>0)
	{
		cout << damage << " damage." << endl;
		strength -= damage;
	}
	else if(damage<1)
		cout << "0 damage." << endl;
	return;
}

