#include<iostream>
#include<string>
#include "Battle.h"
#include "Mage.h"
#include "Inventory.h"

void Battle::startBattle(Player& player, Enemy& enemy) {
	int playerMove;
	bool playerFled = false;
	bool firstAttack = player.getSpeed() >= enemy.getSpeed();
	
	while (player.isAlive() && enemy.isAlive()) {
		cout << "  ====================" << endl;
		cout << "        BATTLE" << endl;
		cout << "  ====================\n" << endl;

		cout << "  ENEMY: " << enemy.getName() << endl;
		cout << "  HP: " << enemy.getHealth()<<"/"<<enemy.getMaxHealth()<< "\n" << endl;
		cout << "  --------------------"<<"\n" << endl;

		cout << "  YOU: " << player.getName() << endl;
		cout << "  HP: " << player.getHealth() << "/" << player.getMaxHealth() << endl;
		cout << "  MANA: " << player.getMana() << "/" << player.getMaxMana() << "\n" << endl;
		cout << "  ATK: " << player.getAttack() << "  DEF: " << player.getDefence() << "\n" << endl;
		cout << "  --------------------" << "\n" << endl;

		if (firstAttack) {
			cout<<" " << enemy.getName() << " ATTACKS FIRST" << endl;
			enemy.chooseAction(player);
		}
		cout << "  WHAT SHOULD I DO?\n" << endl;
		if (player.getPlayerType() == "Mage") {
			Mage& mage = dynamic_cast<Mage&>(player);
			cout << "  [1] Attack" <<"\n  [2] Cast Spell" << "\n  [3] Use Item" << "\n  [4] Flee" << endl;
			cin >> playerMove;
			if (playerMove == 1) {
				cout << "  " << player.getName() << " ATTACKED " << enemy.getName() << endl;
				cout << "  --------------------" << "\n" << endl;
				player.attackTarget(enemy);
				if (!enemy.isAlive()) {
					break;
				}
				else
				{
					cout << "  " << enemy.getName() << " ATTACKED " << player.getName() << endl;
					cout << "  --------------------" << "\n" << endl;
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
			cout << "  [1] Attack" << "\n" << "  [2] Use Item" << "\n" << "  [3] Flee" << endl;
			cin >> playerMove;
			if (playerMove == 1) {
				cout << "  " << player.getName() << " ATTACKED " << enemy.getName() << endl;
				cout << "  --------------------" << "\n" << endl;
				player.attackTarget(enemy);
				if (!enemy.isAlive()) {
					break;
				}
				else
				{
					cout << "  " << enemy.getName() << " ATTACKED " << player.getName() << endl;
					cout << "  --------------------" << "\n" << endl;
					enemy.chooseAction(player);
				}
			}
			else if (playerMove == 2) {
				Inventory& inventory = player.getInventory();
				if (inventory.getSize() <= 0) {
					cout << " YOU HAVE NO ITEMS IN YOUR INVENTORY\n" << endl;
				}
				else {
					for (int i = 0; i < inventory.getSize(); i++) {
						Item* items = inventory.getItem(i);
						cout <<" " << i+1 << ") NAME: " << items->getItemName() << endl;
						cout << " DESCRIPTION: " << items->getItemDescription() << "\n" << endl;
					}
				}
				int choice;
				if(inventory.getSize() != 0){
					cout << "YOU WISH TO USE AN ITEM? (0 TO CANCEL)";
					cin >> choice;
					if (choice != 0) {
						Item* items = inventory.getItem(choice - 1);
						cout << "YOU USED: " << items->getItemName() << endl;
						player.useItem(choice - 1);
						
					}
				}
				
			}
			else if (playerMove == 3) {
				playerFled = true;
				break;
			}
		}
		
	}
	if (playerFled == true) {
		cout << "  YOU CHOSE TO FLEE." << "\n" << "  YOU FLED THE BATTLE...." << endl;
	}
	else
	{
		battleOutcome(player, enemy);
	}
}

void Battle::battleOutcome(Player& player, Enemy& enemy) {
	if (player.isAlive()) {
		cout << "  " << player.getName() << " WINS" << endl;
		player.gainExperience(enemy.getXPrewards());
		cout << "  XP GAINED: " << enemy.getXPrewards() << endl;
		cout << "  TOTAL XP: " << player.getXPPoints() << endl;
		cout << "  --------------------" << "\n" << endl;
		player.levelUp();
		if (player.leveledUp()) {
			cout << "  LEVELED UP: " << player.getLevel() << endl;
			cout << "  MAX HEALTH INCREASED: " << player.getHealth() << endl;
			cout << "  ATTACK INCREASED: " << player.getAttack() << endl;
			cout << "  --------------------" << "\n" << endl;
		}
	}
	if (enemy.isAlive()) {
		cout << "  " << enemy.getName() << " WINS" << endl;
	}
}