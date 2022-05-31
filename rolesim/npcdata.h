#pragma once

#include <vector>
#include <fstream>
#include <iostream>
#include <filesystem>
#include "npc.h"

using namespace std;

class NpcData
{
private:
	vector<Npc> npcs_;
	void readFile(int);
public:
	NpcData();
	void loadData();
	Npc getRandomNpc();
};