#include<iostream>
#include<string>
#include "Mage.h"
#include<algorithm>
using namespace std;

Mage::Mage() : Player("Mage", 70, 70, 10, 5, 7, 1, 0, 50, 100, 100, false, "Mage") {
}

void Mage::castSpell(Character& enemy) {
	if (mana >= 20) {
		int actualDamage = max(1, attack - enemy.getDefence());
		enemy.takeDamage(attack);
		cout << "  " << getName() << " ATTACKED " << enemy.getName() << endl;
		enemy.takeDamage(attack * 3.5);
		mana -= 20;
	}
	else
	{
		cout << "  NOT ENOUGH MANA TO CAST A SPELL" << endl;
	}
}