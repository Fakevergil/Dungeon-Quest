#pragma once
#include<string>
#include "Enemy.h"
#include "Character.h"
using namespace std;

// Boss class inherits from Enemy and represents a stronger enemy type
class Boss : public Enemy {
public:

	// Constructor to initialize the Boss with predefined stats
	Boss();

	// Determines the Boss's action each turn
	void chooseAction(Character& player);

	// Special powerful attack used by the Boss
	void specialAttack(Character& player);
};