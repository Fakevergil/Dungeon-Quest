#include<iostream>
#include<string>
#include "Dungeon.h"
#include "Goblin.h"
#include "Skeleton.h"
#include "Boss.h"
#include "Potion.h"
#include "Weapon.h"
#include "Player.h"
#include "Battle.h"
using std::cout;

// Constructor initializes player position, floor number,
// win state, and generates the first floor
Dungeon::Dungeon() {
	playerX = 0;
	playerY = 0;
	currentFloor = 1;
	gameWon = false;
	generateFloor();
}

// Returns player's current X coordinate
int Dungeon::getPlayerX() {
	return playerX;
}

// Returns player's current Y coordinate
int Dungeon::getPlayerY() {
	return playerY;
}

// Returns the current dungeon floor
int Dungeon::getCurrentFloor() {
	return currentFloor;
}

// Checks if a movement position is inside the 4x4 grid
bool Dungeon::isValidMove(int newX, int newY) {
	if (newX < 4 && newX > -1 && newY < 4 && newY > -1) {
		return true;
	}
	else {
		return false;
	}
}

// Generates a new dungeon floor with rooms, enemies, and loot
void Dungeon::generateFloor() {

	// Generate room types
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {

			// Exit room is always at bottom-right corner
			if (i == 3 && j == 3) {
				grid[i][j] = new Room("Exit", false, false, nullptr, nullptr);
			}

			// Starting room is always top-left corner
			else if (i == 0 && j == 0) {
				grid[i][j] = new Room("Empty", true, true, nullptr, nullptr);
			}

			// Randomly generate room types
			else {
				int randRoll = rand() % 100;

				if (randRoll <= 59) {
					grid[i][j] = new Room("Combat", false, false, nullptr, nullptr);
				}
				else if (randRoll <= 79) {
					grid[i][j] = new Room("Loot", false, false, nullptr, nullptr);
				}
				else if (randRoll <= 94) {
					grid[i][j] = new Room("Heal", false, false, nullptr, nullptr);
				}
				else if (randRoll <= 100) {
					grid[i][j] = new Room("Empty", false, false, nullptr, nullptr);
				}
			}
		}
	}

	// Populate rooms with enemies and items
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {

			// Combat room setup
			if (grid[i][j]->getRoomType() == "Combat") {

				// Floor 1 enemies
				if (currentFloor == 1) {
					Goblin* goblin = new Goblin();

					int roll = rand() % 100;

					if (roll < 20) {
						goblin->setLoot(new Potion("Health Potion", "Restores 50 HP", 50, 0, "Health"));
					}
					else if (roll < 40) {
						goblin->setLoot(new Potion("Mana Potion", "Restores 50 Mana", 0, 50, "Mana"));
					}

					grid[i][j]->setEnemy(goblin);
				}

				// Floor 2 enemies
				else if (currentFloor == 2) {
					Skeleton* skeleton = new Skeleton();

					int roll = rand() % 100;

					if (roll < 20) {
						skeleton->setLoot(new Potion("Health Potion", "Restores 50 HP", 50, 0, "Health"));
					}
					else if (roll < 40) {
						skeleton->setLoot(new Potion("Mana Potion", "Restores 50 Mana", 0, 50, "Mana"));
					}
					else if (roll < 60) {
						skeleton->setLoot(new Weapon("Iron Sword", "A reliable sword, sturdy and sharp", 10));
					}

					grid[i][j]->setEnemy(skeleton);
				}

				// Floor 3 enemies
				else if (currentFloor == 3) {

					// Randomly choose Goblin or Skeleton
					int roll = rand() % 2;

					if (roll == 0) {
						Goblin* goblin = new Goblin();

						int roll = rand() % 100;

						if (roll < 20) {
							goblin->setLoot(new Potion("Health Potion", "Restores 50 HP", 50, 0, "Health"));
						}
						else if (roll < 40) {
							goblin->setLoot(new Potion("Mana Potion", "Restores 50 Mana", 0, 50, "Mana"));
						}

						grid[i][j]->setEnemy(goblin);
					}
					else {
						Skeleton* skeleton = new Skeleton();

						int roll = rand() % 100;

						if (roll < 20) {
							skeleton->setLoot(new Potion("Health Potion", "Restores 50 HP", 50, 0, "Health"));
						}
						else if (roll < 40) {
							skeleton->setLoot(new Potion("Mana Potion", "Restores 50 Mana", 0, 50, "Mana"));
						}
						else if (roll < 60) {
							skeleton->setLoot(new Weapon("Iron Sword", "A reliable sword, sturdy and sharp", 10));
						}

						grid[i][j]->setEnemy(skeleton);
					}
				}
			}

			// Loot room setup
			else if (grid[i][j]->getRoomType() == "Loot") {

				int itemRoll = rand() % 100;

				// Generate weapon
				if (itemRoll <= 49) {

					int weaponRoll = rand() % 100;

					if (weaponRoll <= 49) {
						grid[i][j]->setItem(new Weapon("Rusty Dagger", "A worn blade, better than nothing", 5));
					}
					else if (weaponRoll <= 79) {
						grid[i][j]->setItem(new Weapon("Iron Sword", "A reliable sword, sturdy and sharp", 10));
					}
					else if (weaponRoll <= 94) {
						grid[i][j]->setItem(new Weapon("Steel Blade", "A finely crafted blade with a keen edge", 18));
					}
					else if (weaponRoll <= 99) {
						grid[i][j]->setItem(new Weapon("Shadow Fang", "A mysterious blade said to be forged in darkness", 30));
					}
				}

				// Generate potion
				else {
					int randRoll = rand() % 100;

					if (randRoll <= 49) {
						grid[i][j]->setItem(new Potion("Health Potion", "Restores 50 HP", 50, 0, "Health"));
					}
					else if (randRoll <= 99) {
						grid[i][j]->setItem(new Potion("Mana Potion", "Restores 50 Mana", 0, 50, "Mana"));
					}
				}
			}
		}
	}

	// Place boss on floor 3
	if (currentFloor == 3) {
		Boss* boss = new Boss();

		// Boss always drops Shadow Fang
		boss->setLoot(new Weapon("Shadow Fang", "A mysterious blade said to be forged in darkness", 30));

		// Boss room fixed at position (2,2)
		grid[2][2] = new Room("Combat", false, false, boss, nullptr);
	}
}

