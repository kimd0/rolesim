#pragma once

#include "gamedata.h"
#include "npc.h"

using namespace std;

class NpcData : public GameData
{
private:
	typedef vector<Npc> npc_list_t;
	npc_list_t npcs_;
	void readFile(int);
public:
	NpcData();
	void loadData() override;
	void showData() const override;
	npc_list_t &getNpc();
};