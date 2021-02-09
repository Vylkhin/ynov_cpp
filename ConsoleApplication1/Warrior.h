#pragma once

using namespace std;

#include "Character.h"

class Warrior : virtual public Character
{




public:
	Warrior(string name);
	virtual ~Warrior();
	int hammerHit(Character* target);
	int smash();
	int seppuku();
	int takeDamage(int value);
	int takeHealing(int value);
	void checkDead();

};

