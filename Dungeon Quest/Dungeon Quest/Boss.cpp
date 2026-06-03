#include<iostream>
#include<string>
#include "Boss.h"
#include "Player.h"
using namespace std;

// Default constructor for Boss
// Initializes the boss with predefined stats by calling the Enemy constructor
Boss::Boss() : Enemy("Argosax, The Chaos", 150, 150, 25, 15, 8, 1, 0, 100) {
}

// Determines the boss's action during its turn
void Boss::chooseAction(Character& player) {

	// Get the boss's current health
	int bossHealth = getHealth();

	// If health is 75 or lower, use special attack
	if (bossHealth <= 75) {
		specialAttack(player);
	}
	else {
		// Otherwise perform a normal attack
		attackTarget(player);
	}
}

// Boss's special attack ability
void Boss::specialAttack(Character& player) {

	// Display attack message
	cout << "Boss Used Special Attack..." << endl;

	// Deal 75 damage directly to the player
	player.takeDamage(75);

}