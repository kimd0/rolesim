#pragma once

#include <string>
#include <vector>
#include <filesystem>
#include "itemdata.h"
#include "skilldata.h"

using namespace std;

class UserData
{
private:
	string name_;
	int level_;
	int health_;
	int mana_;
	int money_;
	vector<int> skill_;
	vector<int> item_;
	vector<string> user_list_;
	void readFile(string);
	void writeFile(string) const;
	void getUserList();
	void selectData();
	bool checkData(string) const;
	bool checkUser(string);
public:
	UserData();
	void newData();
	void loadData();
	void saveData() const;
	void showData(ItemData&) const;
	void showData(SkillData&) const;
	void showData(SkillData&, ItemData&) const;
	void removeData();
	void addSkill(int);
	void addItem(int);
	int useItem(ItemData&, int);
	void useSkill(SkillData&, int);
	void addHealth(int);
	void addMana(int);
	void addMoney(int);
	int getLevel();
};