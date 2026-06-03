#pragma once
#include<string>
#include "Dungeon.h"
#include "Warrior.h"
#include "Mage.h"
#include "Rogue.h"

// Game class controls the overall game flow (menu, player selection, main loop)
class Game {
public:

	// Starts and runs the game loop
	void run();
};