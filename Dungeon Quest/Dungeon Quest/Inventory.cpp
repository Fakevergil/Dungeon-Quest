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
    cout << "  +------------------------------------------+" << endl;
    cout << "  |              INVENTORY                   |" << endl;
    cout << "  +------------------------------------------+" << endl;

    if (getSize() <= 0) {
        cout << "  | YOUR INVENTORY IS EMPTY                  |" << endl;
        cout << "  +------------------------------------------+" << endl;
        cout << "  PRESS ENTER TO CONTINUE...";
        cin.ignore();
        cin.get();
        return;
    }

    for (int i = 0; i < getSize(); i++) {
        cout << "  | [" << i + 1 << "] " << items[i]->getItemName() << endl;
        cout << "  |     " << items[i]->getItemDescription() << endl;
        cout << "  |" << endl;
    }
    cout << "  +------------------------------------------+" << endl;
    cout << "  SELECT ITEM TO USE (0 TO CANCEL): ";

    int choice;
    cin >> choice;
    if (choice != 0 && choice <= getSize()) {
        string itemName = items[choice - 1]->getItemName();
        player.useItem(choice - 1);
        cout << "  >> YOU USED: " << itemName << "!" << endl;
    }
    cout << "  PRESS ENTER TO CONTINUE...";
    cin.ignore();
    cin.get();
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