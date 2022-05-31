#include "npc.h"

Npc::Npc(string name, vector<string> scripts, vector<int> skills, vector<int> items)
{
	name_ = move(name);
	scripts_ = move(scripts);
	skills_ = move(skills);
	items_ = move(items);
}

string Npc::getName() const
{
	return name_;
}

string Npc::getScript() const
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, 2);
	return scripts_[dist(gen)];
}

vector<int> Npc::getReward() const
{
	vector<int> new_reward; //will be [type, code]. type = 0 -> item, 1 -> skill.

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, 99);
	int random_number = dist(gen);

	//give item : 80%
	if (random_number < 80)
	{
		new_reward.push_back(0);
		new_reward.push_back(items_[random_number % items_.size()]);
	}
	//give skill : 20%
	else
	{
		new_reward.push_back(1);
		new_reward.push_back(skills_[random_number % skills_.size()]);
	}
	return new_reward;
}
