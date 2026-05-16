#include<iostream>
#include<string>
#include "Boss.h"
#include "Player.h"
using namespace std;

Boss::Boss() : Enemy("Argosax, The Chaos", 150, 150, 25, 15, 8, 1, 0, 100) {
}

void Boss::chooseAction(Character& player) {
	int bossHealth = getHealth();
	if (bossHealth <= 75) {
		specialAttack(player);
	}
	else {
		attackTarget(player);
	}
}

void Boss::specialAttack(Character& player) {
	cout << "Boss Used Special Attack..." << endl;
	player.takeDamage(100);
		
	}

