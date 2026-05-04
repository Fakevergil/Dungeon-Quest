#pragma once
#include<vector>
#include<string>
#include "Item.h"
#include "Weapon.h"
using namespace std;

class Inventory {
	vector<Item*> items;
	Weapon* equippedWeapon;
public:
    Inventory();
    void addItem(Item* item);
    void removeItem(int index);
    void equipWeapon(Weapon* weapon);
    void displayItems();
    Item* getItem(int index);
    Weapon* getEquippedWeapon();
    int getSize();
};
