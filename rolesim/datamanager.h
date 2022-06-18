#pragma once

#include <random>

#include "monsterdata.h"
#include "npcdata.h"
#include "userdata.h"
#include "itemdata.h"
#include "skilldata.h"

class DataManager
{
private:
	UserData *user_data_;
	ItemData *item_data_;
	SkillData *skill_data_;
	NpcData* npc_data_;
	MonsterData* monster_data_;
	User user_;
public:
	DataManager();
	~DataManager();
	void loadData();
	void newGame();
	void loadGame();
	void saveGame() const;
	void showData() const;
	void showInfo() const;
	void showInventory() const;
	void showSkill() const;
	void showCondition() const;
	void gainItem(int);
	void gainSkill(int);
	void gainMoney(int);
	void gainExperience(int);
	int changeHealth(int);
	int changeMana(int);
	int useItem(int);
	int useSkill(int);
	string getItemInfo(int) const;
	string getSkillInfo(int) const;
	int getLevelInfo() const;
	vector<Monster> getMonsterList() const;
	vector<Npc> getNpcList() const;
};