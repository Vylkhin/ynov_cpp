#include "Warrior.h"

Warrior::Warrior(string name) : Character(name){
	m_hp = 1000;
	m_maxHp = 1000;
	m_defense = 3;
	m_x = 3;
	m_y = 4;
	m_type = "warrior";
}

Warrior::~Warrior()
{
}

int Warrior::hammerHit(Character* target) {
	cout << m_name << " uses Hammer Hit on " << target->getName() << "." << endl;
	target->takeDamage(m_strength*50);
	return target->getHp();
}

int Warrior::smash()
{
	cout << m_name << " uses Smash." << endl;
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
			if (distance < 5) {
				target->takeDamage(m_strength * 50);
			}
			else {
				cout << target->getName() << " was out of range." << endl;
			}
		}

	}
	return m_hp;
}

int Warrior::seppuku()
{
	cout << m_name << ": I'M USING MY JAPANESE MASTER'S FORBIDDEN TECHNIQUE !" << endl;
	cout << m_name << ": SEPPUKU !" << endl;
	cout << m_name << " empales himself and his guts fall on the floor, thus making everyone take damage from disgust." << endl;
	takeDamage(m_hp*9999);
	for (unsigned int k = 0; k < m_characters.size(); k++) {
		Character* target = m_characters[k];
		if (target == this);
		else target->takeDamage(20);
	}
	return m_hp;
}

int Warrior::takeDamage(int value)
{
	if (m_hp <= 0) return m_hp;
	m_hp -= value/(m_defense*2.5);
	if (m_hp < 0) m_hp = 0;
	cout << m_name << ": Wow that hurts..." << endl;
	showHP();
	checkDead();
	return m_hp;
}

int Warrior::takeHealing(int value)
{
	m_hp += value;
	if (m_hp > m_maxHp) m_hp = m_maxHp;
	cout << m_name << ": Soooooooo good !" << endl;
	showHP();
	return m_hp;
}

void Warrior::checkDead()
{
	if (m_hp <= 0) std::cout << m_name << ": I'm dying the warrior way, with honor !" << endl;
}


