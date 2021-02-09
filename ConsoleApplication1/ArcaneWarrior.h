#pragma once

#include "Mage.h"
#include "Warrior.h"

class ArcaneWarrior : public Mage, public Warrior
{
	

public:
	ArcaneWarrior(string name);
	virtual ~ArcaneWarrior();
	int takeDamage(int value);
	int takeHealing(int value);
	void checkDead();

};

