#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <filesystem>
#include "itemdata.h"
#include "skilldata.h"

using namespace std;

class PlayData
{
private:
	string name_;
	int level_;
	int health_;
	int mana_;
	int money_;
	vector<int> skill_;
	vector<int> item_;
	vector<string> player_list_;
	void ReadFile(string);
	void WriteFile(string);
	void GetPlayerList();
	void SelectData();
	bool CheckData(string);
	bool CheckPlayer(string);
public:
	PlayData();
	void NewData();
	void LoadData();
	void SaveData();
	void ShowData(SkillData&, ItemData&);
	void RemoveData();
	void AddSkill(int);
	void AddItem(int);
};