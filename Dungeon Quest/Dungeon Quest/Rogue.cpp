#include<iostream>
#include<string>
#include "Rogue.h"
using namespace std;

// Default constructor for Rogue class
// Initializes the Rogue with its starting stats
Rogue::Rogue() : Player("Rogue", 90, 90, 12, 6, 10, 1, 0, 0, 0, 100, false, "Rogue") {
}

// Overrides the base attack function
// Gives the Rogue a chance to perform a critical hit
void Rogue::attackTarget(Character& target) {

	// Generate a random number between 1 and 100
	int roll = rand() % 100 + 1;

	// 30% chance to perform a critical hit
	if (roll <= 30) {
		critHit(target);
	}
	else {
		// Otherwise perform a normal attack
		Character::attackTarget(target);
	}
}

// Rogue's special critical hit attack
void Rogue::critHit(Character& enemy) {

	// Deal double attack damage
	enemy.takeDamage(attack * 2);

	// Display critical hit message
	cout << name << " Delt A Critical Hit" << endl;
}