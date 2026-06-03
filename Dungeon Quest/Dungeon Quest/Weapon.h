#pragma once
#include<string>
#include "Item.h"
#include "Player.h"
using namespace std;

// Weapon class represents equippable items that increase player attack power
class Weapon : public Item {

	// Additional attack power provided by this weapon
	int attackBonus;

public:

	// Constructor initializes weapon stats and base item info
	Weapon(string name, string description, int attackBonus)
		: Item(name, description) {

		this->attackBonus = attackBonus;
	}

	// Returns the attack bonus value
	int getAttackBonus();

	// Equips the weapon to the player
	void use(Player& player);
};