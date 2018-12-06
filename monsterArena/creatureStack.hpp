/***********************************************
 * *Author: Mathew McDade
 * *Date: Sat Nov 19 20:48:37 PST 2016
 * *Description: Stack-like, LIFO, class for
 * storing pointers to Creature class objects.
 * *********************************************/
#ifndef MMCD_CREATURESTACK_HPP
#define MMCD_CREATURESTACK_HPP

#include "creature.hpp"

class CreatureStack
{
private:
	class StackNode
	{
		friend class CreatureStack;
		Creature* creature;
		StackNode* next;

		StackNode(Creature* nextCritter, StackNode* nextNode = NULL)
		{
			creature = nextCritter;
			next = nextNode;
		}
	};
	StackNode* top;

public:
	CreatureStack();
	~CreatureStack();
	void push(Creature*);
	Creature* pop();
	bool isEmpty() const;
	void clear();
};
#endif
