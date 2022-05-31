#include "stagemanager.h"

StageManager::StageManager(PlayData& play_data)
{
	play_data_ = play_data;
	npc_data_ = new NpcData();
}

StageManager::~StageManager()
{
	delete npc_data_;
}

bool StageManager::newStage()
{
	int input;

	while (true)
	{
		system("cls");
		cout << endl;
		cout << "---------------------------------------------" << endl;
		cout << "[Info] An endless dungeon unfolds before your eyes." << endl;
		cout << "1) Go\t2) Stop\t3) Status" << endl;
		cout << "---------------------------------------------" << endl;
		cout << "Input: ";
		cin >> input;
		if (input == 1)
		{
			//monster 70%, npc 30%
			srand((unsigned int)time(NULL));
			if (rand() % 100 < 0) //for test. should be "rand() % 100 < 70"
			{
				if (monsterStage())
					break;
				else
					return false;
			}
			else
			{
				npcStage();
				break;
			}
		}
		else if (input == 2)
		{
			return false;
		}
		else if (input == 3)
		{
			system("cls");
			play_data_.showInfo();
		}
		else
		{
			cout << "[Info] Please enter valid input." << endl;
			fflush(stdin);
		}
	}
	return true;
}

bool StageManager::monsterStage()
{
	int input;

	//monster encounter
	system("cls");
	cout << "1) Fight\t2) Run" << endl;
	cin >> input;

	//player win -> return true, lose -> return false.
	return true;
}

void StageManager::npcStage()
{
	Npc new_npc = npc_data_->getRandomNpc();
	vector<int> npc_reward = new_npc.getReward();

	//npc encounter
	system("cls");
	cout << "---------------------------------------------" << endl;
	cout << "[Info] A voice comes from somewhere..." << endl;
	cout << "[Info] " << new_npc.getName() << " : " << new_npc.getScript() << endl;

	if (npc_reward[0] == 0)
	{
		cout << "[Info] " << new_npc.getName() << " gave you the item, ["
			<< play_data_.getItemInfo(npc_reward[1]) << "] and disappeared." << endl;
		play_data_.gainItem(npc_reward[1]);
	}
	else
	{
		cout << "[Info] " << new_npc.getName() << " teached you the skill, ["
			<< play_data_.getSkillInfo(npc_reward[1]) << "] and disappeared." << endl;
		play_data_.gainSkill(npc_reward[1]);
	}
	cout << "---------------------------------------------" << endl;
}