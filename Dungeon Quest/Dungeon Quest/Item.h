#pragma once
#include<string>
using namespace std;

// Forward declaration of Player class (needed for use() function)
class Player;

// Base class for all usable items in the game
class Item {

	// Item name
	string name;

	// Item description shown in inventory
	string description;

public:

	// Constructor initializes item name and description
	Item(string name, string description) {
		this->name = name;
		this->description = description;
	}

	// Pure virtual function: makes Item an abstract class
	// Each derived item must define its own effect on the player
	virtual void use(Player& player) = 0;

	// Returns item name
	string getItemName();

	// Returns item description
	string getItemDescription();
};