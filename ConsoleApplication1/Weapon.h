#pragma once

using namespace std;

#include <string>
#include <iostream>
#include "Character.h"

class Character;

enum WeaponType {
	None,
	Melee,
	Range
};

class Weapon
{
protected:
	int m_damage;
	string m_name;
	int m_range;


	WeaponType m_weaponType;
	Weapon();

public:
	Weapon(string name, int damage, int range);
	~Weapon();
	int attack(Character* character, Character* target);
	int areaAttack(Character* character);
	string getName();
	int getDamage();
	void setDamage(int damage);

};

