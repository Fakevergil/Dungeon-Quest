#pragma once
#include<string>
using namespace std;

class Item {
	string name;
	string description;
public:
	Item(string name, string description) {
		this->name = name;
		this->description;
	}
	virtual void use() = 0;

	string getItemName();
	string getItemDescription();
};
