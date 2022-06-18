#pragma once

#include "gamedata.h"

using namespace std;

class ItemData : public GameData
{
private:
	vector<vector<int>> item_;
	vector<string> item_name_;
	void readFile(const string&);
public:
	ItemData();
	void loadData() override;
	void showData() const override;
	string getName(int) const;
	vector<int> getData(int) const;
};