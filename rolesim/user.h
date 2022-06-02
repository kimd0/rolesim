#pragma once

#include <string>
#include <vector>
#include <filesystem>
#include "itemdata.h"
#include "skilldata.h"

class User
{
private:
	string name_;
	int level_;
	int health_;
	int current_health_;
	int mana_;
	int current_mana_;
	int experience_;
	int money_;
	vector<int> skill_;
	vector<int> item_;
public:
	User();
	User(string, int, int, int, int, int, vector<int>, vector<int>);
	void showCondition() const;
	void showItem(const ItemData&) const;
	void showSkill(const SkillData&) const;
	void showStatus(const SkillData&, const ItemData&) const;
	void addSkill(int);
	void addItem(int);
	int useItem(ItemData&, int);
	int useSkill(SkillData&, int);
	int addExperience(int);
	int addHealth(int);
	int addMana(int);
	void addMoney(int);
	void levelUp();

	string getName();
	int getLevel();
	int getExperience();
	int getHealth();
	int getMana();
	int getMoney();
	vector<int> getSkill();
	vector<int> getItem();
};

