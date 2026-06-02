#include<iostream>
#include<string>
#include "Battle.h"
#include "Mage.h"
#include "Inventory.h"

void Battle::startBattle(Player& player, Enemy& enemy) {
	int playerMove;
	bool playerFled = false;
	bool enemyFirst = enemy.getSpeed() > player.getSpeed();
	bool firstTurn = true;

	while (player.isAlive() && enemy.isAlive()) {
		system("cls");

		cout << "  +==========================================+" << endl;
		cout << "  |               *** BATTLE ***            |" << endl;
		cout << "  +==========================================+\n" << endl;

		
		cout << "  ENEMY" << endl;
		cout << "  +------------------------------------------+" << endl;
		cout << "  | NAME  : " << enemy.getName() << endl;
		cout << "  | HP    : " << enemy.getHealth() << "/" << enemy.getMaxHealth() << endl;
		cout << "  | ATK   : " << enemy.getAttack() << "   DEF: " << enemy.getDefence() << endl;
		cout << "  +------------------------------------------+\n" << endl;

		
		cout << "  YOU" << endl;
		cout << "  +------------------------------------------+" << endl;
		cout << "  | NAME  : " << player.getName() << endl;
		cout << "  | HP    : " << player.getHealth() << "/" << player.getMaxHealth() << endl;
		cout << "  | MANA  : " << player.getMana() << "/" << player.getMaxMana() << endl;
		cout << "  | ATK   : " << player.getAttack() << "   DEF: " << player.getDefence() << endl;
		cout << "  +------------------------------------------+\n" << endl;

		if (enemyFirst && firstTurn) {
			cout << "  !! " << enemy.getName() << " ATTACKS FIRST !!" << endl;
			cout << "  +------------------------------------------+" << endl;
			enemy.chooseAction(player);
			cout << "  +------------------------------------------+\n" << endl;
			if (!player.isAlive()) break;
			firstTurn = false;
		}
		firstTurn = false;

		cout << "  +------------------------------------------+" << endl;
		cout << "  |           WHAT WILL YOU DO?             |" << endl;
		cout << "  +------------------------------------------+" << endl;

		if (player.getPlayerType() == "Mage") {
			Mage& mage = dynamic_cast<Mage&>(player);
			cout << "  | [1] Attack                              |" << endl;
			cout << "  | [2] Cast Spell                          |" << endl;
			cout << "  | [3] Use Item                            |" << endl;
			cout << "  | [4] Flee                                |" << endl;
			cout << "  +------------------------------------------+" << endl;
			cout << "  SELECT: ";
			cin >> playerMove;
			cout << endl;

			if (playerMove == 1) {
				cout << "  >> " << player.getName() << " ATTACKS " << enemy.getName() << "!" << endl;
				player.attackTarget(enemy);
				if (!enemy.isAlive()) break;
				cout << "\n  >> " << enemy.getName() << " RETALIATES!" << endl;
				enemy.chooseAction(player);
			}
			else if (playerMove == 2) {
				cout << "  >> " << player.getName() << " CASTS A SPELL!" << endl;
				mage.castSpell(enemy);
				if (!enemy.isAlive()) break;
				cout << "\n  >> " << enemy.getName() << " RETALIATES!" << endl;
				enemy.chooseAction(player);
			}
			else if (playerMove == 3) {
				Inventory& inventory = player.getInventory();
				if (inventory.getSize() <= 0) {
					cout << "  >> YOU HAVE NO ITEMS IN YOUR INVENTORY!" << endl;
				}
				else {
					cout << "  +------------------------------------------+" << endl;
					cout << "  |              INVENTORY                  |" << endl;
					cout << "  +------------------------------------------+" << endl;
					for (int i = 0; i < inventory.getSize(); i++) {
						Item* item = inventory.getItem(i);
						cout << "  | [" << i + 1 << "] " << item->getItemName() << endl;
						cout << "  |     " << item->getItemDescription() << endl;
					}
					cout << "  +------------------------------------------+" << endl;
					cout << "  SELECT ITEM (0 TO CANCEL): ";
					int choice;
					cin >> choice;
					if (choice != 0 && choice <= inventory.getSize()) {
						string itemName = inventory.getItem(choice - 1)->getItemName();
						player.useItem(choice - 1);
						cout << "  >> YOU USED: " << itemName << "!" << endl;
						enemy.chooseAction(player);
					}
				}
			}
			else if (playerMove == 4) {
				playerFled = true;
				break;
			}
		}
		else {
			cout << "  | [1] Attack                              |" << endl;
			cout << "  | [2] Use Item                            |" << endl;
			cout << "  | [3] Flee                                |" << endl;
			cout << "  +------------------------------------------+" << endl;
			cout << "  SELECT: ";
			cin >> playerMove;
			cout << endl;

			if (playerMove == 1) {
				cout << "  >> " << player.getName() << " ATTACKS " << enemy.getName() << "!" << endl;
				player.attackTarget(enemy);
				if (!enemy.isAlive()) break;
				cout << "\n  >> " << enemy.getName() << " RETALIATES!" << endl;
				enemy.chooseAction(player);
				cout << "  PRESS ENTER TO CONTINUE...";
				cin.ignore();
				cin.get();
			}
			else if (playerMove == 2) {
				Inventory& inventory = player.getInventory();
				if (inventory.getSize() <= 0) {
					cout << "  >> YOU HAVE NO ITEMS IN YOUR INVENTORY!" << endl;
				}
				else {
					cout << "  +------------------------------------------+" << endl;
					cout << "  |              INVENTORY                  |" << endl;
					cout << "  +------------------------------------------+" << endl;
					for (int i = 0; i < inventory.getSize(); i++) {
						Item* item = inventory.getItem(i);
						cout << "  | [" << i + 1 << "] " << item->getItemName() << endl;
						cout << "  |     " << item->getItemDescription() << endl;
					}
					cout << "  +------------------------------------------+" << endl;
					cout << "  SELECT ITEM (0 TO CANCEL): ";
					int choice;
					cin >> choice;
					if (choice != 0 && choice <= inventory.getSize()) {
						string itemName = inventory.getItem(choice - 1)->getItemName();
						player.useItem(choice - 1);
						cout << "  >> YOU USED: " << itemName << "!" << endl;
						enemy.chooseAction(player);
					}
				}
			}
			else if (playerMove == 3) {
				playerFled = true;
				break;
			}
		}
	}

	system("cls");
	if (playerFled) {
		cout << "  +==========================================+" << endl;
		cout << "  |              YOU FLED!                  |" << endl;
		cout << "  +==========================================+" << endl;
	}
	else {
		battleOutcome(player, enemy);
	}
	cout << "  PRESS ENTER TO CONTINUE...";
	cin.ignore();
	cin.get();
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