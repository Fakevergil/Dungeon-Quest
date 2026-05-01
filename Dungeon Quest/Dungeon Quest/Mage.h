#pragma once
#include<string>
#include "Player.h"

class Mage : public Player {
public:
	Mage();

	void castSpell(Character& enemy);
};
