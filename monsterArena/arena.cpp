/*********************************************
 * *Author: Mathew McDade
 * *Date: Sat Nov 19 20:30:58 PST 2016
 * *Description: Arena class implementation.
 * *********************************************/
#include "arena.hpp"
#include "creature.hpp"
#include "vamp.hpp"
#include "barb.hpp"
#include "bluem.hpp"
#include "medusa.hpp"
#include "harryPotter.hpp"
#include "utils.hpp"
#include <iostream>
#include <unistd.h> //for usleep functionality.

using std::cin;
using std::cout;
using std::endl;

Arena::Arena(Creature* p1, Creature* p2)
{				
	this->player1 = p1;
	this->player2 = p2;
}

Arena::~Arena()
{
}

int Arena::fight()
{
	int first = randInt(1,2);
	if(first==1)
	{
		while(player1->getStrength()>0 && player2->getStrength()>0)
		{
			cout << "Player 1:" << endl;
			int attack = player1->attack();
			usleep(75000);
			if(attack==0)
			{
				cout << "Player 1 Wins!" << endl;
				return 1;
			}
			else
			{
				cout << "Player 2:" << endl;
				player2->defend(attack);
				usleep(75000);
			}
			if(player2->getStrength()<1)
			{
				cout << "Player 1 Wins!" << endl;
				return 1;
			}
			cout << endl;
			usleep(1000000);


			cout << "Player 2:" << endl;
			attack = player2->attack();
			usleep(75000);
			if(attack==0)
			{
				cout << "Player 2 Wins!" << endl;
				return 2;
			}
			else
			{
				cout << "Player 1:" << endl;
				player1->defend(attack);
				usleep(75000);
			}
			if(player1->getStrength()<1)
			{
				cout << "Player 2 Wins!" << endl;
				return 2;
			}
			cout << endl;
			usleep(1000000);
		}
	}
	else if(first==2)
	{
		while(player2->getStrength()>0 && player1->getStrength()>0)
		{
			cout << "Player 2:" << endl;
			int attack = player2->attack();
			usleep(75000);
			if(attack==0)
			{
				cout << "Player 2 Wins!" << endl;
				return 2;
			}
			else
			{
				cout << "Player 1:" << endl;
				player1->defend(attack);
				usleep(75000);
			}
			if(player1->getStrength()<1)
			{
				cout << "Player 2 Wins!" << endl;
				return 2;
			}
			cout << endl;
			usleep(1000000);


			cout << "Player 1:" << endl;
			attack = player1->attack();
			usleep(75000);
			if(attack==0)
			{
				cout << "Player 1 Wins!" << endl;
				return 1;
			}
			else
			{
				cout << "Player 2:" << endl;
				player2->defend(attack);
				usleep(75000);
			}
			if(player2->getStrength()<1)
			{
				cout << "Player 1 Wins!" << endl;
				return 1;
			}
			cout << endl;
			usleep(1000000);
		}
	}
	return 0;
}
