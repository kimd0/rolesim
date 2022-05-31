#pragma once

#include <random>
#include "playdata.h"

using namespace std;

class StageManager
{
private:
	//monster_data_ should be here
	NpcData *npc_data_;
	PlayData play_data_;
	bool monsterStage();
	void npcStage();
	bool computeProbability(int);
public:
	StageManager(PlayData&);
	~StageManager();
	bool newStage();
};