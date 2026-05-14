#pragma once
#include<string>
using namespace std;

class Player;
class Item {
	string name;
	string description;
public:
	Item(string name, string description) {
		this->name = name;
		this->description = description;
	}
	virtual void use(Player& player) = 0;

	string getItemName();
	string getItemDescription();
};
