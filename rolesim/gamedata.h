#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <random>

class GameData
{
public:
	virtual void loadData() = 0;
	virtual void showData() const = 0;
};