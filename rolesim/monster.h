#pragma once

#include <string>
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
	string getName();
	int getLevel();
	int getHealth();
	string getAppearence();
	void setDifficulty(int);
	int actionAtk();
	void actionDef(int);
	vector<int> getReward();
};

