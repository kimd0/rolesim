#pragma once

#include "gamedata.h"
#include "monster.h"

using namespace std;

class MonsterData : public GameData
{
private:
	vector<Monster> monsters_;
	string appearence;
	void readFile(int);
public:
	MonsterData();
	void loadData() override;
	void showData() const override;
	vector<Monster> &getMonster();
};