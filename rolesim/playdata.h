#pragma once

#include "userdata.h"
#include "npcdata.h"
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
	void newGame();
	void loadGame();
	void saveGame();
	void showInfo();
	void gainItem(int);
	void gainSkill(int);
	string getItemInfo(int);
	string getSkillInfo(int);
};