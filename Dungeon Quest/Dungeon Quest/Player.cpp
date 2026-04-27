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
		maxHealth += 50;
		attack += 50;
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
