#include<iostream>
#include<string>
#include "Inventory.h"
#include "Item.h"
#include "Player.h"
#include <vector>
using namespace std;

// Adds an item to the inventory list
void Inventory::addItem(Item* item) {
	items.push_back(item);
}

// Removes an item from the inventory at a given index
void Inventory::removeItem(int index) {

	// Check if index is valid
	if (index >= 0 && index < getSize()) {
		items.erase(items.begin() + index);
	}
	else {
		cout << "Not an item" << endl;
	}
}

// Sets the currently equipped weapon
void Inventory::equipWeapon(Weapon* weapon) {
	equippedWeapon = weapon;
}

// Displays all items in the inventory and allows player interaction
void Inventory::displayItems(Player& player) {

	cout << "  +------------------------------------------+" << endl;
	cout << "  |              INVENTORY                   |" << endl;
	cout << "  +------------------------------------------+" << endl;

	// If inventory is empty, show message and exit
	if (getSize() <= 0) {
		cout << "  | YOUR INVENTORY IS EMPTY                  |" << endl;
		cout << "  +------------------------------------------+" << endl;
		cout << "  PRESS ENTER TO CONTINUE...";
		cin.ignore();
		cin.get();
		return;
	}

	// Print all items in inventory
	for (int i = 0; i < getSize(); i++) {
		cout << "  | [" << i + 1 << "] " << items[i]->getItemName() << endl;
		cout << "  |     " << items[i]->getItemDescription() << endl;
		cout << "  |" << endl;
	}

	cout << "  +------------------------------------------+" << endl;
	cout << "  SELECT ITEM TO USE (0 TO CANCEL): ";

	int choice;
	cin >> choice;

	// Use selected item if valid
	if (choice != 0 && choice <= getSize()) {
		string itemName = items[choice - 1]->getItemName();
		player.useItem(choice - 1);
		cout << "  >> YOU USED: " << itemName << "!" << endl;
	}

	cout << "  PRESS ENTER TO CONTINUE...";
	cin.ignore();
	cin.get();
}

// Returns pointer to item at given index
Item* Inventory::getItem(int index) {

	// Check bounds before accessing vector
	if (index >= 0 && index < getSize()) {
		return items[index];
	}

	return nullptr;
}

// Returns currently equipped weapon
Weapon* Inventory::getEquippedWeapon() {
	return equippedWeapon;
}

// Returns number of items in inventory
int Inventory::getSize() {
	return items.size();
}