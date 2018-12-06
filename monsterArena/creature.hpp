/*********************************************
 * *Author: Mathew McDade
 * *Date: Sat Nov 19 20:35:47 PST 2016
 * *Description: Pure virtual base class.
 * *********************************************/

#ifndef MMCD_CREATURE_HPP
#define MMCD_CREATURE_HPP

#include <string>
using std::string;

class Creature
{
private:
protected: //made these variables protected so derived class may treat them as members.
	int armor;
	int strength;
	int strengthInitial;
	string name;
	string team;
public:
	Creature(int,int,string,string);
	virtual ~Creature();

	int getStrength();
	string getName();
	string getTeam();
	void recover();
	virtual string getCreature() = 0;
	virtual int attack() = 0;
	virtual void defend(int) = 0;
};

#endif
