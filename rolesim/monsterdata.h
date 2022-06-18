#pragma once

#include "gamedata.h"
#include "monster.h"

using namespace std;

class MonsterData : public GameData
{
private:
	typedef vector<Monster> monster_list_t;
	monster_list_t monsters_;
	string appearence;
	void readFile(int);
public:
	MonsterData();
	void loadData() override;
	void showData() const override;
	monster_list_t &getMonster();
};