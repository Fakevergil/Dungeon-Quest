#include<iostream>
#include<string>
#include "Potion.h"
#include "Item.h"
using namespace std;

int Potion::getHealAmount() {
    return healAmount;
}

int Potion::getManaAmount() {
    return manaAmount;
}

string Potion::getPotionType() {
    return potionType;
}

void Potion::use(Player& player) {
    if (potionType == "Health") {
        player.setHealth(player.getHealth() + healAmount);
        if (player.getHealth() > player.getMaxHealth()) {
            player.setHealth(player.getMaxHealth());
        }
    }
    else if (potionType == "Mana") {
        player.restoreMana(manaAmount);
    }
}