#include "monster.h"

Monster::Monster(string name, int level, int health, vector<int> item, string appearence)
{
	name_ = move(name);
	level_ = move(level);
	health_ = move(health);
	items_ = move(item);
	appearence_ = move(appearence);
}

string Monster::getName() const
{
	return name_;
}

int Monster::getLevel() const
{
	return level_;
}

int Monster::getHealth() const
{
	return health_;
}

string Monster::getAppearence() const
{
	return appearence_;
}

void Monster::setDifficulty(int player_level)
{
	double new_level = (100.0 + level_) / 100 * player_level;
	level_ = static_cast<int>(round(new_level));
	health_ += level_ * 50;
}

vector<int> Monster::getReward()
{
	vector<int> rewards; //[money, item]
	rewards.push_back(level_ * 10);
	rewards.push_back(items_[level_ % items_.size()]);

	return rewards;
}

int Monster::actionAtk() const
{
	cout << "[Info] Monster's damage : " << level_ * 10 << endl;
	return -level_ * 10;
}

void Monster::actionDef(int value)
{
	cout << "[Info] Monster's health : " << health_ << " -> ";
	health_ = (health_ > value) ? health_ - value : 0;
	cout << health_ << endl;
}