/*********************************************
 * *Author: Mathew McDade
 * *Date: Sat Nov 19 20:56:29 PST 2016
 * *Description: The main method.
 * And new linked list class testing drivers.
 * *********************************************/
#include "tournament.hpp"
#include "utils.hpp"
#include <cstdlib>
#include <time.h>

#include "barb.hpp"
#include "bluem.hpp"
#include "harryPotter.hpp"
#include "medusa.hpp"
#include "vamp.hpp"
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	srand(time(NULL));
	int choice = 0;
	while(choice!=2)
	{
		cout << "Would you like to play Creature Tournament?" << endl;
		cout << "1. Play." << endl;
		cout << "2. Quit." << endl;
		choice = getInt(1,2);
		switch(choice){
			case 1:{
				Tournament creatureCup;
				creatureCup.runGame();
				break;}
			case 2: break; }
	}


	/***************************************************************
	* queue-like testing driver*
	CreatureQueue queue;
	Creature* c = new Barb("mOne","M");
	queue.enqueue(c);
	++queue;
	c = new Bluem("nOne","N");
	queue.enqueue(c);
	c = new HarryPotter("oOne","O");
	queue.enqueue(c);
	c = new Medusa("pOne","P");
	queue.enqueue(c);
	c = new Vamp("qOne","Q");
	queue.enqueue(c);
	++queue;
	c = queue.dequeue();
	queue.enqueue(c);
	cout << queue.isEmpty() << endl;
	while(!queue.isEmpty())
	{
		c = queue.dequeue();
		cout << c->getName() << endl;
		delete c;
	}
	cout << queue.isEmpty() << endl;
	cout << queue.getTeamScore() << endl <<endl; //should be 2.
	************************************************************

	**************************************
	CreatureStack stack;
	c = new Barb("mOne","M");
	stack.push(c);
	c = new Bluem("nOne","N");
	stack.push(c);
	c = new HarryPotter("oOne","O");
	stack.push(c);
	c = new Medusa("pOne","P");
	stack.push(c);
	c = new Vamp("qOne","Q");
	stack.push(c);
	c = stack.pop();
	stack.push(c);
	cout << stack.isEmpty() << endl;
	while(!stack.isEmpty())
	{
		c = stack.pop();
		cout << c->getName() << endl;
		delete c;
	}
	cout << stack.isEmpty() << endl;
	**************************************


	******Tournament functions test drivers*********
	Tournament t;

	t.buildTeams(2);
	t.fightTeams();
	*************************************************/

	return 0;
}
