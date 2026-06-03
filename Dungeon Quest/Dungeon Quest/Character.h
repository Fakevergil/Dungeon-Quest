#pragma once
#include<string>
using namespace std;

// Base class representing any character in the game (player or enemy)
class Character {
protected:
	string name;        // Character name
	int health;         // Current health
	int maxHealth;      // Maximum health
	int attack;         // Attack power
	int defence;        // Defence stat (reduces incoming damage)
	int speed;          // Speed (determines turn order)
	int level;          // Current level
	int experience;     // Experience points

public:

	// Constructor initializes all character attributes
	Character(string name, int health, int maxHealth, int attack, int defence, int speed, int level, int experience) {
		this->name = name;
		this->health = health;
		this->maxHealth = maxHealth;
		this->attack = attack;
		this->defence = defence;
		this->speed = speed;
		this->level = level;
		this->experience = experience;
	}

	// Applies damage to the character (can be overridden)
	virtual void takeDamage(int damage);

	// Checks if character is still alive
	bool isAlive();

	// Attacks another character (can be overridden)
	virtual void attackTarget(Character& target);

	// Adds experience points
	void gainExperience(int XP);

	// Getter functions
	int getHealth();
	int getAttack();
	string getName();
	int getDefence();
	int getSpeed();
	int getLevel();
	int getMaxHealth();

	// Setter functions
	void setHealth(int health);
	void setAttack(int attack);
	void setDefence(int defence);

	// Virtual destructor for proper cleanup in inheritance
	virtual ~Character() = default;
};