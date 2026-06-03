#pragma once
#include<string>
#include "Enemy.h"
using namespace std;

// Forward declaration of Item to avoid circular dependency
class Item;

// Room class represents a single tile in the dungeon grid
class Room {

	// Type of room (Combat, Loot, Heal, Exit, Empty)
	string roomType;

	// Whether the player has visited this room
	bool isVisited;

	// Whether the room has been revealed on the map
	bool isRevealed;

	// Pointer to enemy in this room (if any)
	Enemy* enemy;

	// Pointer to item in this room (if any)
	Item* item;

public:

	// Constructor initializes room properties
	Room(string roomType, bool isVisited, bool isRevealed, Enemy* enemy, Item* item) {
		this->roomType = roomType;
		this->isVisited = isVisited;
		this->isRevealed = isRevealed;
		this->enemy = enemy;
		this->item = item;
	}

	// Getters
	string getRoomType();
	bool getIsVisited();
	bool getIsRevealed();
	Enemy* getEnemy();
	Item* getItem();

	// Set room state
	void setVisited(bool visited);
	void setRevealed(bool revealed);

	// Check if room is empty (no enemy or item)
	bool isEmpty();

	// Assign enemy to room
	void setEnemy(Enemy* enemy);

	// Assign item to room
	void setItem(Item* item);
};