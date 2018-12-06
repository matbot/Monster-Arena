/*****************************************************
 * *Author: Mathew McDade
 * *Date: Sat Nov 19 20:54:46 PST 2016
 * *Description: Harry Potter class implementation.
 * *************************************************/
#include "harryPotter.hpp"
#include "utils.hpp"
#include <iostream>
using std::cout;
using std::endl;
using std::string;

/**************************
 * HarryPotter Constructor
 * ***********************/
HarryPotter::HarryPotter(string n, string t):Creature(0,10,n,t){}

/**************************
 * HarryPotter Destructor
 * ***********************/
HarryPotter::~HarryPotter(){}

/*******************
 * getCreature()
 * **************/
string HarryPotter::getCreature()
{
	return "Harry Potter";
}

/***********
 * attack()
 * ********/
int HarryPotter::attack()
{
	int attackVal = (randInt(1,6) + randInt(1,6));
	cout << "Harry rolls a " << attackVal << " attack!" << endl;
	return attackVal;
}

/***********
 * defend()
 * ********/
void HarryPotter::defend(int opponentAttack)
{
	int defense = (randInt(1,6) + randInt(1,6));
	int damage = (opponentAttack - defense);
	cout << "Harry rolls a " << defense << " defense, and takes ";
	if(damage>0)
	{
		cout << damage << " damage." << endl;
		strength -= damage;
	}
	else if(damage<1)
		cout << "0 damage." << endl;

	if(strength < 1 && extraLives==1)
	{	//if Harry dies, he comes back to life with 20 strength points.
		cout << "Hogwarts: Harry is dead. Long live Harry! Strength = 20!" << endl;
		strength = 20;
		strengthInitial = 20;//had to add line to prevent wonky behavior related to recover().
		extraLives = 0;
	}
	return;
}

