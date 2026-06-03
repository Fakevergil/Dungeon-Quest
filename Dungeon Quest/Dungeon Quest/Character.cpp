#include<iostream>
#include<string>
#include "Character.h"
#include<algorithm>
using namespace std;

// Reduces the character's health after applying defence
void Character::takeDamage(int damage) {

    // Calculate damage after defence reduction
    // Damage can never be less than 1
    int actualDamage = max(1, damage - defence);

    // Subtract damage from health
    health -= actualDamage;
}

// Checks whether the character is still alive
bool Character::isAlive() {

    // Character is alive if health is above 0
    if (health > 0) {
        return true;
    }
    else {
        return false;
    }
}

// Performs an attack on another character
void Character::attackTarget(Character& target) {

    // Only attack if this character is alive
    if (isAlive()) {

        // Calculate actual damage after target defence
        // (This variable is currently not used)
        int actualDamage = max(1, attack - target.getDefence());

        // Apply attack damage to target
        target.takeDamage(attack);
    }
}

// Adds experience points to the character
void Character::gainExperience(int XP) {
    experience += XP;
}

// Returns the current health of the character
int Character::getHealth() {

    // Prevent health from going below 0
    if (health < 0) {
        health = 0;
    }

    return health;
}

// Returns the attack stat
int Character::getAttack() {
    return attack;
}

// Returns the character's name
string Character::getName() {
    return name;
}

// Returns the defence stat
int Character::getDefence() {
    return defence;
}

// Returns the speed stat
int Character::getSpeed() {
    return speed;
}

// Returns the current level
int Character::getLevel() {
    return level;
}

// Returns the maximum health value
int Character::getMaxHealth() {
    return maxHealth;
}

// Sets a new attack value
void Character::setAttack(int attack) {
    this->attack = attack;
}

// Sets a new health value
void Character::setHealth(int health) {
    this->health = health;
}

// Sets a new defence value
void Character::setDefence(int defence) {
    this->defence = defence;
}