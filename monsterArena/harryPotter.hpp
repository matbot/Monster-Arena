/***************************************************
 * *Author: Mathew McDade
 * *Date: Sat Nov 19 20:54:20 PST 2016
 * *Description: Harry Potter class implementation.
 * ************************************************/
#ifndef MMCD_HARRYPOTTER_HPP
#define MMCD_HARRYPOTTER_HPP

#include "creature.hpp"
using std::string;

class HarryPotter: public Creature
{
private:
	int extraLives = 1; //member variable specific to Harry, decremented when special ability is used.
public:
	HarryPotter(string,string);
	~HarryPotter();

	virtual string getCreature();
	virtual int attack();
	virtual void defend(int);
};

#endif
