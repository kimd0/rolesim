#include "monster.h"

Monster::Monster(string name, int level, int health, vector<int> item, string appearence)
{
	name_ = move(name);
	level_ = move(level);
	health_ = move(health);
	items_ = move(item);
	appearence_ = move(appearence);
}

string Monster::getName()
{
	return name_;
}

int Monster::getLevel()
{
	return level_;
}

int Monster::getHealth()
{
	return health_;
}

string Monster::getAppearence()
{
	return appearence_;
}

void Monster::setDifficulty(int player_level)
{
	double new_level = (100.0 + level_) / 100 * player_level;
	level_ = round(new_level);
	health_ += level_ * 100;
}

vector<int> Monster::getReward()
{
	vector<int> rewards; //[money, item]
	rewards.push_back(level_ * 10);
	rewards.push_back(items_[level_ % items_.size()]);

	return rewards;
}