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
