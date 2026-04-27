#pragma once
#include "Player.h"
#include "Enemy.h"

class Battle {
public:
	static void startBattle(Player& player, Enemy& enemy);
	static void battleOutcome(Player& player, Enemy& enemy);
};
