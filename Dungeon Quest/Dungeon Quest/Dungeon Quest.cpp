#include <iostream>
#include "Character.h"
#include "Battle.h"
#include "Player.h"
#include "Enemy.h"
#include "Goblin.h"
#include "Skeleton.h"
#include "Boss.h"
#include "Warrior.h"
#include "Mage.h"
#include "Rogue.h"
#include "Dungeon.h"

int main()
{
    Warrior warrior;
    Mage mage;
    Rogue rogue;
    Goblin goblin;
    Skeleton skeleton;
    Boss boss;

    Dungeon dungeon;
    dungeon.generateFloor();
    dungeon.printMap();
}

