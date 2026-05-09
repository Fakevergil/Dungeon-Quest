#pragma once
#include<string>
#include "Enemy.h"
using namespace std;
class Item;
class Room {
	string roomType;
	bool isVisited;
	bool isRevealed;
	Enemy* enemy;
	Item* item;
public:
	Room(string roomType, bool isVisited, bool isRevealed, Enemy* enemy, Item* item) {
		this->roomType = roomType;
		this->isVisited = isVisited;
		this->isRevealed = isRevealed;
		this->enemy = enemy;
		this->item = item;
	}

	string getRoomType();
	bool getIsVisited();
	bool getIsRevealed();
	Enemy* getEnemy();
	Item* getItem();
	void setVisited(bool visited);
	void setRevealed(bool revealed);
	bool isEmpty();
	void setEnemy(Enemy* enemy);
	void setItem(Item* item);

};
