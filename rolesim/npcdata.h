#pragma once

#include "gamedata.h"
#include "npc.h"

using namespace std;

class NpcData : public GameData
{
private:
	vector<Npc> npcs_;
	void readFile(int);
public:
	NpcData();
	void loadData() override;
	void showData() const override;
	vector<Npc> &getNpc();
};