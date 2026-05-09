#include<iostream>
#include<string>
#include "Room.h"
using namespace std;

string Room::getRoomType() {
	return roomType;
}
bool Room::getIsVisited() {
	return isVisited;
}
bool Room::getIsRevealed() {
	return isRevealed;
}
Enemy* Room::getEnemy() {
	return enemy;
}
Item* Room::getItem() {
	return item;
}
void Room::setVisited(bool visited) {
	isVisited = visited;
}
void Room::setRevealed(bool revealed) {
	isRevealed = revealed;
}
bool Room::isEmpty() {
	return enemy == nullptr && item == nullptr;
}
void Room::setEnemy(Enemy* enemy) {
	this->enemy = enemy;
}
void Room::setItem(Item* item) {
	this->item = item;
}