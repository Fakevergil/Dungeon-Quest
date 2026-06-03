#include<iostream>
#include<string>
#include "Room.h"
using namespace std;

// Returns the type of room
// (Combat, Loot, Heal, Empty, Exit, etc.)
string Room::getRoomType() {
	return roomType;
}

// Returns whether the room has been visited
bool Room::getIsVisited() {
	return isVisited;
}

// Returns whether the room has been revealed on the map
bool Room::getIsRevealed() {
	return isRevealed;
}

// Returns the enemy stored in this room
Enemy* Room::getEnemy() {
	return enemy;
}

// Returns the item stored in this room
Item* Room::getItem() {
	return item;
}

// Marks the room as visited or unvisited
void Room::setVisited(bool visited) {
	isVisited = visited;
}

// Marks the room as revealed or hidden
void Room::setRevealed(bool revealed) {
	isRevealed = revealed;
}

// Checks whether the room contains neither
// an enemy nor an item
bool Room::isEmpty() {
	return enemy == nullptr && item == nullptr;
}

// Assigns an enemy to the room
void Room::setEnemy(Enemy* enemy) {
	this->enemy = enemy;
}

// Assigns an item to the room
void Room::setItem(Item* item) {
	this->item = item;
}