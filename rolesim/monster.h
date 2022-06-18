#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Monster
{
private:
	typedef vector<int> reward_item_list_t;
	string name_;
	int level_;
	int health_;
	reward_item_list_t items_;
	string appearence_;
public:
	Monster(string, int, int, vector<int>, string);
	string getName() const;
	int getLevel() const;
	int getHealth() const;
	string getAppearence() const;
	void setDifficulty(int);
	int actionAtk() const;
	void actionDef(int);
	vector<int> getReward();
};

