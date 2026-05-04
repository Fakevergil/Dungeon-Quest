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