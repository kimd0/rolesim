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
	NpcData *npc_data_;

public:
	PlayData();
	~PlayData();
	void LoadData();
	void NewGame();
	void LoadGame();
	void SaveGame();
	void ShowInfo();
};