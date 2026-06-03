#pragma once
#include<string>
#include "Item.h"
#include "Player.h"
using namespace std;

// Potion class represents consumable items that restore health or mana
class Potion : public Item {

	// Amount of health restored by this potion
	int healAmount;

	// Amount of mana restored by this potion
	int manaAmount;

	// Type of potion ("Health" or "Mana")
	string potionType;

public:

	// Constructor initializes potion properties
	Potion(string name, string description, int healAmount, int manaAmount, string potionType)
		: Item(name, description) {

		this->healAmount = healAmount;
		this->manaAmount = manaAmount;
		this->potionType = potionType;
	}

	// Uses the potion effect on the player
	void use(Player& player);

	// Returns heal amount
	int getHealAmount();

	// Returns mana amount
	int getManaAmount();

	// Returns potion type
	string getPotionType();
};