#include<iostream>
#include<string>
#include "Rogue.h"
using namespace std;

Rogue::Rogue() : Player("Rogue", 90, 90, 12, 6, 10, 1, 0, 0, 0, 100, false, "Rogue") {
}

void Rogue::attackTarget(Character& target) {
	int roll = rand() % 100 + 1;
	if (roll <= 30) {
		critHit(target);
	}
	else {
		Character::attackTarget(target);
	}
}

void Rogue::critHit(Character& enemy) {
	enemy.takeDamage(attack * 2);
	cout << name << " Delt A Critical Hit" << endl;
}