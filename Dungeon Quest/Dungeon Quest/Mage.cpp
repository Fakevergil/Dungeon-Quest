#include<iostream>
#include<string>
#include "Mage.h"
using namespace std;

Mage::Mage() : Player("Mage", 70, 70, 10, 5, 7, 1, 0, 100, 100, 100, false, "Mage") {
}

void Mage::castSpell(Character& enemy) {
	if (mana >= 20) {
		enemy.takeDamage(attack * 3.5);
		mana -= 20;
	}
	else
	{
		cout << "Not Enough Mana To Cast Spell" << endl;
	}
}