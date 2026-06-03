#include<iostream>
#include<string>
#include "Battle.h"
#include "Mage.h"
#include "Inventory.h"

// Starts and manages the entire battle sequence
void Battle::startBattle(Player& player, Enemy& enemy) {
	int playerMove; // Stores player's menu choice
	bool playerFled = false; // Tracks whether the player escaped
	bool enemyFirst = enemy.getSpeed() > player.getSpeed(); // Determines who attacks first
	bool firstTurn = true; // Used to ensure first-turn logic only happens once

	// Main battle loop continues while both combatants are alive
	while (player.isAlive() && enemy.isAlive()) {
		system("cls"); // Clear console screen

		// Battle header
		cout << "  +==========================================+" << endl;
		cout << "  |               *** BATTLE ***            |" << endl;
		cout << "  +==========================================+\n" << endl;


		// Display enemy information
		cout << "  ENEMY" << endl;
		cout << "  +------------------------------------------+" << endl;
		cout << "  | NAME  : " << enemy.getName() << endl;
		cout << "  | HP    : " << enemy.getHealth() << "/" << enemy.getMaxHealth() << endl;
		cout << "  | ATK   : " << enemy.getAttack() << "   DEF: " << enemy.getDefence() << endl;
		cout << "  +------------------------------------------+\n" << endl;


		// Display player information
		cout << "  YOU" << endl;
		cout << "  +------------------------------------------+" << endl;
		cout << "  | NAME  : " << player.getName() << endl;
		cout << "  | HP    : " << player.getHealth() << "/" << player.getMaxHealth() << endl;
		cout << "  | MANA  : " << player.getMana() << "/" << player.getMaxMana() << endl;
		cout << "  | ATK   : " << player.getAttack() << "   DEF: " << player.getDefence() << endl;
		cout << "  +------------------------------------------+\n" << endl;

		// Enemy attacks first if it has greater speed
		if (enemyFirst && firstTurn) {
			cout << "  !! " << enemy.getName() << " ATTACKS FIRST !!" << endl;
			cout << "  +------------------------------------------+" << endl;
			enemy.chooseAction(player); // Enemy takes its turn
			cout << "  +------------------------------------------+\n" << endl;

			// End battle if player dies
			if (!player.isAlive()) break;

			firstTurn = false;
		}
		firstTurn = false;

		// Player action menu
		cout << "  +------------------------------------------+" << endl;
		cout << "  |           WHAT WILL YOU DO?             |" << endl;
		cout << "  +------------------------------------------+" << endl;

		// Special menu for Mage class
		if (player.getPlayerType() == "Mage") {
			Mage& mage = dynamic_cast<Mage&>(player); // Cast player to Mage

			cout << "  | [1] Attack                              |" << endl;
			cout << "  | [2] Cast Spell                          |" << endl;
			cout << "  | [3] Use Item                            |" << endl;
			cout << "  | [4] Flee                                |" << endl;
			cout << "  +------------------------------------------+" << endl;
			cout << "  SELECT: ";
			while (!(cin >> playerMove) || playerMove < 1 || playerMove > 4) {
				cin.clear();                  // Clear error flags
				cin.ignore(1000, '\n');      // Remove invalid input
				cout << " Invalid input. Choose 1, 2, 3 or 4: ";
			}

			// Normal attack option
			if (playerMove == 1) {
				cout << "  >> " << player.getName() << " ATTACKS " << enemy.getName() << "!" << endl;
				player.attackTarget(enemy);

				// Stop if enemy dies
				if (!enemy.isAlive()) break;

				cout << "\n  >> " << enemy.getName() << " RETALIATES!" << endl;
				enemy.chooseAction(player);
			}

			// Mage spell attack option
			else if (playerMove == 2) {
				cout << "  >> " << player.getName() << " CASTS A SPELL!" << endl;
				mage.castSpell(enemy);

				// Stop if enemy dies
				if (!enemy.isAlive()) break;

				cout << "\n  >> " << enemy.getName() << " RETALIATES!" << endl;
				enemy.chooseAction(player);
			}

			// Use inventory item
			else if (playerMove == 3) {
				Inventory& inventory = player.getInventory();

				// Check if inventory is empty
				if (inventory.getSize() <= 0) {
					cout << "  >> YOU HAVE NO ITEMS IN YOUR INVENTORY!" << endl;
				}
				else {
					// Display inventory contents
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

					while (!(cin >> choice) || choice < 0 || choice > inventory.getSize()) {
						cin.clear();                  // Clear error flags
						cin.ignore(1000, '\n');      // Remove invalid input
						cout << " Invalid input: ";
					}

					// Use selected item
					if (choice != 0 && choice <= inventory.getSize()) {
						string itemName = inventory.getItem(choice - 1)->getItemName();
						player.useItem(choice - 1);

						cout << "  >> YOU USED: " << itemName << "!" << endl;

						// Enemy gets a turn after item use
						enemy.chooseAction(player);
					}
				}
			}

			// Attempt to flee
			else if (playerMove == 4) {
				playerFled = true;
				break;
			}
		}

		// Menu for non-Mage classes
		else {
			cout << "  | [1] Attack                              |" << endl;
			cout << "  | [2] Use Item                            |" << endl;
			cout << "  | [3] Flee                                |" << endl;
			cout << "  +------------------------------------------+" << endl;
			cout << "  SELECT: ";
			while (!(cin >> playerMove) || playerMove < 1 || playerMove > 3) {
				cin.clear();                  // Clear error flags
				cin.ignore(1000, '\n');      // Remove invalid input
				cout << " Invalid input. Choose 1, 2 or 3: ";
			}

			// Normal attack
			if (playerMove == 1) {
				cout << "  >> " << player.getName() << " ATTACKS " << enemy.getName() << "!" << endl;
				player.attackTarget(enemy);

				// Stop if enemy dies
				if (!enemy.isAlive()) break;

				cout << "\n  >> " << enemy.getName() << " RETALIATES!" << endl;
				enemy.chooseAction(player);

				cout << "  PRESS ENTER TO CONTINUE...";
				cin.ignore();
				cin.get();
			}

			// Use inventory item
			else if (playerMove == 2) {
				Inventory& inventory = player.getInventory();

				// Check if inventory is empty
				if (inventory.getSize() <= 0) {
					cout << "  >> YOU HAVE NO ITEMS IN YOUR INVENTORY!" << endl;
				}
				else {
					// Display inventory
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
					while (!(cin >> choice) || choice < 0 || choice > inventory.getSize()) {
						cin.clear();                  // Clear error flags
						cin.ignore(1000, '\n');      // Remove invalid input
						cout << " Invalid input: ";
					}

					// Use selected item
					if (choice != 0 && choice <= inventory.getSize()) {
						string itemName = inventory.getItem(choice - 1)->getItemName();
						player.useItem(choice - 1);

						cout << "  >> YOU USED: " << itemName << "!" << endl;

						// Enemy takes a turn after item use
						enemy.chooseAction(player);
					}
				}
			}

			// Attempt to flee
			else if (playerMove == 3) {
				playerFled = true;
				break;
			}
		}
	}

	system("cls");

	// Display flee message if player escaped
	if (playerFled) {
		cout << "  +==========================================+" << endl;
		cout << "  |              YOU FLED!                  |" << endl;
		cout << "  +==========================================+" << endl;
	}
	else {
		// Display battle results
		battleOutcome(player, enemy);
	}

	// Pause before returning
	cout << "  PRESS ENTER TO CONTINUE...";
	cin.ignore();
	cin.get();
}

// Handles victory/defeat rewards and messages
void Battle::battleOutcome(Player& player, Enemy& enemy) {

	// Player victory
	if (player.isAlive()) {
		cout << "  " << player.getName() << " WINS" << endl;

		// Award experience points
		player.gainExperience(enemy.getXPrewards());

		cout << "  XP GAINED: " << enemy.getXPrewards() << endl;
		cout << "  TOTAL XP: " << player.getXPPoints() << endl;
		cout << "  --------------------" << "\n" << endl;

		// Check for level up
		player.levelUp();

		if (player.leveledUp()) {
			cout << "  LEVELED UP: " << player.getLevel() << endl;
			cout << "  MAX HEALTH INCREASED: " << player.getHealth() << endl;
			cout << "  ATTACK INCREASED: " << player.getAttack() << endl;
			cout << "  --------------------" << "\n" << endl;
		}
	}

	// Enemy victory
	if (enemy.isAlive()) {
		cout << "  " << enemy.getName() << " WINS" << endl;
	}
}