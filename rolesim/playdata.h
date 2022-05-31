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
	void newGame() const;
	void loadGame() const;
	void saveGame() const;
	void showInfo() const;
	void gainItem(int) const;
	void gainSkill(int) const;
	string getItemInfo(int) const;
	string getSkillInfo(int) const;
};