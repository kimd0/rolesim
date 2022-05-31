#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <filesystem>
#include <cstdlib>
#include <ctime>
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