#pragma once
#include<string>
#include "Player.h"

// Rogue class is a fast player type with critical hit ability
class Rogue : public Player {
public:

	// Constructor initializes Rogue stats
	Rogue();

	// Overrides attack to include critical hit chance
	void attackTarget(Character& target);

	// Performs a critical hit attack dealing extra damage
	void critHit(Character& enemy);
};