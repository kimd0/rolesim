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

class UserData
{
private:
	string name_;
	int level_;
	int health_;
	int mana_;
	int money_;
	vector<int> skill_;
	vector<int> item_;
	vector<string> user_list_;
	void ReadFile(string);
	void WriteFile(string);
	void GetUserList();
	void SelectData();
	bool CheckData(string);
	bool CheckUser(string);
public:
	UserData();
	void NewData();
	void LoadData();
	void SaveData();
	void ShowData(SkillData&, ItemData&) const;
	void RemoveData();
	void AddSkill(int);
	void AddItem(int);
};