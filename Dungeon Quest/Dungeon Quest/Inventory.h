#pragma once
#include<vector>
#include<string>
#include "Item.h"
using namespace std;

// Forward declaration to avoid circular dependency
class Weapon;
class Player;

// Inventory class manages all items and equipped weapon of a player
class Inventory {

	// List of items currently stored in inventory
	vector<Item*> items;

	// Currently equipped weapon (if any)
	Weapon* equippedWeapon;

public:

	// Constructor initializes empty inventory with no weapon equipped
	Inventory() {
		this->equippedWeapon = nullptr;
	}

	// Adds an item to the inventory
	void addItem(Item* item);

	// Removes an item from the inventory by index
	void removeItem(int index);

	// Equips a weapon and updates player stats accordingly
	void equipWeapon(Weapon* weapon);

	// Displays all items and allows player interaction
	void displayItems(Player& player);

	// Returns item at a specific index
	Item* getItem(int index);

	// Returns currently equipped weapon
	Weapon* getEquippedWeapon();

	// Returns number of items in inventory
	int getSize();
};