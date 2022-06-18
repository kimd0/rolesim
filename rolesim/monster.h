#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <random>

using namespace std;

class Monster
{
private:
	string name_;
	int level_;
	int health_;
	vector<int> items_;
	string appearence_;
public:
	Monster(string, int, int, vector<int>, string);
	string getName() const;
	int getLevel() const;
	int getHealth() const;
	string getAppearence() const;
	void setDifficulty(int);
	int actionAtk();
	void actionDef(int);
	vector<int> getReward();
};

