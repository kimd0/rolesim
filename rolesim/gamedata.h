#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <filesystem>

class GameData
{
public:
	virtual ~GameData();
	virtual void loadData() = 0;
	virtual void showData() const = 0;
};