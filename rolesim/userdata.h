#pragma once

#include <string>
#include <vector>
#include <filesystem>
#include "itemdata.h"
#include "skilldata.h"
#include "user.h"

using namespace std;

class UserData
{
private:
	vector<string> user_list_;
	User readFile(string);
	void writeFile(User &) const;
	void getUserList();
	string selectData();
	bool checkData(string) const;
	bool checkUser(string);
public:
	UserData();
	User newData();
	User loadData();
	void saveData(User &);
};