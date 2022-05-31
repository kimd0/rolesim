#pragma once

#include "userdata.h"
#include "itemdata.h"
#include "skilldata.h"

class PlayData
{
private:
	UserData *user_data_;
	ItemData *item_data_;
	SkillData *skill_data_;

public:
	PlayData();
	~PlayData();
	void loadData();
	void newGame() const;
	void loadGame() const;
	void saveGame() const;
	void showInfo() const;
	void showInventory() const;
	void showSkill() const;
	void showCondition() const;
	void gainItem(int) const;
	void gainSkill(int) const;
	void gainMoney(int) const;
	void gainExperience(int) const;
	int changeHealth(int) const;
	int changeMana(int) const;
	int useItem(int) const;
	int useSkill(int) const;
	string getItemInfo(int) const;
	string getSkillInfo(int) const;
	int getLevelInfo() const;
};