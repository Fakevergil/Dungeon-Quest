#include<iostream>
#include<string>
#include "Potion.h"
#include "Item.h"
using namespace std;

// Returns the amount of health restored by the potion
int Potion::getHealAmount() {
    return healAmount;
}

// Returns the amount of mana restored by the potion
int Potion::getManaAmount() {
    return manaAmount;
}

// Returns the potion's type ("Health" or "Mana")
string Potion::getPotionType() {
    return potionType;
}

// Uses the potion on the player
void Potion::use(Player& player) {

    // Health potion restores HP
    if (potionType == "Health") {

        // Increase player's health
        player.setHealth(player.getHealth() + healAmount);

        // Prevent health from exceeding maximum health
        if (player.getHealth() > player.getMaxHealth()) {
            player.setHealth(player.getMaxHealth());
        }
    }

    // Mana potion restores mana
    else if (potionType == "Mana") {
        player.restoreMana(manaAmount);
    }
}