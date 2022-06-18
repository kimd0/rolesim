#pragma once

#include <iostream>
#include "playdata.h"
#include "stagemanager.h"

using namespace std;

class main
{
public:
	int main();
	PlayData* play_data;
	StageManager* stage_manager;
};