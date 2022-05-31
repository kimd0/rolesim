#include "npc.h"

Npc::Npc(string name, vector<string> scripts, vector<int> items, vector<int> skills)
{
	name_ = name;
	scripts_ = scripts;
	items_ = items;
	skills_ = skills;
}

string Npc::getName()
{
	return name_;
}

string Npc::getScript()
{
	srand((unsigned int)time(NULL));
	return scripts_[rand() % 3];
}

vector<int> Npc::getReward()
{
	vector<int> new_reward; //will be [type, code]. type = 0 -> item, 1 -> skill.

	srand((unsigned int)time(NULL));
	//give item : 80%
	if (rand() % 5 < 4)
	{
		new_reward.push_back(0);
		new_reward.push_back(items_[rand() % items_.size()]);
	}
	//give skill : 20%
	else
	{
		new_reward.push_back(1);
		new_reward.push_back(skills_[rand() % skills_.size()]);
	}
	return new_reward;
}