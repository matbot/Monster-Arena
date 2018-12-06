/**************************************************
 * *Author: Mathew McDade
 * *Date: Sat Nov 19 21:02:54 PST 2016
 * *Description: Tournament class implementation.
 * ***********************************************/
#include <iostream>
#include <unistd.h>

#include "tournament.hpp"
#include "arena.hpp"
#include "creatureQueue.hpp"
#include "creatureStack.hpp"
#include "creature.hpp"
#include "barb.hpp"
#include "bluem.hpp"
#include "harryPotter.hpp"
#include "medusa.hpp"
#include "vamp.hpp"
#include "utils.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;

/**************************
 * Tournament constructor
 * ***********************/
Tournament::Tournament()
{
}

/*************************
 * Tournament destructor
 * **********************/
Tournament::~Tournament()
{
	teamOne.clear();
	teamTwo.clear();
	loserStack.clear();
}

/***************
 * buildTeams()
 * ************/
void Tournament::buildTeams(int teamSize)
{
	Creature* player = NULL;
	clearPage();
	cout << "Player One, Build Your Team" << endl;
	for(int i=0;i<teamSize;i++)
	{
		cout << "What type of creature will team member " << i+1 << " be?" << endl;
		cout << "1. Barbarian." << endl;
		cout << "2. Blue Men." << endl;
		cout << "3. Harry Potter." << endl;
		cout << "4. Medusa." << endl;
		cout << "5. Vampire." << endl;
		int creatureChoice = getInt(1,5);

		cout << "What is this creature's name?" << endl;
		string creatureName;
		cin.ignore(256,'\n');
		getline(cin,creatureName);

		switch(creatureChoice){
			case 1:{
				player = new Barb(creatureName,"Team One");
				teamOne.enqueue(player);
				break; }
			case 2:{
				player = new Bluem(creatureName,"Team One");
				teamOne.enqueue(player);
				break; }
			case 3:{
				player = new HarryPotter(creatureName,"Team One");
				teamOne.enqueue(player);
				break; }
			case 4:{
				player = new Medusa(creatureName,"Team One");
				teamOne.enqueue(player);
				break; }
			case 5:{
				player = new Vamp(creatureName,"Team One");
				teamOne.enqueue(player); }
		}
		player = NULL;
	}

	player = NULL;
	clearPage();
	cout << "Player Two, Build Your Team" << endl;
	for(int i=0;i<teamSize;i++)
	{
		cout << "What type of creature will team member " << i+1 << " be?" << endl;
		cout << "1. Barbarian." << endl;
		cout << "2. Blue Men." << endl;
		cout << "3. Harry Potter." << endl;
		cout << "4. Medusa." << endl;
		cout << "5. Vampire." << endl;
		int creatureChoice = getInt(1,5);

		cout << "What is this creature's name?" << endl;
		string creatureName;
		cin.ignore(256,'\n');
		getline(cin,creatureName);

		switch(creatureChoice){
			case 1:{
				player = new Barb(creatureName,"Team Two");
				teamTwo.enqueue(player);
				break; }
			case 2:{
				player = new Bluem(creatureName,"Team Two");
				teamTwo.enqueue(player);
				break; }
			case 3:{
				player = new HarryPotter(creatureName,"Team Two");
				teamTwo.enqueue(player);
				break; }
			case 4:{
				player = new Medusa(creatureName,"Team Two");
				teamTwo.enqueue(player);
				break; }
			case 5:{
				player = new Vamp(creatureName,"Team Two");
				teamTwo.enqueue(player); }
		}
		player = NULL;
	}
	cout << endl << "Team building complete." << endl;
	return;
}

/****************
 * fightTeams()
 * *************/
void Tournament::fightTeams()
{
	while(!teamOne.isEmpty() && !teamTwo.isEmpty())
	{
		clearPage();
		Creature* t1C = teamOne.dequeue();
		Creature* t2C = teamTwo.dequeue();
		Arena roadHouse(t1C,t2C);
		int winner = roadHouse.fight();
		switch(winner){
			case 1:{
				t1C->recover();
				teamOne.enqueue(t1C);
				loserStack.push(t2C);
				++teamOne;
				break; }
			case 2:{
				t2C->recover();
				teamTwo.enqueue(t2C);
				loserStack.push(t1C);
				++teamTwo;
				break; }
		}
	}
	return;
}

/*****************
 * printResults()
 * **************/
void Tournament::printResults()
{
	clearPage();
	Creature* survivor = NULL;
	Creature* fallen = NULL;
	cout << "Tournament Final Results!" << endl << endl;
	if(teamOne.getTeamScore()>teamTwo.getTeamScore())
	{
		cout << "Team One Wins!" << endl << endl;
		cout << "Survivors:" << endl;
		int i=1;
		while(!teamOne.isEmpty())
		{
			survivor = teamOne.dequeue();
			cout << i << " " << survivor->getTeam() << " " << survivor->getCreature() << " ";
			cout << survivor->getName() << " Remaining Strength: " << survivor->getStrength();
			cout << endl << endl;
			delete survivor;
			survivor = NULL;
			i++;
		}
		while(!loserStack.isEmpty())
		{
			cout << "Fallen:" << endl;
			fallen = loserStack.pop();
			cout << i << " " << fallen->getTeam() << " " << fallen->getCreature() << " ";
			cout << fallen->getName() << endl << endl;
			delete fallen;
			fallen = NULL;
			i++;
		}
	}
	else if(teamOne.getTeamScore()<teamTwo.getTeamScore())
	{
		cout << "Team Two Wins!" << endl << endl;
		cout << "Survivors:" << endl;
		int i=1;
		while(!teamTwo.isEmpty())
		{
			survivor = teamTwo.dequeue();
			cout << i << " " << survivor->getTeam() << " " << survivor->getCreature() << " ";
			cout << survivor->getName() << " Remaining Strength: " << survivor->getStrength();
			cout << endl << endl;
			delete survivor;
			survivor = NULL;
			i++;
		}
		while(!loserStack.isEmpty())
		{
			cout << "Fallen:" << endl;
			fallen = loserStack.pop();
			cout << i << " " << fallen->getTeam() << " " << fallen->getCreature() << " ";
			cout << fallen->getName() << endl << endl;
			delete fallen;
			fallen = NULL;
			i++;
		}
	}
}

/************
 * runGame()
 * *********/
void Tournament::runGame()
{
	cout << "Welcome to Mathew McDade's Creature Tournament implementation." << endl << endl;
	cout << "How many fighter's will each team have?" << endl;
	int num = getInt();
	buildTeams(num);
	fightTeams();
	printResults();
	cout << "Enter any character to end the Tournament." << endl;
	char nothing;
	cin >> nothing;
	return;
}
