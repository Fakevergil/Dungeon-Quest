#pragma once
#include<string>
#include "Player.h"

// Mage class represents a magic-based player with spell abilities
class Mage : public Player {
public:

	// Constructor initializes Mage stats
	Mage();

	// Casts a spell on an enemy character
	void castSpell(Character& enemy);
};