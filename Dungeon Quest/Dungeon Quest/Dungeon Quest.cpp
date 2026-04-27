#include <iostream>
#include "Character.h"
#include "Battle.h"
#include "Player.h"
#include "Enemy.h"

int main()
{
    Player player("Hero", 150, 150, 100, 200, 100, 0, 0, 0, 0,100, false);
    Enemy enemy("Enemy", 50, 100, 50, 100, 100, 200, 100, 100);
    Enemy enemy2("Enemy", 50, 100, 50, 100, 100, 200, 100, 100);
    Enemy enemy3("Enemy", 50, 100, 50, 100, 100, 200, 100, 6000);

    Battle::startBattle(player, enemy);
    Battle::startBattle(player, enemy2);
    Battle::startBattle(player, enemy3);
}

