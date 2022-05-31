#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <filesystem>

using namespace std;

class SkillData
{
private:
	vector<vector<int>> skill_;
	vector<string> skill_name_;
	void ReadFile(string);
public:
	SkillData();
	virtual void LoadData();
	string GetName(int);
};


