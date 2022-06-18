#pragma once

#include "gamedata.h"

using namespace std;

class SkillData : public GameData
{
private:
	typedef vector<int> skill_info_t;
	vector<skill_info_t> skill_;
	vector<string> skill_name_;
	void readFile(const string&);
public:
	SkillData();
	void loadData() override;
	void showData() const override;
	string getName(int) const;
	skill_info_t getData(int) const;
};


