#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <filesystem>

using namespace std;

class SkillData
{
private:
	vector<vector<int>> skill_;
	vector<string> skill_name_;
	void readFile(const string&);
public:
	SkillData();
	void loadData();
	void showData() const;
	string getName(int) const;
	vector<int> getData(int) const;
};


