#include<iostream>
#include<string>
#include <ctime>
#include <iomanip>
#include "Game.h"
using namespace std;

void Game::run() {
	srand(time(nullptr));
	cout << "     +---------------------------------+" << endl;
	cout << "     |          DUNGEON QUEST          |" << endl;
	cout << "     |      THE DUNGEON AWAITS YOU     |" << endl;
	cout << "     +---------------------------------+\n\n" << endl;

	
	cout << " Choose Your Hero.\n" << endl;
	cout << " 1) ----(HERO)----" << endl;
	cout << "       WARRIOR" << endl;
	cout << " A hardened fighter, built for close combat.\n High health and defense but slow on their feet" << endl;
	cout << "   ----(STATS)----" << endl;
	cout << " HP: 120  ATK: 15  DEF: 12  SPEED: 5" << endl;
	cout << " ABILITY: Power Strike - deals 1.5x damage\n\n" << endl;

	cout << " 2) ----(HERO)----" << endl;
	cout << "         MAGE" << endl;
	cout << " A scholar of the arcane arts.\n Devastating spell power but fragile in direct combat." << endl;
	cout << "   ----(STATS)----" << endl;
	cout << " HP: 70  ATK: 10  DEF: 5  SPEED: 7" << endl;
	cout << " ABILITY: Cast Spell - deals bonus damage, costs mana\n\n" << endl;

	cout << " 3) ----(HERO)----" << endl;
	cout << "        Rogue" << endl;
	cout << " A swift and cunning trickster. Strikes fast and hits\n hard with a chance to land critical blows." << endl;
	cout << "   ----(STATS)----" << endl;
	cout << " HP: 90  ATK: 12  DEF: 6  SPEED: 10" << endl;
	cout << " ABILITY: Critical Hit - 30% chance to deal 2x damage\n\n" << endl;

	Player* player = nullptr;

	int heroSelect;
	cout << " Select: ";

	while (!(cin >> heroSelect) || heroSelect < 1 || heroSelect > 3) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << " Invalid input. Choose 1, 2 or 3: ";
	}

		if (heroSelect == 1) {
			player = new Warrior();
		}
		else if (heroSelect == 2) {
			player = new Mage();
		}
		else if (heroSelect == 3) {
			player = new Rogue();
		}

	Dungeon dungeon;

	while (true) {
		dungeon.printMap(*player);
		char playerMove;
		cin >> playerMove;

		if (playerMove == 'i') {
			player->getInventory().displayItems(*player);
		}
		else {
			dungeon.movePlayer(playerMove, *player);
		}

		if (!player->isAlive()) {
			cout << "  YOU LOST" << endl;
			break;
		}
		if (dungeon.isGameWon() == true) {
			break;
		}
	}
	
	


}