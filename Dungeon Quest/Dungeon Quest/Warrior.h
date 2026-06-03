#pragma once
#include<string>
#include "Player.h"

// Warrior class represents a tanky melee character with high defense
class Warrior : public Player {
public:

	// Constructor initializes Warrior stats
	Warrior();

	// Overrides base attack function with a stronger attack
	void attackTarget(Character& target);

	// Special ability that deals increased damage
	void powerStrike(Character& enemy);
};