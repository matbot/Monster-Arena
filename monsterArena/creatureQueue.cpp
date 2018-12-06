/*****************************************************
 * *Author: Mathew McDade
 * *Date: Sat Nov 19 20:40:42 PST 2016
 * *Description: Queue-like structure implementation.
 * **************************************************/

#include <iostream>
#include "creatureQueue.hpp"

using namespace std;

/***************
 * Constructor
 * ************/
CreatureQueue::CreatureQueue()
{
	front = NULL;
	rear = NULL;
	teamScore = 0;
}

/****************
 * Destructor
 * ************/
CreatureQueue::~CreatureQueue()
{
	clear();
}

/*************
 * enqueue()
 * **********/
void CreatureQueue::enqueue(Creature* c)
{
	if(isEmpty())
	{
		front = new QueueNode(c);
		rear = front;
	}
	else
	{
		rear->next = new QueueNode(c);
		rear = rear->next;
	}
}

/************
 * dequeue()
 * *********/
Creature* CreatureQueue::dequeue()
{
	QueueNode* temp;
	if(isEmpty())
	{
		cout << "Team is empty." << endl;
		return NULL;
	}
	else
	{
		Creature* rC = front->creature;
		temp = front;
		front = front->next;
		delete temp;
		return rC;
	}
}

/************
 * isEmpty()
 * *********/
bool CreatureQueue::isEmpty() const
{
	if(front==NULL)
		return true;
	else
		return false;
}

/**********
 * clear()
 * *******/
void CreatureQueue::clear()
{
	while(!isEmpty())
	{
		Creature* temp = dequeue();
		delete temp;
	}
}

/*****************
 * getTeamScore()
 * **************/
int CreatureQueue::getTeamScore()
{
	return teamScore;
}

/*****************************************************
 * ++ prefix operator overload: increments teamScore
 * **************************************************/
void CreatureQueue::operator++()
{
	teamScore++;
}
