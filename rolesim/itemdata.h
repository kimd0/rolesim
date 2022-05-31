#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <filesystem>

using namespace std;

class ItemData
{
private:
	vector<vector<int>> item_;
	vector<string> item_name_;
	void readFile(string);
public:
	ItemData();
	void loadData();
	void showData();
	string getName(int);
};