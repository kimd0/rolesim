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
	vector<string> itemname_;
	void ReadFile(string);
public:
	ItemData();
	void LoadData();
	string GetName(int);
};