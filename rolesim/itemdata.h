#pragma once

#include "gamedata.h"

using namespace std;

class ItemData : public GameData
{
private:
	typedef vector<int> item_info_t;
	vector<item_info_t> item_;
	vector<string> item_name_;
	void readFile(const string&);
public:
	ItemData();
	void loadData() override;
	void showData() const override;
	string getName(int) const;
	item_info_t getData(int) const;
};