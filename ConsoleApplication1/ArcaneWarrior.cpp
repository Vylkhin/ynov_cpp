#include "ArcaneWarrior.h"

ArcaneWarrior::ArcaneWarrior(string name) : Mage(name), Warrior(name), Character(name) {
	Mage::m_hp = 700;
	Mage::m_maxHp = 700;
	Mage::m_strength = 2;
	Mage::m_magic = 10;
	Mage::m_defense = 2;
	Mage::m_x = 3;
	Mage::m_y = 2;
	m_type = "arcane warrior";
}

ArcaneWarrior::~ArcaneWarrior()
{
}

int ArcaneWarrior::takeDamage(int value)
{
	if (Mage::m_hp <= 0) return m_hp;
	Mage::m_hp -= value / (Mage::m_defense * 2.5);
	if (Mage::m_hp < 0) Mage::m_hp = 0;
	cout << Mage::m_name << ": Stop it." << endl;
	Mage::showHP();
	Mage::checkDead();
	return Mage::m_hp;
}

int ArcaneWarrior::takeHealing(int value)
{
	Mage::m_hp += value;
	if (Mage::m_hp > Mage::m_maxHp) Mage::m_hp = Mage::m_maxHp;
	cout << Mage::m_name << ": Thanks." << endl;
	Mage::showHP();
	return Mage::m_hp;
}

void ArcaneWarrior::checkDead()
{
	if (Mage::m_hp <= 0) std::cout << Mage::m_name << ": I am dead." << endl;
}
