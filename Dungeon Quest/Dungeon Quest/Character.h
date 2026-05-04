#pragma once
#include<string>
using namespace std;

class Character {
protected:
	string name;
	int health;
	int maxHealth;
	int attack;
	int defence;
	int speed;
	int level;
	int experience;
public:
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

	virtual void takeDamage(int damage);
	bool isAlive();
	virtual void attackTarget(Character& target);
	void gainExperience(int XP);
	int getHealth();
	int getAttack();
	string getName();
	int getDefence();
	int getSpeed();
	int getLevel();
	int getMaxHealth();
	void setHealth(int health);
	void setAttack(int attack);
	void setDefence(int defence);
	virtual ~Character() = default;
};
