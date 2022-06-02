#include "playdata.h"

PlayData::PlayData()
{
	loadData();
	cout << "[Info] Play data loaded." << endl;
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

void PlayData::newGame()
{
	user_ = user_data_->newData();
}

void PlayData::loadGame()
{
	user_ = user_data_->loadData();
}

void PlayData::saveGame()
{
	user_data_->saveData(user_);
}

void PlayData::showInfo()
{
	user_.showStatus(*skill_data_, *item_data_);
}

void PlayData::showInventory()
{
	user_.showItem(*item_data_);
}

void PlayData::showSkill()
{
	user_.showSkill(*skill_data_);
}

void PlayData::showCondition()
{
	user_.showCondition();
}

void PlayData::gainItem(int code)
{
	user_.addItem(code);
}

void PlayData::gainSkill(int code)
{
	user_.addSkill(code);
}

void PlayData::gainExperience(int value)
{
	user_.addExperience(value);
}

void PlayData::gainMoney(int value)
{
	user_.addMoney(value);
}

int PlayData::changeHealth(int value)
{
	return user_.addHealth(value);
}

int PlayData::changeMana(int value)
{
	return user_.addMana(value);
}

int PlayData::useItem(int index)
{
	return user_.useItem(*item_data_, index);
}

int PlayData::useSkill(int index)
{
	return user_.useSkill(*skill_data_, index);
}

string PlayData::getItemInfo(int code)
{
	return item_data_->getName(code);
}

string PlayData::getSkillInfo(int code)
{
	return skill_data_->getName(code);
}

int PlayData::getLevelInfo()
{
	return user_.getLevel();
}
