#include<iostream>
#include<string>
#include "Character.h"
using namespace std;

void Character::takeDamage(int damage) {
    health -= damage;
}

bool Character::isAlive() {
    if (health > 0) {
        return true;
    }
    else {
        return false;
    }
}

void Character::attackTarget(Character& target){
    if (isAlive()) {
        target.takeDamage(attack);
        cout << name << " Attacked " << target.name << endl;
        cout << "Damage Taken: " << target.attack << endl;
        cout << "Health: " << getHealth() << endl;
    }
}

void Character::gainExperience(int XP) {
    experience += XP;
}
int Character::getHealth() {
    return health;
}
int Character::getAttack() {
    return attack;
}
string Character::getName() {
    return name;
}