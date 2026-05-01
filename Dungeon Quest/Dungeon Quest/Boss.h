#pragma once
#include<string>
#include "Enemy.h"
#include "Character.h"
using namespace std;

class Boss : public Enemy {
public:
	Boss();
	void chooseAction(Character& player);
	void specialAttack(Character& player);
};