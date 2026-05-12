#pragma once
#include<string>
#include "Room.h"
#include "Player.h"

class Dungeon {
	Room* grid[4][4];
	int playerX;
	int playerY;
	int currentFloor;
public:
	Dungeon();

    void movePlayer(char direction, Player& player);
    void printMap(Player& player);
    void generateFloor();
    bool isValidMove(int newX, int newY);
    int getPlayerX();
    int getPlayerY();
    int getCurrentFloor();
    Room* getRoom(int x, int y);
};
