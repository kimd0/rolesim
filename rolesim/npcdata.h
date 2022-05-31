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

using namespace std;

class NpcData
{
private:
	vector<vector<string>> npc_text_;
	vector<vector<int>> npc_item_;
	void ReadFile(int);
public:
	NpcData();
	void LoadData();
	int GetRandomCode();
	string GetName(int);
	string GetRandomScript(int);
	int GetRandomItem(int);
};