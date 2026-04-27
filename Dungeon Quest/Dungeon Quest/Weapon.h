#pragma once
#include<string>
#include "Item.h"
using namespace std;

class Weapon : public Item {
	int weaponBonus;
public:
	Weapon(string name, string description, int weapon) : Item(name, description) {
		this->weaponBonus = weaponBonus;
	}
};
