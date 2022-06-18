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
	int randomNumber(int = 0, int = 99);
public:
	StageManager(DataManager&);
	bool newStage();
};