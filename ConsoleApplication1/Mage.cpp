#include "Mage.h"

Mage::Mage(string name) : Character(name) {
	m_hp = 200;
	m_maxHp = 200;
	m_strength = 1;
	m_magic = 20;
	m_defense = 1;
	m_x = 2;
	m_y = 1;
	m_type = "mage";
}

Mage::~Mage()
{
}

int Mage::zettaflare()
{
	cout << m_name << " uses Zettaflare." << endl;
	bool isAlly;
	for (unsigned int k = 0; k < m_characters.size(); k++) {
		isAlly = false;
		Character* target = m_characters[k];
		double distance = sqrt(pow((target->getX() - m_x), 2) + pow((target->getY() - m_y), 2));
		for (unsigned int m = 0; m < m_allies.size(); m++) {
			if (target == m_allies[m]) isAlly = true;
		}
		if (target == this);
		else if (!isAlly) {
			if (distance < 30) {
				target->takeDamage(m_magic * 100);
			}
			else {
				cout << target->getName() << " was out of range." << endl;
			}
		}
		
	}
	return m_hp;
}

int Mage::takeDamage(int value)
{
	m_hp -= value/(m_defense*2.5);
	if (m_hp < 0) m_hp = 0;
	cout << m_name << ": Hey, stop hitting me !" << endl;
	showHP();
	dead();
	return m_hp;
}

int Mage::takeHealing(int value)
{
	m_hp += value;
	if (m_hp > m_maxHp) m_hp = m_maxHp;
	cout << m_name << ": Yeah thanks..." << endl;
	showHP();
	return m_hp;
}

void Mage::dead()
{
	if (m_hp <= 0) std::cout << m_name << ": So that's how I die... Meh." << endl;
}

int Mage::fireball(Character* target) {
	cout << m_name << " uses Fireball on " << target->getName() << "." << endl;
	target->takeDamage(m_magic * 50);
	return target->getHp();
}
