#pragma once
#include<string>
#include "Item.h"
using namespace std;

class Potion : public Item {
	int healAmount;
	int manaAmount;
	string potionType;
public:
	Potion(string name, string description, int healAmount, int manaAmount, string potionType) : Item(name, description) {
		this->healAmount = healAmount;
		this->manaAmount = manaAmount;
		this->potionType = potionType;
	}

	void use();
	int getHealAmount();
	int getManaAmount();
	string getPotionType();
};
