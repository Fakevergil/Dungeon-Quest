#pragma once
#include "Character.h"
#include<string>
#include "Item.h"
using namespace std;

// Enemy class represents all AI-controlled characters in the game
// Inherits basic stats and behavior from Character
class Enemy : public Character {

protected:

	// Experience points rewarded to player when enemy is defeated
	int XPRewards;

	// Item dropped by enemy after defeat
	Item* loot;

public:

	// Constructor initializes enemy stats and reward value
	Enemy(string name, int health, int maxHealth, int attack, int defence, int speed, int level, int experience, int XPRewards)
		:Character(name, health, maxHealth, attack, defence, speed, level, experience) {

		this->XPRewards = XPRewards;
		this->loot = nullptr;
	}

	// Returns XP reward value
	int getXPrewards();

	// Sets the loot item dropped by this enemy
	void setLoot(Item* item);

	// Determines enemy's action each turn (can be overridden)
	virtual void chooseAction(Character& player);
};