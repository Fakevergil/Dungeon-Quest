#pragma once
#include<string>
#include "Character.h"
using namespace std;

class Player : public Character {
	int mana;
	int maxMana;
	int thresHold;
	bool justLeveled;
public:
	Player(string name, int health, int maxHealth, int attack, int defence, int speed, int level, int experience, int mana, int maxMana, int thresHold, bool justLeveled)
		:Character(name, health, maxHealth, attack, defence, speed, level, experience) {
		this->mana = mana;
		this->maxMana = maxMana;
		this->thresHold = thresHold;
		this->justLeveled = justLeveled;
	}

	int getXPPoints();
	void levelUp();
	bool leveledUp();
	int getLevel();
	
};
