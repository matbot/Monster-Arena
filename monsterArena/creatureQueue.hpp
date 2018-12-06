/*********************************************
 * *Author: Mathew McDade
 * *Date: Sat Nov 19 20:36:28 PST 2016
 * *Description: Header file for a queue-like,
 * FIFO, linked list class.
 * *********************************************/

#ifndef MMCD_CREATUREQUEUE_HPP
#define MMCD_CREATUREQUEUE_HPP

#include "creature.hpp"

class CreatureQueue
{
private:
	class QueueNode
	{
		friend class CreatureQueue;
		Creature* creature;
		QueueNode* next;
		QueueNode(Creature* c, QueueNode* next1 = NULL)
		{
			creature = c;
			next = next1;
		}
	};

	QueueNode* front;
	QueueNode* rear;

	int teamScore;

public:
	CreatureQueue();
	~CreatureQueue();

	void enqueue(Creature*);
	Creature* dequeue();
	bool isEmpty() const;
	void clear();

	int getTeamScore();
	void operator++();
};
#endif
