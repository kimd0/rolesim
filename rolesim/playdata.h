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
	User user_;
public:
	PlayData();
	~PlayData();
	void loadData();
	void newGame();
	void loadGame();
	void saveGame();
	void showInfo();
	void showInventory();
	void showSkill();
	void showCondition();
	void gainItem(int);
	void gainSkill(int);
	void gainMoney(int);
	void gainExperience(int);
	int changeHealth(int);
	int changeMana(int);
	int useItem(int);
	int useSkill(int);
	string getItemInfo(int);
	string getSkillInfo(int);
	int getLevelInfo();
};