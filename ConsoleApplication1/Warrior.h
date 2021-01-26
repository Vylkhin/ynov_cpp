#pragma once

using namespace std;

#include <string>
#include <iostream>
#include "Character.h"

class Warrior : public Character
{




public:
	Warrior(string name);
	~Warrior();
	int hammerHit(Character* target);
	int smash();
	int seppuku();
	int takeDamage(int value);
	int takeHealing(int value);
	void isDead();

};