// Returns whether the player has won the game
bool Dungeon::isGameWon() {
	return gameWon;
}

// Handles player movement and room interactions
void Dungeon::movePlayer(char direction, Player& player) {

	// Store current position
	int newX = playerX;
	int newY = playerY;

	// Update coordinates based on movement direction
	if (direction == 'w') {
		newY--;
	}
	else if (direction == 's') {
		newY++;
	}
	else if (direction == 'd') {
		newX++;
	}
	else if (direction == 'a') {
		newX--;
	}

	// Check if move is valid
	if (isValidMove(newX, newY)) {

		playerX = newX;
		playerY = newY;

		// Mark room as visited
		grid[playerY][playerX]->setVisited(true);

		// Combat room logic
		if (grid[playerY][playerX]->getRoomType() == "Combat") {

			Enemy* enemy = grid[playerY][playerX]->getEnemy();

			// Start battle if enemy is alive
			if (enemy->isAlive()) {
				Battle::startBattle(player, *enemy);
			}

			// Winning condition: defeat boss
			if (currentFloor == 3 && playerX == 2 && playerY == 2 && !enemy->isAlive()) {
				gameWon = true;
			}
		}

		// Loot room logic
		else if (grid[playerY][playerX]->getRoomType() == "Loot") {

			Item* item = grid[playerY][playerX]->getItem();

			if (item != nullptr) {
				player.getInventory().addItem(item);

				cout << "  YOU FOUND: " << item->getItemName() << endl;

				// Remove item from room after pickup
				grid[playerY][playerX]->setItem(nullptr);

				cout << "  PRESS ENTER TO CONTINUE...";
				cin.ignore();
				cin.get();
			}
		}

		// Healing room logic
		else if (grid[playerY][playerX]->getRoomType() == "Heal") {

			// Intended to heal only once
			if (!grid[playerY][playerX]->getIsVisited()) {
				player.setHealth(player.getMaxHealth());

				cout << "  YOU FOUND A HEALING SHRINE, HEALTH FULLY RESTORED!" << endl;

				cout << "  PRESS ENTER TO CONTINUE...";
				cin.ignore();
				cin.get();
			}
		}

		// Exit room logic
		else if (grid[playerY][playerX]->getRoomType() == "Exit") {

			Boss* boss;

			// Cannot leave floor 3 before defeating boss
			if (currentFloor == 3 && !isGameWon()) {
				cout << "  YOU CANNOT LEAVE THE DUNGEON YET" << endl;

				cout << "  PRESS ENTER TO CONTINUE...";
				cin.ignore();
				cin.get();
			}

			// Victory message
			else if (currentFloor == 3 && isGameWon()) {
				cout << "  YOU DEFEATED THE DUNGEON! YOU WIN" << endl;
			}

			// Move to next floor
			else {
				currentFloor++;

				playerX = 0;
				playerY = 0;

				generateFloor();

				cout << "  YOU DECENDED TO FLOOR " << currentFloor << endl;

				cout << "  PRESS ENTER TO CONTINUE...";
				cin.ignore();
				cin.get();
			}
		}
	}
	else {
		// Invalid movement message
		cout << "  YOU CAN'T MOVE THAT WAY" << endl;

		cout << "  PRESS ENTER TO CONTINUE...";
		cin.ignore();
		cin.get();
	}
}

