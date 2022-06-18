#pragma once

#include <string>
#include <vector>
#include <filesystem>
#include "itemdata.h"
#include "skilldata.h"

class User
{
private:
	typedef vector<int> skill_list_t;
	typedef vector<int> item_list_t;
	string name_;
	int level_;
	int experience_;
	int health_;
	int current_health_;
	int mana_;
	int current_mana_;
	int money_;
	skill_list_t skill_;
	item_list_t item_;
public:
	User();
	User(string, int, int, int, int, int, skill_list_t, item_list_t);
	void showCondition() const;
	void showItem(const ItemData&) const;
	void showSkill(const SkillData&) const;
	void showStatus(const SkillData&, const ItemData&) const;
	void addSkill(int);
	void addItem(int);
	int useItem(const ItemData&, int);
	int useSkill(const SkillData&, int);
	int addExperience(int);
	int addHealth(int);
	int addMana(int);
	void addMoney(int);
	void levelUp();
	string getName() const;
	int getLevel() const;
	int getExperience() const;
	int getHealth() const;
	int getMana() const;
	int getMoney() const;
	skill_list_t getSkill() const;
	item_list_t getItem() const;
};