#include "datamanager.h"

DataManager::DataManager()
{
	loadData();
	cout << "[Info] Play data loaded." << endl;
}

DataManager::~DataManager()
{
	delete user_data_;
	delete item_data_;
	delete skill_data_;
	delete npc_data_;
	delete monster_data_;
}

void DataManager::loadData()
{
	user_data_ = new UserData();
	item_data_ = new ItemData();
	skill_data_ = new SkillData();
	npc_data_ = new NpcData();
	monster_data_ = new MonsterData();
}

void DataManager::newGame()
{
	user_ = user_data_->newData();
}

void DataManager::loadGame()
{
	user_ = user_data_->loadData();
}

void DataManager::saveGame()
{
	user_data_->saveData(user_);
}

void DataManager::showData() const
{
	item_data_->showData();
	skill_data_->showData();
	npc_data_->showData();
	monster_data_->showData();
}

void DataManager::showInfo() const
{
	user_.showStatus(*skill_data_, *item_data_);
}

void DataManager::showInventory() const
{
	user_.showItem(*item_data_);
}

void DataManager::showSkill() const
{
	user_.showSkill(*skill_data_);
}

void DataManager::showCondition() const
{
	user_.showCondition();
}

void DataManager::gainItem(int code)
{
	user_.addItem(code);
}

void DataManager::gainSkill(int code)
{
	user_.addSkill(code);
}

void DataManager::gainExperience(int value)
{
	user_.addExperience(value);
}

void DataManager::gainMoney(int value)
{
	user_.addMoney(value);
}

int DataManager::changeHealth(int value)
{
	return user_.addHealth(value);
}

int DataManager::changeMana(int value)
{
	return user_.addMana(value);
}

int DataManager::useItem(int index)
{
	return user_.useItem(*item_data_, index);
}

int DataManager::useSkill(int index)
{
	return user_.useSkill(*skill_data_, index);
}

string DataManager::getItemInfo(int code) const
{
	return item_data_->getName(code);
}

string DataManager::getSkillInfo(int code) const
{
	return skill_data_->getName(code);
}

int DataManager::getLevelInfo() const
{
	return user_.getLevel();
}

Monster DataManager::getRandomMonster() const
{
	vector<Monster> monsters = monster_data_->getMonster();
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, monsters.size() - 1);

	return monsters[dist(gen)];
}

Npc DataManager::getRandomNpc() const
{
	vector<Npc> npcs = npc_data_->getNpc();
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, npcs.size() - 1);

	return npcs[dist(gen)];
}