// Displays the dungeon map and player stats
void Dungeon::printMap(Player& player) {

	system("cls");

	Inventory& weapon = player.getInventory();

	cout << " @ = YOU  E = ENEMY ROOM  L = LOOT ROOM  X = EXIT" << endl;
	cout << "    ? = UNDISCOVERED ROOM  # = HIDDEN ROOM" << endl;

	// Draw map grid
	for (int i = 0; i < 4; i++) {

		cout << "   +--------+--------+--------+--------+" << endl;

		for (int j = 0; j < 4; j++) {

			if (i == playerY && j == playerX) {
				cout << "   |   @ ";
			}
			else if (grid[i][j]->getRoomType() == "Exit") {
				cout << "   |   X ";
			}
			else if (grid[i][j]->getIsVisited()) {

				if (grid[i][j]->getRoomType() == "Combat") {
					cout << "   |   E ";
				}
				else if (grid[i][j]->getRoomType() == "Loot") {
					cout << "   |   L ";
				}
				else if (grid[i][j]->getRoomType() == "Heal") {
					cout << "   |   H ";
				}
				else if (grid[i][j]->getRoomType() == "Empty") {
					cout << "   |   . ";
				}
			}
			else if (grid[i][j]->getIsRevealed()) {
				cout << "   |   ? ";
			}
			else {
				cout << "   |   # ";
			}
		}

		cout << "   |";
		cout << endl;
	}

	// Bottom border
	cout << "   +--------+--------+--------+--------+\n" << endl;

	// Player statistics
	cout << "   --------------------------------------------" << endl;
	cout << "   NAME: " << player.getName()
		<< "  HP: " << player.getHealth() << "/" << player.getMaxHealth()
		<< "  ATK: " << player.getAttack()
		<< "  DEF: " << player.getDefence()
		<< endl;

	cout << "   SPEED: " << player.getSpeed()
		<< "  LVL: " << player.getLevel();

	// Show equipped weapon if one exists
	if (weapon.getEquippedWeapon() != nullptr) {
		cout << "  EQUIPPED WEAPON: "
			<< weapon.getEquippedWeapon()->getItemName()
			<< "\n" << endl;
	}

	cout << "   USE THE 'WASD TO MOVE'" << endl;
	cout << "   PRESS 'I' TO VIEW YOUR INVENTORY" << endl;
	cout << "   --------------------------------------------" << endl;
}

// Returns the room at the specified coordinates
Room* Dungeon::getRoom(int x, int y) {
	return grid[y][x];
}