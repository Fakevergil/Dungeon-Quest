#include<iostream>
#include<string>
#include "Battle.h"
#include "Mage.h"

void Battle::startBattle(Player& player, Enemy& enemy) {
	int playerMove;
	bool playerFled = false;
	bool firstAttack = player.getSpeed() >= enemy.getSpeed();
	if (firstAttack) {
		cout << enemy.getName() << " Attacks Firsts" << endl;
		enemy.chooseAction(player);
	}
	while (player.isAlive() && enemy.isAlive()) {
		cout << "What should i do?" << endl;
		if (player.getPlayerType() == "Mage") {
			Mage& mage = dynamic_cast<Mage&>(player);
			cout << "1) Attack" <<"\n2) Cast Spell" << "\n3) Use Item" << "\n4) Flee" << endl;
			cin >> playerMove;
			if (playerMove == 1) {
				player.attackTarget(enemy);
				if (!enemy.isAlive()) {
					break;
				}
				else
				{
					enemy.chooseAction(player);
				}
			}
			else if( playerMove == 2){
				mage.castSpell(enemy);
			}
			else if (playerMove == 3) {
				playerFled = true;
				break;
			}

		}
		else {
			cout << "1) Attack" << "\n" << "2) Use Item" << "\n" << "3) Flee" << endl;
			cin >> playerMove;
			if (playerMove == 1) {
				player.attackTarget(enemy);
				if (!enemy.isAlive()) {
					break;
				}
				else
				{
					enemy.chooseAction(player);
				}
			}
			else if (playerMove == 3) {
				playerFled = true;
				break;
			}
		}
		
	}
	if (playerFled == true) {
		cout << "You chose flee." << "\n" << "You fled the battle...." << endl;
	}
	else
	{
		battleOutcome(player, enemy);
	}
}

void Battle::battleOutcome(Player& player, Enemy& enemy) {
	if (player.isAlive()) {
		cout <<player.getName() << " Wins" << endl;
		player.gainExperience(enemy.getXPrewards());
		cout << "XP Gained: " << enemy.getXPrewards() << endl;
		cout << "Total XP: " << player.getXPPoints() << endl;
		player.levelUp();
		if (player.leveledUp()) {
			cout << "Leveled Up: " << player.getLevel() << endl;
			cout << "Max Health Increased: " << player.getHealth() << endl;
			cout << "Attack Increased: " << player.getAttack() << endl;
		}
	}
	if (enemy.isAlive()) {
		cout << enemy.getName() << " Wins" << endl;
	}
}