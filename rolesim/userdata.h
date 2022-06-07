#pragma once

#include <string>
#include <vector>
#include <filesystem>
#include "user.h"

using namespace std;

class UserData
{
private:
	vector<string> user_list_;
	User readFile(const string&);
	void writeFile(const User&);
	void getUserList();
	string selectData();
	bool checkData(const string&) const;
	bool checkUser(const string&) const;
public:
	UserData();
	User newData();
	User loadData();
	void saveData(const User &);
};