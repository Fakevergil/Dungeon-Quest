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
	void virtual use();
};
