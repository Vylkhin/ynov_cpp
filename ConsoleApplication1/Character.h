#pragma once
using namespace std;

#include <string>
#include <iostream>
#include "Weapon.h"
#include <vector>

class Weapon;

class Character
{
protected:
	int m_hp;
	int m_maxHp;
	int m_strength;
	int m_defense;
	string m_name;
	vector<Weapon*> weaponInventory;
	Weapon* m_weapon;
	int m_x;
	int m_y;
	vector<Character*> m_characters;
	vector<Character*> m_allies;


public:
	Character(string name);
	int drinkPotion(int amount);
	int attack(Character* target);
	int areaAttack();
	Weapon* changeWeapon(Weapon* newWeapon);
	void showHP();
	virtual void isDead();
	virtual int takeDamage(int value);
	Character* addAlly(Character* ally);
	virtual int takeHealing(int value);

	void setHp(int value);
	int getHp();
	void setName(string name);
	string getName();
	int getStrength();
	int getMaxHp();
	void setMaxHp(int maxHp);
	int getX();
	void setX(int x);
	int getY();
	void setY(int y);
	int getDefense();
	void setDefense(int defense);
	vector<Character*> getCharacters();
	void setCharacters(vector<Character*> characters);
	vector<Character*> getAllies();

	virtual ~Character();

};

