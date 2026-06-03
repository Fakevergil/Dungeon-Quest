#include<iostream>
#include<string>
#include "Weapon.h"
using namespace std;

// Returns the attack bonus provided by the weapon
int Weapon::getAttackBonus() {
	return attackBonus;
}

// Uses the weapon by equipping it to the player
void Weapon::use(Player& player) {

	// Equip this weapon and apply its attack bonus
	player.equipWeapon(this);
}