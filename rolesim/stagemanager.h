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
	MonsterData *monster_data_;
	const PlayData* play_data_;
	bool monsterStage();
	void npcStage();
	bool computeProb(int);
public:
	StageManager(const PlayData&);
	~StageManager();
	bool newStage();
};