#include<iostream>
#include<string>
#include "Weapon.h"
using namespace std;

int Weapon::getAttackBonus() {
	return attackBonus;
}

void Weapon::use(Player& player) {
	player.equipWeapon(this);
}