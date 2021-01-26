#include "MageHeal.h"

MageHeal::MageHeal(string name) : Mage(name) {
	m_strength = 1;
	m_magic = 10;
	m_spirit = 30;
}

int MageHeal::heal(Character* target) {
	cout << m_name << " uses Heal on " << target->getName() << "." << endl;
	if (target->getHp() > 0) target->takeHealing(m_spirit * 30);
	else {
		cout << target->getName() << " is dead. You can't heal a dead person, that's not how it works." << endl;
		cout << "Please, you have to accept his death now, you're just hurting yourself..." << endl;
	}
	return target->getHp();
}

int MageHeal::zettaheal()
{
	cout << m_name << " uses Zettaheal." << endl;
	bool isAlly;
	for (unsigned int k = 0; k < m_characters.size(); k++) {
		isAlly = false;
		Character* target = m_characters[k];
		double distance = sqrt(pow((target->getX() - m_x), 2) + pow((target->getY() - m_y), 2));
		for (unsigned int m = 0; m < m_allies.size(); m++) {
			if (target == m_allies[m]) isAlly = true;
		}
		if (target == this) takeHealing(m_spirit * 100);
		if (isAlly && target->getHp() > 0) {
			if (distance < 30) {
				target->takeHealing(m_spirit * 100);
			}
			else {
				cout << target->getName() << " was out of range." << endl;
			}
		}

	}
	return m_hp;
}

int MageHeal::getSpirit() {
	return m_spirit;
}

void MageHeal::setSpirit(int spirit) {
	m_spirit = spirit;
}

int MageHeal::takeDamage(int value)
{
	m_hp -= value/(m_defense*2.5);
	if (m_hp < 0) m_hp = 0;
	cout << m_name << ": Seriously ? Do that again I'll kick your ass." << endl;
	showHP();
	isDead();
	return m_hp;
}

int MageHeal::takeHealing(int value)
{
	m_hp += value;
	if (m_hp > m_maxHp) m_hp = m_maxHp;
	cout << m_name << ": Hihihi !" << endl;
	showHP();
	return m_hp;
}

void MageHeal::isDead()
{
	if (m_hp <= 0) std::cout << m_name << ": So now you kill me ? Wait till I'm back I'll kick your ass." << endl;
}
