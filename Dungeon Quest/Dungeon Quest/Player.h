#pragma once
#include<string>
#include "Character.h"
#include "Inventory.h"
#include "Weapon.h"
using namespace std;

class Player : public Character {
protected:
	int mana;
	int maxMana;
	int thresHold;
	bool justLeveled;
	string playerType;
	Inventory inventory;
	Weapon* equippedWeapon;
public:
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

	int getXPPoints();
	void levelUp();
	bool leveledUp();
	int getLevel();
	string getPlayerType();
	int getMana();
	int getMaxMana();
	void setMana(int mana);
	Inventory& getInventory();
	Weapon* getEquippedWeapon();
	void equipWeapon(Weapon* weapon);
	void useItem(int index);
	void restoreMana(int amount);
	void useMana(int amount);
};
