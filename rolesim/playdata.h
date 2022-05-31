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
	void gainItem(int) const;
	void gainSkill(int) const;
	void changeHealth(int) const;
	void changeMana(int) const;
	int useItem(int) const;
	string getItemInfo(int) const;
	string getSkillInfo(int) const;
	int getLevelInfo() const;
};