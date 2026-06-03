#pragma once
#include<string>
#include "Room.h"
#include "Player.h"

// Dungeon class manages the game map, player movement, and floor generation
class Dungeon {

	// 4x4 grid representing dungeon rooms
	Room* grid[4][4];

	// Player's current position in the grid
	int playerX;
	int playerY;

	// Current dungeon floor number
	int currentFloor;

	// Tracks whether the final boss has been defeated
	bool gameWon;

public:

	// Constructor initializes dungeon and generates first floor
	Dungeon();

	// Moves the player based on input direction (WASD)
	void movePlayer(char direction, Player& player);

	// Displays the dungeon map and player status
	void printMap(Player& player);

	// Generates a new dungeon floor with rooms and enemies
	void generateFloor();

	// Checks if a movement is within bounds
	bool isValidMove(int newX, int newY);

	// Getter for player X position
	int getPlayerX();

	// Getter for player Y position
	int getPlayerY();

	// Getter for current floor number
	int getCurrentFloor();

	// Returns true if the game has been won
	bool isGameWon();

	// Returns a pointer to a specific room in the grid
	Room* getRoom(int x, int y);
};