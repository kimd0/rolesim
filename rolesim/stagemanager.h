#pragma once

#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "playdata.h"

using namespace std;

class StageManager
{
private:
	//monster_data_ should be here
	NpcData *npc_data_;
	PlayData play_data_;
	bool MonsterStage();
	void NpcStage();
public:
	StageManager(PlayData&);
	~StageManager();
	bool NewStage();
};