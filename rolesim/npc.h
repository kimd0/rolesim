#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

class Npc
{
private:
	string name_;
	vector<string> scripts_;
	vector<int> items_;
	vector<int> skills_;
public:
	Npc(string, vector<string>, vector<int>, vector<int>);
	string getName();
	string getScript();
	vector<int> getReward();
	void getInfo();
};

