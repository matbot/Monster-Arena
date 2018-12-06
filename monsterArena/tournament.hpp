/*********************************************
 * *Author: Mathew McDade
 * *Date: Sat Nov 19 21:01:35 PST 2016
 * *Description: Tournament class header.
 * This is the primary container for game
 * pieces and functions.
 * *********************************************/

#ifndef MMCD_TOURNAMENT_HPP
#define MMCD_TOURNAMENT_HPP

#include "creatureQueue.hpp"
#include "creatureStack.hpp"



class Tournament
{
private:
	CreatureQueue teamOne; //include team score as cQ member variable.
	CreatureQueue teamTwo;
	CreatureStack loserStack;

public:
	Tournament();
	~Tournament();

	void buildTeams(int);
	void fightTeams(); //dequeue a player from each team into an Arena object, then fight.
	void printResults();
	void runGame();
};
#endif
