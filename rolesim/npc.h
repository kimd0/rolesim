#pragma once

#include <string>
#include <vector>
#include <random>

using namespace std;

class Npc
{
private:
	string name_;
	vector<string> scripts_;
	vector<int> skills_;
	vector<int> items_;
public:
	Npc(string, vector<string>, vector<int>, vector<int>);
	string getName() const;
	string getScript() const;
	vector<int> getReward() const;
};

