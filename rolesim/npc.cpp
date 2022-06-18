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

Npc::script_list_t Npc::getScript() const
{
	return scripts_;
}

Npc::skill_list_t Npc::getSkill() const
{
	return skills_;
}

Npc::item_list_t Npc::getItem() const
{
	return items_;
}
