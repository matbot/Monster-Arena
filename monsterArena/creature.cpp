/*********************************************
 * *Author: Mathew McDade
 * *Date: Sat Nov 19 20:36:08 PST 2016
 * *Description: Pure virtual base class
 * implementation.
 * *********************************************/

#include "creature.hpp"
#include "utils.hpp"
using std::string;

/************************
 * Creature Constructor
 * *********************/
Creature::Creature(int a, int s, string name, string team)
{
	this->armor = a;
	this->strength = s;
	this->strengthInitial = s;
	this->name = name;
	this->team = team;
}

/************************
 * Creature Destructor
 * *********************/
Creature::~Creature()
{
	//virtual destructore, does nothing.
}

/******************
 * getStrength()
 * **************/
int Creature::getStrength()
{
	return strength;
}

/****************
 * getName()
 * **********/
string Creature::getName()
{
	return this->name;
}

/**************
 * getTeam()
 * *********/
string Creature::getTeam()
{
	return this->team;
}

/************
 * recover()
 * *********/
void Creature::recover()
{
	if(strength!=strengthInitial)
		strength += randInt((strengthInitial-strength));
}
