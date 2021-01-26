#pragma once

using namespace std;

#include "Character.h"

class Mage : virtual public Character
{
protected:
	int m_magic;


public:
	Mage(string name);
	virtual ~Mage();
	int fireball(Character* target);
	int zettaflare();
	int takeDamage(int value);
	int takeHealing(int value);
	void dead();
};

