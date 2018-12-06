/**************************************************
 * *Author: Mathew McDade
 * *Date: Sat Nov 19 20:50:43 PST 2016
 * *Description: Stack-like class implementation.
 * ***********************************************/
#include <iostream>
#include "creatureStack.hpp"

using std::cout;
using std::endl;

/**************
 * Constructor
 * ***********/
CreatureStack::CreatureStack()
{
	top = NULL;
}

/**************
 * Destructor
 * ***********/
CreatureStack::~CreatureStack()
{
	clear();
}

/*********
 * push()
 * ******/
void CreatureStack::push(Creature* c)
{
	top = new StackNode(c,top);
}

/********
 * pop()
 * *****/
Creature* CreatureStack::pop()
{
	StackNode* temp;

	if(isEmpty())
	{
		cout << "Empty Stack" << endl;
		return NULL;
	}
	else
	{
		Creature* rC = top->creature;
		temp = top;
		top = top->next;
		delete temp;
		return rC;
	}
}

/*************
 * isEmpty()
 * **********/
bool CreatureStack::isEmpty() const
{
	if(top==NULL)
		return true;
	else
		return false;
}

/**********
 * clear()
 * *******/
void CreatureStack::clear()
{
	while(!isEmpty())
	{
		Creature* temp = pop();
		delete temp;
	}
}


