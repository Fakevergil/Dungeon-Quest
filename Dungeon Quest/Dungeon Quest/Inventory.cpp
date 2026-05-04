#include<iostream>
#include<string>
#include "Inventory.h"
#include "Item.h"
#include <vector>
using namespace std;

void Inventory::addItem(Item* item) {
	items.push_back(item);
}

void Inventory::removeItem(int index) {
	if (index >= 0 && index < getSize()) {
		items.erase(items.begin() + index);
	}
	else {
		cout << "Not an item" << endl;
	}
	
}

void Inventory::equipWeapon(Weapon* weapon) {
	equippedWeapon = weapon;
}

void Inventory::displayItems() {
	for (int i = 0; i < getSize(); i++) {
		cout << "Name: " << items[i]->getItemName() << endl;
		cout << "Description: " << items[i]->getItemDescription() << endl;
	}
}

Item* Inventory::getItem(int index) {
	if (index >= 0 && index < getSize()) {
		return items[index];
	}
	return nullptr;
}

Weapon* Inventory::getEquippedWeapon() {
	return equippedWeapon;
}

int Inventory::getSize() {
	return items.size();
}