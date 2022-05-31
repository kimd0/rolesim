#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
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
	void writeFile(string);
	void getUserList();
	void selectData();
	bool checkData(string);
	bool checkUser(string);
public:
	UserData();
	void newData();
	void loadData();
	void saveData();
	void showData(SkillData&, ItemData&) const;
	void removeData();
	void addSkill(int);
	void addItem(int);
	void addMoney(int);
};