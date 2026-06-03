#include<iostream>
#include<string>
#include "Warrior.h"
using namespace std;

// Default constructor for Warrior class
// Initializes the Warrior with its starting stats
Warrior::Warrior() : Player("Warrior", 120, 120, 15, 12, 5, 1, 0, 0, 0, 100, false, "Warrior") {
}

// Overrides the base attack function
// Warrior always uses Power Strike when attacking
void Warrior::attackTarget(Character& target) {
	powerStrike(target);
}

// Warrior's special ability
// Deals 1.5x the Warrior's attack damage
void Warrior::powerStrike(Character& enemy) {
	enemy.takeDamage(attack * 1.5);
}