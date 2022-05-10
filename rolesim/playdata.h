#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <filesystem>

using namespace std;

class PlayData
{
private:
	string name_;
	int level_;
	int health_;
	int mana_;
	int money_;
	vector<int> skill_;
	vector<int> item_;
	void ReadFile(string);
	void WriteFile(string);
	bool SelectData();
public:
	void NewData();
	void LoadData();
	void SaveData();
	void ShowData();
	void RemoveData();
};