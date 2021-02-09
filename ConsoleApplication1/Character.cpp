#include "Character.h"

Character::Character(string name){
	m_name = name;
	m_hp = 500;
	m_maxHp = m_hp;
	m_strength = 3;
	m_defense = 2;
	m_weapon = new Weapon("sword", 30, 5);
	m_x = 2;
	m_y = 1;
	m_type = "character";
}

int Character::drinkPotion(int amount) {
	m_hp += amount;
	if (m_hp > m_maxHp) m_hp = m_maxHp;
	std::cout << m_name << " drinks a potion and restores " << amount << " HP." << endl;
	showHP();
	return m_hp;
}

int Character::attack(Character* target) {
	return m_weapon->attack(this, target);
}

int Character::areaAttack() {
	return m_weapon->areaAttack(this);
}

Weapon* Character::changeWeapon(Weapon* newWeapon) {
	m_weapon = newWeapon;
	std::cout << m_name << ": I switched weapons, I am now fighting with a " << m_weapon->getName() << "." << endl;
	return m_weapon;
}

void Character::showHP() {
	std::cout << m_name << " now has " << m_hp << " HP." << endl;
}

void Character::checkDead() {
	if (m_hp <= 0) std::cout << m_name << ": I am dead." << endl;
}

int Character::takeDamage(int value) {
	if (m_hp <= 0) return m_hp;
	m_hp -= value/(m_defense/2.5);
	if (m_hp < 0) m_hp = 0;
	cout << m_name << ": Ouch." << endl;
	showHP();
	checkDead();
	return m_hp;
}

Character* Character::addAlly(Character* ally)
{
	m_allies.push_back(ally);
	ally->m_allies.push_back(this);
	return ally;
}

int Character::takeHealing(int value)
{
	m_hp += value;
	if (m_hp > m_maxHp) m_hp = m_maxHp;
	cout << m_name << ": Thanks !" << endl;
	showHP();
	return m_hp;
}


void Character::setHp(int value) {
	m_hp = value;
}

int Character::getHp() {
	return m_hp;
}

void Character::setName(string name) {
	m_name = name;
}

string Character::getName() {
	return m_name;
}

int Character::getStrength() {
	return m_strength;
}

int Character::getMaxHp() {
	return m_maxHp;
}

void Character::setMaxHp(int maxHp) {
	m_maxHp = maxHp;
}

int Character::getX()
{
	return m_x;
}

void Character::setX(int x)
{
	m_x = x;
}

int Character::getY()
{
	return m_y;
}

void Character::setY(int y)
{
	m_y = y;
}

int Character::getDefense()
{
	return m_defense;
}

void Character::setDefense(int defense)
{
	m_defense = defense;
}

vector<Character*> Character::getCharacters()
{
	return m_characters;
}

void Character::setCharacters(vector<Character*> characters)
{
	m_characters = characters;
}

vector<Character*> Character::getAllies()
{
	return m_allies;
}

string Character::getType()
{
	return m_type;
}

void Character::setType(string type)
{
	m_type = type;
}

Character::~Character()
{
}
