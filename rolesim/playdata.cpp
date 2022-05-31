#include "playdata.h"

PlayData::PlayData()
{
	loadData();
}

PlayData::~PlayData()
{
	delete user_data_;
	delete item_data_;
	delete skill_data_;
}

void PlayData::loadData()
{
	user_data_ = new UserData();
	item_data_ = new ItemData();
	skill_data_ = new SkillData();
}

void PlayData::newGame() const
{
	user_data_->newData();
}

void PlayData::loadGame() const
{
	user_data_->loadData();
}

void PlayData::saveGame() const
{
	user_data_->saveData();
}

void PlayData::showInfo() const
{
	user_data_->showData(*skill_data_, *item_data_);
}

void PlayData::gainItem(int code) const
{
	user_data_->addItem(code);
}

void PlayData::gainSkill(int code) const
{
	user_data_->addSkill(code);
}

string PlayData::getItemInfo(int code) const
{
	return item_data_->getName(code);
}

string PlayData::getSkillInfo(int code) const
{
	return skill_data_->getName(code);
}
