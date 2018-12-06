/*********************************************
 * *Author: Mathew McDade
 * *Date: Sat Nov 19 20:34:59 PST 2016
 * *Description: Blue Men class header.
 * *********************************************/

#ifndef MMCD_BLUEM_HPP
#define MMCD_BLUEM_HPP

#include <string>
using std::string;
#include "creature.hpp"

class Bluem: public Creature
{
private:

public:
	Bluem(string,string);
	~Bluem();

	virtual string getCreature();
	virtual int attack();
	virtual void defend(int);
};

#endif
