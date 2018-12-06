/*********************************************
 * *Author: Mathew McDade
 * *Date: Sat Nov 19 21:03:57 PST 2016
 * *Description: Vamp class implementation.
 * *********************************************/
#include "vamp.hpp"
#include "utils.hpp"
#include <iostream>
using std::cout;
using std::endl;

/*******************
 * Vamp Constructor
 * ****************/
Vamp::Vamp(string n, string t):Creature(1,18,n,t)
{
	//passes values to base class constructor.
}

/******************
 * Vamp Destructor
 * ***************/
Vamp::~Vamp()
{
	//nothing.
}

/****************************************************
 * getCreature(): returns Creature type in a string.
 * *************************************************/
string Vamp::getCreature()
{
	return "Vampire";
}

/*********************************************
 * charm(): 50% chance of returning true.
 * If true, opponents attack does no damange.
 * *******************************************/
bool Vamp::charm()
{
	int charmVal = randInt(0,100);
	if(charmVal >= 50)
		return true;
	else
		return false;
}

/******************************
 * attack(): virtual function
 * ***************************/
int Vamp::attack()
{
	int attackVal = randInt(1,12);
	cout << "Vampire rolls a " << attackVal << " attack!" << endl;
	return attackVal;
}

/*********************************************
 * defend(): calls charm() first to determine
 * if the attack may be mitigated.
 * *******************************************/
void Vamp::defend(int opponentAttack)
{
	if(charm()) //checks charm before evaluating attack.
	{
		cout << "Vampire has charmed his opponent! His opponent just stands there drooling."
			<< endl;
		return;
	}
	else
	{
		int defense = (randInt(1,6));
		int damage = (opponentAttack - (defense + armor));
		cout << "Vampire rolls a " << defense << " defense, has " << armor
			<< " armor, and takes ";
		if(damage>0)
		{
			cout << damage << " damage." << endl;
			strength -= damage;
		}
		else if(damage<1)
			cout << "0 damage." << endl;
	}
	return;
}
