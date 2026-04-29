#pragma once
#include<string>
#include "Enemy.h"
using namespace std;

class Boss : public Enemy {
public:
	Boss();

	void specialAttack();
};