#include<iostream>
#include<string>
#include "Goblin.h"
using namespace std;

// Constructor initializes Goblin enemy with predefined stats
Goblin::Goblin() : Enemy("Goblin", 30, 30, 8, 3, 6, 1, 0, 20) {
	// No extra initialization required
}