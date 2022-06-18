#include "stagemanager.h"

StageManager::StageManager(DataManager& play_data)
{
	play_data_ = &play_data;
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
		cin >> input;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "[Info] Please enter valid input." << endl;
			continue;
		}

		if (input == 1)
		{
			system("cls");

			if (randomNumber() < 70) //for test. should be 70%
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
			play_data_->showInventory();
			cout << "[Tip] Input -1 to Cancel." << endl;
			cout << "---------------------------------------------" << endl;
			cout << "Select item : ";
			cin >> input;

			if (cin.fail())
			{
				cin.clear();
				cin.ignore(256, '\n');
				cout << "[Info] Please enter valid input." << endl;
				continue;
			}
			if (input != -1)
				play_data_->useItem(input);
		}
		else if (input == 3)
		{
			system("cls");
			play_data_->showInfo();
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
	int max_health;
	Monster new_monster = play_data_->getMonsterList()[randomNumber() % (int)play_data_->getMonsterList().size()];
	new_monster.setDifficulty(play_data_->getLevelInfo());
	max_health = new_monster.getHealth();

	system("cls");
	cout << "---------------------------------------------" << endl;
	cout << new_monster.getAppearence() << endl;
	cout << "[ Lvl. " << new_monster.getLevel() << " ] " << new_monster.getName() << endl;
	cout << "A monster appeared from the darkness." << endl;
	
	while (true)
	{
		cout << endl;
		cout << "---------------------------------------------" << endl;
		cout << "1) Fight\t2) Run" << endl;
		cout << "---------------------------------------------" << endl;
		cout << "Input : ";
		cin >> input;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "[Info] Please enter valid input." << endl;
			continue;
		}

		if (input == 1)
		{
			break;
		}
		else if (input == 2)
		{
			if (randomNumber() < 50)
			{
				cout << "[Info] Successfully escaped from the monster." << endl;
				return true;
			}
			else
			{
				cout << "[Info] Failed to escape from the monster." << endl;
				//need to add disadvantage
				if (play_data_->changeHealth(-50) <= 0)
				{
					cout << "[Info] You lost your mind and passed out." << endl;
					return false;
				}
				
			}
		}
		else
		{
			cout << "[Info] Please enter valid input." << endl;
		}
	}
	system("cls");
	while (true)
	{
		cout << "---------------------------------------------" << endl;
		cout << new_monster.getAppearence() << endl;
		cout << "[ LV. " << new_monster.getLevel() << " ] " << new_monster.getName() << endl;
		cout << "Health : " << new_monster.getHealth() << " / " << max_health << endl;
		cout << "---------------------------------------------" << endl;
		cout << "VS" << endl;
		play_data_->showCondition();
		cout << "---------------------------------------------" << endl;
		cout << "1) Use Skill\t2) Use Item" << endl;
		cout << "Select Input : ";
		cin >> input;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "[Info] Please enter valid input." << endl;
			continue;
		}

		if (input == 1)
		{
			play_data_->showSkill();
			cout << "Select skill : ";
			cin >> input;
			new_monster.actionDef(play_data_->useSkill(input));
		}
		else if (input == 2)
		{
			play_data_->showInventory();
			cout << "Select item : ";
			cin >> input;
			new_monster.actionDef(play_data_->useItem(input));
		}
		else
		{
			cout << "[Info] The turn is passed due to the wrong choice." << endl << endl;
		}

		if (new_monster.getHealth() <= 0)
		{
			vector<int> reward = new_monster.getReward();
			cout << "[Info] You win!" << endl;
			cout << "[Info] You gained " << reward[0] << " Gold and " << play_data_->getItemInfo(reward[1]) << endl;
			play_data_->gainMoney(reward[0]);
			play_data_->gainItem(reward[1]);
			play_data_->gainExperience((int)round(50.0 * new_monster.getLevel() / play_data_->getLevelInfo()));
			break;
		}

		cout << "[Info] Monster " << new_monster.getName() << " has attacked!" << endl;

		if(play_data_->changeHealth(new_monster.actionAtk()) <= 0)
		{
			cout << "[Info] You lost your mind and passed out." << endl;
			return false;
		}
	}
	//player win / runaway (50%)) -> return true, lose -> return false.
	return true;
}

void StageManager::npcStage()
{
	Npc new_npc = play_data_->getNpcList()[randomNumber() % (int)play_data_->getNpcList().size()];
	int reward;

	//npc encounter
	cout << "---------------------------------------------" << endl;
	cout << "[Info] A voice comes from somewhere..." << endl;
	cout << "[Info] " << new_npc.getName() << " : ";
	cout << new_npc.getScript()[randomNumber() % (int)new_npc.getScript().size()] << endl;

	if (randomNumber() < 80)
	{
		reward = new_npc.getItem()[randomNumber() % (int)new_npc.getItem().size()];
		cout << "[Info] " << new_npc.getName() << " gave you the item, ["
			<< play_data_->getItemInfo(reward) << "] and disappeared." << endl;
		play_data_->gainItem(reward);
	}
	else
	{
		reward = new_npc.getSkill()[randomNumber() % (int)new_npc.getSkill().size()];
		cout << "[Info] " << new_npc.getName() << " teached you the skill, ["
			<< play_data_->getSkillInfo(reward) << "] and disappeared." << endl;
		play_data_->gainSkill(reward);
	}
	cout << "---------------------------------------------" << endl;
}


int StageManager::randomNumber(int min, int max)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dist(min, max);

	return dist(gen);
}