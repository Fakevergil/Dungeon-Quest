#pragma once
#include<string>
#include "Player.h"

class Warrior : public Player {
public:
	Warrior();

	void attackTarget(Character& target);
	void powerStrike(Character& enemy);
};
