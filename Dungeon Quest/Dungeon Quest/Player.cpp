#include<iostream>
#include<string>
#include "Player.h"
using namespace std;

int Player::getXPPoints() {
	return experience;
}

void Player::levelUp() {
	while (experience >= thresHold) {
		experience -= thresHold;
		level++;
		maxHealth += 10;
		attack += 3;
		defence += 2;
		health = maxHealth;
		thresHold *= 2;
		justLeveled = true;
	}
}
bool Player::leveledUp() {
	if (justLeveled == true) {
		justLeveled = false;
		return true;
	}
	return false;
}
int Player::getLevel() {
	return level;
}
string Player::getPlayerType() {
	return playerType;
}
int Player::getMana() {
	return mana;
}
int Player::getMaxMana() {
	return maxMana;
}
void Player::setMana(int mana) {
	this->mana = mana;
}
Inventory& Player::getInventory() {
	return inventory;
}
Weapon* Player::getEquippedWeapon() {
	return equippedWeapon;
}
void Player::equipWeapon(Weapon* weapon) {
	if (equippedWeapon != nullptr) {
		setAttack(getAttack() - equippedWeapon->getAttackBonus());
	}
	equippedWeapon = weapon;
	inventory.equipWeapon(weapon);
	setAttack(getAttack() + weapon->getAttackBonus());
}
void Player::useItem(int index) {
	Item* item = inventory.getItem(index);
	if (item != nullptr) {
		item->use(*this);
		inventory.removeItem(index);
	}
}
void Player::restoreMana(int amount) {
	mana += amount;
	if (mana > maxMana) {
		mana = maxMana;
	}
}
void Player::useMana(int amount) {
	mana -= amount;
}