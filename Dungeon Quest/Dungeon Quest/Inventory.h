#pragma once
#include<vector>
#include<string>
#include "Item.h"
using namespace std;

class Weapon;

class Inventory {
	vector<Item*> items;
	Weapon* equippedWeapon;
public:
    Inventory() {
        this->equippedWeapon = nullptr;
    }
    void addItem(Item* item);
    void removeItem(int index);
    void equipWeapon(Weapon* weapon);
    void displayItems();
    Item* getItem(int index);
    Weapon* getEquippedWeapon();
    int getSize();
};
