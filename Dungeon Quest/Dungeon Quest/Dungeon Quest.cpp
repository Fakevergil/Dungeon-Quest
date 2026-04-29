#include <iostream>
#include "Character.h"
#include "Battle.h"
#include "Player.h"
#include "Enemy.h"
#include "Goblin.h"
#include "Skeleton.h"
#include "Boss.h"

int main()
{
    Player player("Hero", 150, 150, 100, 200, 100, 0, 0, 0, 0,100, false);
    Goblin goblin;
    Skeleton skeleton;
    Boss boss;

    Battle::startBattle(player, goblin);
    Battle::startBattle(player, skeleton);
    Battle::startBattle(player, boss);
}

