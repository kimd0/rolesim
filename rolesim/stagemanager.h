#pragma once

#include <random>

#include "monsterdata.h"
#include "npcdata.h"
#include "playdata.h"

using namespace std;

class StageManager
{
private:
	NpcData *npc_data_;
	MonsterData* monster_data_;
	PlayData play_data_;
	bool monsterStage();
	void npcStage();
	bool computeProb(int);
public:
	StageManager(PlayData&);
	~StageManager();
	bool newStage();
};