#include<iostream>
#include<string>
#include "Player.h"
using namespace std;

// Returns the player's current experience points
int Player::getXPPoints() {
	return experience;
}

// Handles player level progression
void Player::levelUp() {

	// Continue leveling up while enough XP is available
	while (experience >= thresHold) {

		// Remove XP required for current level
		experience -= thresHold;

		// Increase player level
		level++;

		// Increase player stats
		maxHealth += 10;
		attack += 3;
		defence += 2;

		// Fully heal player upon leveling up
		health = maxHealth;

		// Double XP requirement for next level
		thresHold *= 2;

		// Mark that a level-up occurred
		justLeveled = true;
	}
}

// Checks if the player has recently leveled up
bool Player::leveledUp() {

	// Return true once, then reset the flag
	if (justLeveled == true) {
		justLeveled = false;
		return true;
	}

	return false;
}

// Returns the player's current level
int Player::getLevel() {
	return level;
}

// Returns the player's class type
string Player::getPlayerType() {
	return playerType;
}

// Returns current mana
int Player::getMana() {
	return mana;
}

// Returns maximum mana
int Player::getMaxMana() {
	return maxMana;
}

// Sets the player's mana value
void Player::setMana(int mana) {
	this->mana = mana;
}

// Returns a reference to the player's inventory
Inventory& Player::getInventory() {
	return inventory;
}

// Returns the currently equipped weapon
Weapon* Player::getEquippedWeapon() {
	return equippedWeapon;
}

// Equips a new weapon
void Player::equipWeapon(Weapon* weapon) {

	// Remove attack bonus from previously equipped weapon
	if (equippedWeapon != nullptr) {
		setAttack(getAttack() - equippedWeapon->getAttackBonus());
	}

	// Set the new equipped weapon
	equippedWeapon = weapon;

	// Update inventory's equipped weapon reference
	inventory.equipWeapon(weapon);

	// Add attack bonus from the new weapon
	setAttack(getAttack() + weapon->getAttackBonus());
}

// Uses an item from the inventory
void Player::useItem(int index) {

	// Get item at specified inventory slot
	Item* item = inventory.getItem(index);

	if (item != nullptr) {

		// Activate item's effect
		item->use(*this);

		// Remove item after use
		inventory.removeItem(index);
	}
}

// Restores mana to the player
void Player::restoreMana(int amount) {

	// Add mana
	mana += amount;

	// Prevent mana from exceeding maximum
	if (mana > maxMana) {
		mana = maxMana;
	}
}

// Consumes mana
void Player::useMana(int amount) {
	mana -= amount;
}