#include<iostream>
#include<string>
#include "Inventory.h"
#include "Item.h"
#include "Player.h"
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

void Inventory::displayItems(Player& player) {
	if (getSize() <= 0) {
		cout << " YOU HAVE NO ITEMS IN YOUR INVENTORY\n" << endl;
	}
	else {
		for (int i = 0; i < getSize(); i++) {
			cout << " " << i + 1 << ") NAME: " << items[i]->getItemName() << endl;
			cout << " DESCRIPTION: " << items[i]->getItemDescription()<<"\n" << endl;
		}
	}
	int choice;
	if (getSize() != 0) {
		cout << "YOU WISH TO USE AN ITEM? (0 TO CANCEL)";
		cin >> choice;
		if (choice != 0) {
			cout << "YOU USED: " << items[choice - 1]->getItemName() << endl;
			player.useItem(choice - 1);
			
		}
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