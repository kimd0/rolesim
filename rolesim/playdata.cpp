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

void PlayData::showInventory() const
{
	user_data_->showData(*item_data_);
}

void PlayData::showSkill() const
{
	user_data_->showData(*skill_data_);
}

void PlayData::showCondition() const
{
	user_data_->showCondition();
}

void PlayData::gainItem(int code) const
{
	user_data_->addItem(code);
}

void PlayData::gainSkill(int code) const
{
	user_data_->addSkill(code);
}

void PlayData::gainExperience(int value) const
{
	user_data_->addExperience(value);
}

void PlayData::gainMoney(int value) const
{
	user_data_->addMoney(value);
}

int PlayData::changeHealth(int value) const
{
	return user_data_->addHealth(value);
}

int PlayData::changeMana(int value) const
{
	return user_data_->addMana(value);
}

int PlayData::useItem(int index) const
{
	return user_data_->useItem(*item_data_, index);
}

int PlayData::useSkill(int index) const
{
	return user_data_->useSkill(*skill_data_, index);
}

string PlayData::getItemInfo(int code) const
{
	return item_data_->getName(code);
}

string PlayData::getSkillInfo(int code) const
{
	return skill_data_->getName(code);
}

int PlayData::getLevelInfo() const
{
	return user_data_->getLevel();
}
