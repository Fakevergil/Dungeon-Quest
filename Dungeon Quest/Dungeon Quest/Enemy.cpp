#include<iostream>
#include<string>
#include "Enemy.h"
using namespace std;

int Enemy::getXPrewards() {
	return XPRewards;
}

void Enemy::chooseAction(Character& player) {
	attackTarget(player);
}