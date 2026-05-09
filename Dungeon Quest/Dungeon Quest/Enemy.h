#pragma once
#include "Character.h"
#include<string>
#include "Item.h"
using namespace std;

class Enemy : public Character {
protected:
	int XPRewards;
	Item* loot;
public:
	Enemy(string name, int health, int maxHealth, int attack, int defence, int speed, int level, int experience, int XPRewards)
		:Character(name, health, maxHealth, attack, defence, speed, level, experience) {
		this->XPRewards = XPRewards;
		this->loot = nullptr;
	}

	int getXPrewards();
	void setLoot(Item* item);
	virtual void chooseAction(Character& player);
};
