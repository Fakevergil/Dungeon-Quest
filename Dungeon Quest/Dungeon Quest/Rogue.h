#pragma once
#include<string>
#include "Player.h"

class Rogue : public Player {
public:
	Rogue();

	void attackTarget(Character& target);
	void critHit(Character& enemy);
};
