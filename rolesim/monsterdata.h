#pragma once

#include <vector>
#include <fstream>
#include <iostream>
#include <filesystem>
#include "monster.h"

using namespace std;

class MonsterData
{
private:
	vector<Monster> monsters_;
	string appearence;
	void readFile(int);
public:
	MonsterData();
	void loadData();
	Monster getRandomMonster();
};