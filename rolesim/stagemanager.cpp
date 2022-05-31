#include "stagemanager.h"

StageManager::StageManager(PlayData& play_data)
{
	play_data_ = play_data;
	npc_data_ = new NpcData();
	monster_data_ = new MonsterData();
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
		cout << endl;
		cout << "---------------------------------------------" << endl;
		cout << "[Info] An endless dungeon unfolds before your eyes." << endl;
		cout << "1) Move forward\t\t2) Inventory" << endl;
		cout << "3) Status\t\t4) Exit" << endl;
		cout << "---------------------------------------------" << endl;
		cout << "Input: ";
		fflush(stdin);
		cin >> input;
		if (input == 1)
		{
			system("cls");

			if (computeProb(70)) //for test. should be 70%
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
			system("cls");
			//item show / use
			play_data_.showInventory();
			cout << "[Tip] Input -1 to Cancel." << endl;
			cout << "---------------------------------------------" << endl;
			cout << "Select item : ";
			fflush(stdin);
			cin >> input;
			if (input != -1)
				play_data_.useItem(input);
		}
		else if (input == 3)
		{
			system("cls");
			play_data_.showInfo();
		}
		else if (input == 4)
		{
			system("cls");
			return false;
		}
		else
		{
			cout << "[Info] Please enter valid input." << endl;
		}
	}
	return true;
}

bool StageManager::monsterStage()
{
	int input;
	Monster new_monster = monster_data_->getRandomMonster();
	new_monster.setDifficulty(play_data_.getLevelInfo());

	system("cls");
	cout << "---------------------------------------------" << endl;
	cout << new_monster.getAppearence() << endl;
	cout << "[ Lvl. " << new_monster.getLevel() << " ] " << new_monster.getName() << endl;
	cout << "A monster appeared from the darkness." << endl;
	
	while (true)
	{
		cout << endl;
		cout << "---------------------------------------------" << endl;
		cout << "1) Fight    2) Run" << endl;
		cout << "---------------------------------------------" << endl;
		cout << "Input : ";
		fflush(stdin);
		cin >> input;

		if (input == 1)
		{
			break;
		}
		else if (input == 2)
		{
			if (computeProb(50))
			{
				cout << "[Info] Successfully escaped from the monster." << endl;
				break;
			}
			else
			{
				cout << "[Info] Failed to escape from the monster." << endl;
				//need to add disadvantage
				play_data_.changeHealth(-100);
				
			}
		}
		else
		{
			cout << "[Info] Please enter valid input." << endl;
		}
	}
	//need to implement combat here
	//player win / runaway (50%)) -> return true, lose -> return false.
	return true;
}

void StageManager::npcStage()
{
	Npc new_npc = npc_data_->getRandomNpc();
	vector<int> npc_reward = new_npc.getReward();

	//npc encounter
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


bool StageManager::computeProb(int percent)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dist(0, 99);

	if (dist(gen) < percent)
		return true;
	else
		return false;
}