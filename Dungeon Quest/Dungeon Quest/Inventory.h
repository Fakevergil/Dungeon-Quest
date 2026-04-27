#pragma once
#include<vector>
#include<string>
#include "Item.h"
#include "Weapon.h"
using namespace std;

class Inventory {
	vector<Item*> items;
	Weapon* equippedWeapons;
};
