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
	vector<string> item_;
	void ReadFile(string);
public:
	void LoadData();
	string GetData(int);
};