#pragma once

#include <random>

#include "datamanager.h"

using namespace std;

class StageManager
{
private:
	DataManager *play_data_;
	bool monsterStage();
	void npcStage();
	bool computeProb(int);
public:
	StageManager(DataManager&);
	bool newStage();
};