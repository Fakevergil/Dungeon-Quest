#pragma once
#include "Character.h"
#include<string>
#include "Item.h"
using namespace std;

class Enemy : public Character {
	int XPRewards;
	Item* loot;
public:
	Enemy(string name, int health, int maxHealth, int attack, int defence, int speed, int level, int experience, int XPRewards)
		:Character(name, health, maxHealth, attack, defence, speed, level, experience) {
		this->XPRewards = XPRewards;
	}

	int getXPrewards();
};
