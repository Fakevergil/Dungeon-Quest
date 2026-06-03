#include<iostream>
#include<string>
#include<cstdlib>
#include "Dungeon.h"
#include "Warrior.h"
#include "Mage.h"
#include "Rogue.h"
#include "Game.h"
using namespace std;

// Entry point of the program
int main() {

	// Create a Game object
	Game game;

	// Start and run the game
	game.run();

	// Indicate successful program termination
	return 0;
}