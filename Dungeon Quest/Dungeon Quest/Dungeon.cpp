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
using namespace std;

Dungeon::Dungeon() {
	playerX = 0;
	playerY = 0;
	currentFloor = 1;
	generateFloor();
}

int Dungeon::getPlayerX() {
	return playerX;
}
int Dungeon::getPlayerY() {
	return playerY;
}
int Dungeon::getCurrentFloor() {
	return currentFloor;
}
bool Dungeon::isValidMove(int newX, int newY) {
	if (newX < 4 && newX > -1 && newY < 4 && newY > -1) {
		return true;
	}
	else {
		return false;
	}
}
void Dungeon::generateFloor() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == 3 && j == 3) {
				grid[i][j] = new Room("Exit", false, false, nullptr, nullptr);
			}
			else if (i == 0 && j == 0) {
				grid[i][j] = new Room("Empty", true, true, nullptr, nullptr);
			}
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

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (grid[i][j]->getRoomType() == "Combat") {
				if (currentFloor == 1) {
					Goblin* goblin = new Goblin();
					int roll = rand() % 100;
					if (roll < 20) {
						goblin->setLoot(new Potion("Health Potion", "Restores 50 HP", 50, 0, "Health"));
					}
					else if(roll < 40) {
						goblin->setLoot(new Potion("Mana Potion", "Restores 50 Mana", 0, 50, "Mana"));
					}
					grid[i][j]->setEnemy(goblin);
				}
				else if (currentFloor == 2) {
					Skeleton* skeleton = new Skeleton();
					int roll = rand() % 100;
					if (roll < 20) {
						skeleton->setLoot(new Potion("Health Potion", "Restores 50 HP", 50, 0, "Health"));
					}
					else if(roll < 40) {
						skeleton->setLoot(new Potion("Mana Potion", "Restores 50 Mana", 0, 50, "Mana"));
					}
					else if (roll < 60) {
						skeleton->setLoot(new Weapon("Iron Sword", "A reliable sword, sturdy and sharp", 10));
					}
					grid[i][j]->setEnemy(skeleton);
				}
				else if (currentFloor == 3) {
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
			else if (grid[i][j]->getRoomType() == "Loot") {
				int itemRoll = rand() % 100;
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
}

void Dungeon::movePlayer(char direction, Player& player) {
	int newX = playerX;
	int newY = playerY;

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

	if (isValidMove(newX, newY)) {
		playerX = newX;
		playerY = newY;
		grid[playerY][playerX]->setVisited(true);
		if (grid[playerY][playerX]->getRoomType() == "Combat") {
			Enemy* enemy = grid[playerY][playerX]->getEnemy();
			Battle::startBattle(player, *enemy);
		}
		else if (grid[playerY][playerX]->getRoomType() == "Loot") {
			Item* item = grid[playerY][playerX]->getItem();
			if (item != nullptr) {
				player.getInventory().addItem(item);
				cout << "You found: " << item->getItemName() << endl;
				grid[playerY][playerX]->setItem(nullptr);
			}
		}
		else if (grid[playerY][playerX]->getRoomType() == "Heal") {
			player.setHealth(player.getMaxHealth());
			cout << "You found a healing shrine. Health fully restored!" << endl;
		}
		else if (grid[playerY][playerX]->getRoomType() == "Exit") {
			if (currentFloor == 3) {
				cout << "You defeated the dungeon! You win!" << endl;
			}
			else {
				currentFloor++;
				playerX = 0;
				playerY = 0;
				generateFloor();
				cout << "You descended to floor " << currentFloor << endl;
			}
		}
	}
	else {
		cout << "You can't move that way." << endl;
	}
}

void Dungeon::printMap(Player& player) {
	cout << " @ = YOU  E = ENEMY ROOM  L = LOOT ROOM  X = EXIT" << endl;
	cout << "    ? = UNDISCOVERED ROOM  # = HIDDEN ROOM" << endl;
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
	cout << "   +--------+--------+--------+--------+\n" << endl;
	cout << "   -------------------------------------" << endl;
	cout << "   NAME: "<<player.getName() << "  HP: " << player.getHealth() << "/" << player.getMaxHealth() << "  ATK: " << player.getAttack()
		 << "  DEF: " << player.getDefence() << "  LVL: " << player.getLevel()
		<< endl;
	cout << "   HP: " << player.getHealth() << "/" << player.getMaxHealth()
		<< endl;
}

Room* Dungeon::getRoom(int x, int y) {
	return grid[y][x];
}
