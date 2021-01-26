#include <iostream>
#include "MageHeal.h"
#include "Warrior.h"

int main()
{
    MageHeal* clazza = new MageHeal("Clazza");
    Warrior* vylkhin = new Warrior("Vylkhin");
    Character* enemy = new Character("Enemy");

    vector<Character*> characters;
    characters.push_back(clazza);
    characters.push_back(vylkhin);
    characters.push_back(enemy); 
    clazza->setCharacters(characters);
    vylkhin->setCharacters(characters);
    enemy->setCharacters(characters);
    clazza->addAlly(vylkhin);

    enemy->attack(vylkhin);
    vylkhin->drinkPotion(30);
    enemy->attack(clazza);
    vylkhin->hammerHit(enemy);
    enemy->changeWeapon(new Weapon("spear", 2, 10));
    enemy->attack(vylkhin);
    clazza->heal(vylkhin);
    enemy->areaAttack();
    vylkhin->seppuku();
    clazza->heal(vylkhin);
    enemy->drinkPotion(30);
    clazza->zettaheal();
    clazza->zettaflare();
}