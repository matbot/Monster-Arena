/*********************************************
 * *Author: Mathew McDade
 * *Date: Sat Nov 19 21:01:03 PST 2016
 * *Description: Medusa class header (sssssss).
 * *********************************************/
#ifndef MMCD_MEDUSA_HPP
#define MMCD_MEDUSA_HPP

#include "creature.hpp"
using std::string;

class Medusa: public Creature
{
private:

public:
	Medusa(string,string);
	~Medusa();

	virtual string getCreature();
	virtual int attack();
	virtual void defend(int);
};

#endif
