/*********************************************
 * *Author: Mathew McDade
 * *Date: Sat Nov 19 21:03:36 PST 2016
 * *Description: Vampire class header.
 * *********************************************/
#ifndef MMCD_VAMP_HPP
#define MMCD_VAMP_HPP

#include "creature.hpp"
using std::string;

class Vamp: public Creature
{
private:

public:
	Vamp(string,string);
	~Vamp();

	virtual string getCreature();
	bool charm(); //specific to Vampire class.
	virtual int attack();
	virtual void defend(int);
};

#endif
