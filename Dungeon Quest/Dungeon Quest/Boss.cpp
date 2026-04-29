#include<iostream>
#include<string>
#include "Boss.h"
using namespace std;

Boss::Boss() : Enemy("Boss", 150, 150, 25, 15, 8, 1, 0, 100) {
}

void Boss::specialAttack() {
	int bossHealth = getHealth();
	if (bossHealth <= 75) {
		attack = 100;
		cout << "Boss Used Special Attack..." << endl;
	}
}

