#include <iostream>
#include "MageHeal.h"
#include "ArcaneWarrior.h"
#include "Overlord.h"

int main()
{
    MageHeal* clazza = new MageHeal("Clazza");
    Warrior* vylkhin = new Warrior("Vylkhin");
    ArcaneWarrior* thierry = new ArcaneWarrior("Thierry");
    Mage* passerby = new Mage("Passerby");
    ArcaneWarrior* seb = new ArcaneWarrior("Seb");
    Overlord<ArcaneWarrior>* joel = new Overlord<ArcaneWarrior>("Joel");

    vector<Character*> characters;
    characters.push_back(clazza);
    characters.push_back(vylkhin);
    characters.push_back(thierry);
    characters.push_back(passerby);
    characters.push_back(seb);
    characters.push_back(joel);

    joel->addAlly(thierry);
    joel->addAlly(seb);
    thierry->addAlly(seb);
    clazza->addAlly(vylkhin);

    clazza->setCharacters(characters);
    vylkhin->setCharacters(characters);
    thierry->setCharacters(characters);
    passerby->setCharacters(characters);
    seb->setCharacters(characters);
    joel->setCharacters(characters);

    passerby->setX(52); passerby->setY(67);

    joel->showHP();
    thierry->attack(vylkhin);
    vylkhin->drinkPotion(30);
    thierry->attack(clazza);
    vylkhin->hammerHit(thierry);
    thierry->changeWeapon(new Weapon("spear", 5, 10));
    joel->lynching(vylkhin);
    clazza->heal(vylkhin);
    thierry->areaAttack();
    thierry->fireball(vylkhin);
    thierry->hammerHit(vylkhin);
    vylkhin->seppuku();
    clazza->heal(vylkhin);
    thierry->drinkPotion(30);
    clazza->zettaheal();
    clazza->zettaflare();
    thierry->areaAttack();
}