#pragma once

#include "gamedata.h"

using namespace std;

class SkillData : public GameData
{
private:
	vector<vector<int>> skill_;
	vector<string> skill_name_;
	void readFile(const string&);
public:
	SkillData();
	void loadData() override;
	void showData() const override;
	string getName(int) const;
	vector<int> getData(int) const;
};


