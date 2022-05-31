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
	void ReadFile(int);
public:
	NpcData();
	void LoadData();
	Npc GetRandomNpc();
};