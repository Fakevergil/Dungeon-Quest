#include<iostream>
#include<string>
#include "Warrior.h"
using namespace std;

Warrior::Warrior() : Player("Warrior", 120, 120, 15, 12, 5, 1, 0, 0, 0, 100, false, "Warrior") {
}

void Warrior::attackTarget(Character& target) {
	powerStrike(target);
}

void Warrior::powerStrike(Character& enemy) {
	enemy.takeDamage(attack * 1.5);
}