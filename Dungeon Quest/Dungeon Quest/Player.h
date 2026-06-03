#pragma once
#include<string>
#include "Character.h"
#include "Inventory.h"
#include "Weapon.h"
using namespace std;

// Player class represents the user-controlled character
// Inherits basic stats and combat behavior from Character
class Player : public Character {

protected:

	// Current mana for spell casting or abilities
	int mana;

	// Maximum mana capacity
	int maxMana;

	// Experience threshold required for leveling up
	int thresHold;

	// Flag to track if player has just leveled up
	bool justLeveled;

	// String representing the type/class of player (Warrior, Mage, Rogue)
	string playerType;

	// Inventory system holding items and weapons
	Inventory inventory;

	// Pointer to currently equipped weapon
	Weapon* equippedWeapon;

public:

	// Constructor initializes player stats and base attributes
	Player(string name, int health, int maxHealth, int attack, int defence, int speed,
		int level, int experience, int mana, int maxMana, int thresHold, bool justLeveled, string playerType)
		:Character(name, health, maxHealth, attack, defence, speed, level, experience) {

		this->mana = mana;
		this->maxMana = maxMana;
		this->thresHold = thresHold;
		this->justLeveled = justLeveled;
		this->playerType = playerType;
		this->equippedWeapon = nullptr;
	}

	// Returns current XP
	int getXPPoints();

	// Handles level-up logic
	void levelUp();

	// Checks if player just leveled up
	bool leveledUp();

	// Returns current level
	int getLevel();

	// Returns player class/type
	string getPlayerType();

	// Returns current mana
	int getMana();

	// Returns maximum mana
	int getMaxMana();

	// Sets mana value
	void setMana(int mana);

	// Returns reference to inventory
	Inventory& getInventory();

	// Returns equipped weapon
	Weapon* getEquippedWeapon();

	// Equips a weapon and updates stats
	void equipWeapon(Weapon* weapon);

	// Uses an item from inventory
	void useItem(int index);

	// Restores mana
	void restoreMana(int amount);

	// Consumes mana
	void useMana(int amount);
};