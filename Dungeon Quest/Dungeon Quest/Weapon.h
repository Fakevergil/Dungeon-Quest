#pragma once
#include<string>
#include "Item.h"
#include "Player.h"
using namespace std;

class Weapon : public Item {
	int attackBonus;
public:
	Weapon(string name, string description, int attackBonus) : Item(name, description) {
		this->attackBonus = attackBonus;
	}

	int getAttackBonus();
	void use(Player& player);
};
