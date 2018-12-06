/*********************************************
 * *Author: Mathew McDade
 * *Date: Sat Nov 19 20:30:30 PST 2016
 * *Description: Arena class header.
 * The arena class has two Creature pointers
 * and a function to make the two creatures
 * battle.
 * *********************************************/

#ifndef MMCD_ARENA_HPP
#define MMCD_ARENA_HPP

#include "creature.hpp"

class Arena
{
private:
	Creature* player1;
	Creature* player2;

public:
	Arena(Creature*,Creature*);
	~Arena();

	int fight();
};

#endif

