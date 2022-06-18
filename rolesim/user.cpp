#include "user.h"

User::User()
{

}

User::User(string name, int level, int experience, int health, int mana, int money, vector<int> skill, vector<int> item)
{
	name_ = move(name);
	level_ = level;
	experience_ = experience;
	health_ = health;
	current_health_ = health_;
	mana_ = mana;
	current_mana_ = mana_;
	money_ = money;
	skill_ = move(skill);
	item_ = move(item);
}

void User::showCondition() const
{
	cout << "---------------------------------------------" << endl;
	cout << "[LV. " << level_ << " (" << experience_ << "%)] " << name_ << endl;
	cout << "[Health] " << current_health_ << "/" << health_ << " | ";
	cout << "[Mana] " << current_mana_ << "/" << mana_ << endl;
	cout << "---------------------------------------------" << endl;
}

void User::showItem(const ItemData& item_data) const
{
	cout << "---------------------------------------------" << endl;
	cout << "\t[Inventory]" << endl;
	cout << "---------------------------------------------" << endl;
	for (vector<int>::size_type i = 0; i < item_.size(); i++)
	{
		vector<int> new_item = item_data.getData(item_[i]);
		cout << "[ " << i << " ] " << item_data.getName(item_[i]) << " | Effect : ";
		if (new_item[1] == 0)
			cout << "Health +";
		else if (new_item[1] == 1)
			cout << "Mana +";
		else if (new_item[1] == 2)
			cout << "Give damage ";
		cout << new_item[2] << endl;
	}
	cout << "---------------------------------------------" << endl;
}

void User::showSkill(const SkillData& skill_data) const
{
	cout << "---------------------------------------------" << endl;
	cout << "\t[Skills]" << endl;
	cout << "---------------------------------------------" << endl;
	for (vector<int>::size_type i = 0; i < skill_.size(); ++i)
	{
		vector<int> new_skill = skill_data.getData(skill_[i]);
		cout << "[ " << i << " ] " << skill_data.getName(skill_[i]) << " | Type : ";
		if (new_skill[1] == 0)
			cout << "Normal";
		else if (new_skill[1] == 1)
			cout << "Fire";
		else if (new_skill[1] == 2)
			cout << "Water";
		else if (new_skill[1] == 3)
			cout << "Earth";
		else if (new_skill[1] == 4)
			cout << "Wind";
		cout << " | Damage : " << new_skill[2] * level_ * 50 << " | Cost : " << new_skill[3] << endl;
	}
	cout << "---------------------------------------------" << endl;
}

void User::showStatus(const SkillData& skill_data, const ItemData& item_data) const
{
	showCondition();
	showSkill(skill_data);
	showItem(item_data);
}

void User::addSkill(int code)
{
	if (find(skill_.begin(), skill_.end(), code) == skill_.end())
	{
		skill_.push_back(code);
		sort(skill_.begin(), skill_.end());
	}
	else
	{
		cout << "[Info] You already have the skill." << endl;
	}
}

void User::addItem(int code)
{
	item_.push_back(code);
	sort(item_.begin(), item_.end());
}

int User::useItem(ItemData& item_data, int index)
{
	if (static_cast<int>(item_.size()) <= index)
	{
		cout << "[Info] Can't use that item. (Out of range)" << endl;
		return 0;
	}

	vector<int> item_effect = item_data.getData(item_[index]);
	item_.erase(item_.begin() + index);

	cout << "[Info] " << item_data.getName(item_effect[0]) << " used." << endl;
	if (item_effect[1] == 0)//health
	{
		cout << "[Info] Recovered health +" << item_effect[2] << endl;
		addHealth(item_effect[2]);
		return 0;
	}
	else if (item_effect[1] == 1)//mana
	{
		cout << "[Info] Recovered Mana +" << item_effect[2] << endl;
		addMana(item_effect[2]);
		return 0;
	}
	else//granade.
	{
		cout << "BOOM!" << endl;
		return item_effect[2];
	}
}

int User::useSkill(SkillData& skill_data, int index)
{
	if (static_cast<int>(skill_.size()) <= index)
	{
		cout << "[Info] Can't use that skill. (Out of range)" << endl;
		return 0;
	}

	vector<int> skill_effect = skill_data.getData(skill_[index]);

	if (mana_ > skill_effect[3])
	{
		cout << "[Info] Skill - [" << skill_data.getName(skill_effect[0]) << "]" << endl;
		addMana(-skill_effect[3]);
		return level_ * skill_effect[2] * 50;
	}
	else
	{
		cout << "[Info] Skill execution failed due to lack of mana." << endl;
		return 0;
	}
}

int User::addExperience(int value)
{
	cout << "[Info] EXP " << experience_ << "% -> ";
	experience_ += value;
	
	if (experience_ >= 100)
	{
		experience_ = 0;
		cout << "100%" << endl;
		levelUp();
	}
	else
	{
		cout << experience_ << "%" << endl;
	}
	return experience_;
}

void User::levelUp()
{
	cout << "[Info] Congratulations! Level UP!" << endl;
	cout << "[Info] LV." << level_;
	level_ += 1;
	cout << " -> LV." << level_ << endl;
	cout << "[Info] Health " << health_ << " / Mana " << mana_;
	health_ += level_ * 10;
	mana_ += level_ * 5;
	cout << " -> Health " << health_ << " / Mana " << mana_ << endl;
}

int User::addHealth(int value)
{
	cout << "[Info] Health " << current_health_ << "/" << health_;
	current_health_ += value;
	if (current_health_ < 0)
		current_health_ = 0;
	else if (current_health_ > health_)
		current_health_ = health_;
	cout << " -> " << current_health_ << "/" << health_ << endl;
	return current_health_;
}

int User::addMana(int value)
{
	cout << "[Info] Mana " << current_mana_ << "/" << mana_;
	current_mana_ += value;
	if (current_mana_ < 0)
		current_mana_ = 0;
	else if (current_mana_ > mana_)
		current_mana_ = mana_;
	cout << " -> " << current_mana_ << "/" << mana_ << endl;
	return current_mana_;
}

void User::addMoney(const int value)
{
	money_ += value;
}

string User::getName() const
{
	return name_;
}

int User::getLevel() const
{
	return level_;
}

int User::getExperience() const
{
	return experience_;
}

int User::getHealth() const
{
	return health_;
}

int User::getMana() const
{
	return mana_;
}

int User::getMoney() const
{
	return money_;
}

vector<int> User::getSkill() const
{
	return skill_;
}

vector<int> User::getItem() const
{
	return item_;
}
