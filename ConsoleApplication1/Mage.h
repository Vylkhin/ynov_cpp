#pragma once

using namespace std;

#include <string>
#include <iostream>
#include "Character.h"

class Mage : public Character
{
protected:
	int m_magic;


public:
	Mage(string name);
	~Mage();
	int fireball(Character* target);
	int zettaflare();
	int takeDamage(int value);
	int takeHealing(int value);
	void isDead();
};

