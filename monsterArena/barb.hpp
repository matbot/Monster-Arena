/*********************************************
 * *Author: Mathew McDade
 * *Date: Sat Nov 19 20:34:23 PST 2016
 * *Description: Barbarian class header.
 * *********************************************/
#ifndef MMCD_BARB_HPP
#define MMCD_BARB_HPP

#include <string>
using std::string;
#include "creature.hpp"

class Barb: public Creature
{
private:

public:
	Barb(string,string);
	~Barb();

	virtual string getCreature();
	virtual int attack();
	virtual void defend(int);
};

#endif
