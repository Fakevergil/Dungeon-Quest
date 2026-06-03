#pragma once
#include "Player.h"
#include "Enemy.h"

// Battle class handles combat between player and enemy
class Battle {
public:

	// Starts a battle between the player and an enemy
	static void startBattle(Player& player, Enemy& enemy);

	// Determines and displays the outcome of the battle
	static void battleOutcome(Player& player, Enemy& enemy);
};