#include<iostream>
#include<string>
#include "Mage.h"
#include<algorithm>
using namespace std;

// Constructor initializes Mage with predefined stats
Mage::Mage() : Player("Mage", 70, 70, 10, 5, 7, 1, 0, 50, 100, 100, false, "Mage") {
}

// Casts a spell on an enemy if enough mana is available
void Mage::castSpell(Character& enemy) {

	// Check if Mage has enough mana to cast spell
	if (mana >= 20) {

		// Calculate base damage (currently not used in final damage)
		int actualDamage = max(1, attack - enemy.getDefence());

		// Normal attack applied once
		enemy.takeDamage(attack);

		cout << "  " << getName() << " ATTACKED " << enemy.getName() << endl;

		// Strong spell damage (high burst damage)
		enemy.takeDamage(attack * 3.5);

		// Reduce mana cost
		mana -= 20;
	}
	else
	{
		// Not enough mana message
		cout << "  NOT ENOUGH MANA TO CAST A SPELL" << endl;
	}
}