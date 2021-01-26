#include "Weapon.h"

Weapon::Weapon(string name, int damage, int range) {
	m_name = name;
	m_damage = damage;
	m_range = range;
}

Weapon::~Weapon()
{
}

int Weapon::attack(Character* character, Character* target) {
	cout << character->getName() << " attacks " << target->getName() << " with a " << m_name << endl;
	target->takeDamage((character->getStrength() * m_damage)/(target->getDefense()*2.5));
	return target->getHp();
}

int Weapon::areaAttack(Character* character)
{
	cout << character->getName() << " attacks in an area with " << m_name << "." << endl;
	bool isAlly;
	for (unsigned int k = 0; k < character->getCharacters().size(); k++) {
		isAlly = false;
		Character* target = character->getCharacters()[k];
		double distance = sqrt(pow((target->getX() - character->getX()), 2) + pow((target->getY() - character->getY()), 2));
		for (unsigned int m = 0; m < character->getAllies().size(); m++) {
			if (target == character->getAllies()[m]) isAlly = true;
		}
		if (target == character);
		else if (!isAlly) {
			if (distance < m_range) {
				target->takeDamage((character->getStrength() * m_damage/2) / target->getDefense()*2.5);
			}
			else {
				cout << target->getName() << " was out of range." << endl;
			}
		}

	}
	return m_range;
}

string Weapon::getName() {
	return m_name;
}

int Weapon::getDamage() {
	return m_damage;
}

void Weapon::setDamage(int damage) {
	m_damage = damage;
}