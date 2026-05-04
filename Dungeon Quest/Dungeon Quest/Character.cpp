#include<iostream>
#include<string>
#include "Character.h"
#include<algorithm>
using namespace std;

void Character::takeDamage(int damage) {
    int actualDamage = max(1, damage - defence);
    health -= actualDamage;
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
        int actualDamage = max(1, attack - target.getDefence());
        target.takeDamage(attack);
        cout << name << " Attacked " << target.getName() << endl;
        cout << "Damage Taken: " << actualDamage << endl;
        cout << target.getName() << " Health: " << target.getHealth() << endl;
    }
}

void Character::gainExperience(int XP) {
    experience += XP;
}
int Character::getHealth() {
    if (health < 0) {
        health = 0;
    }
    return health;
}
int Character::getAttack() {
    return attack;
}
string Character::getName() {
    return name;
}
int Character::getDefence() {
    return defence;
}
int Character::getSpeed() {
    return speed;
}
int Character::getLevel() {
    return level;
}
int Character::getMaxHealth() {
    return maxHealth;
}
void Character::setAttack(int attack) {
    this->attack = attack;
}
void Character::setHealth(int health) {
    this->health = health;
}
void Character::setDefence(int defence) {
    this->defence = defence;
}
