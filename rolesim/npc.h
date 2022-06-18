#pragma once

#include <string>
#include <vector>

using namespace std;

class Npc
{
private:
	typedef vector<int> skill_list_t;
	typedef vector<int> item_list_t;
	typedef vector<string> script_list_t;
	string name_;
	script_list_t scripts_;
	skill_list_t skills_;
	item_list_t items_;
public:
	Npc(string, vector<string>, vector<int>, vector<int>);
	string getName() const;
	script_list_t getScript() const;
	skill_list_t getSkill() const;
	item_list_t getItem() const;
	vector<int> getReward() const;
};

