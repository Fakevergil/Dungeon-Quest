#include<iostream>
#include<string>
#include "Item.h"
using namespace std;

// Returns the name of the item
string Item::getItemName() {
	return name;
}

// Returns the description of the item
string Item::getItemDescription() {
	return description;
}