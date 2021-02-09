#pragma once

using namespace std;

#include "Mage.h"

class MageHeal : public Mage
{
protected:
	int m_spirit;

public:
	MageHeal(string name);
	virtual ~MageHeal();
	int heal(Character* target);
	int zettaheal();
	int getSpirit();
	void setSpirit(int spirit);
	int takeDamage(int value);
	int takeHealing(int value);
	void checkDead();
};

