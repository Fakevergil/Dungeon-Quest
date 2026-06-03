#include<iostream>
#include<string>
#include "Enemy.h"
using namespace std;

// Returns the amount of experience points awarded
// when this enemy is defeated
int Enemy::getXPrewards() {
	return XPRewards;
}

// Determines the enemy's action during its turn
// Default behavior is to perform a normal attack
void Enemy::chooseAction(Character& player) {
	attackTarget(player);
}

// Assigns a loot item that the enemy can drop
// upon defeat
void Enemy::setLoot(Item* item) {
	loot = item;
}