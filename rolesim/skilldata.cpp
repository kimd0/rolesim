#include "skilldata.h"

SkillData::SkillData()
{
	LoadData();
}

void SkillData::ReadFile(string file_name)
{
	ifstream read_file;
	string read_line;
	read_file.open(file_name);
	if (read_file.is_open())
	{
		while (getline(read_file, read_line))
		{
			stringstream sstream(read_line);
			string skill;
			vector<int> new_skill;
			//skill.txt: code/name/type/value/cost
			//code
			getline(sstream, skill, '/');
			new_skill.push_back(stoi(skill));
			//name
			getline(sstream, skill, '/');
			skill_name_.push_back(skill);
			//type
			getline(sstream, skill, '/');
			new_skill.push_back(stoi(skill));
			//value
			getline(sstream, skill, '/');
			new_skill.push_back(stoi(skill));
			//cost
			getline(sstream, skill, '/');
			new_skill.push_back(stoi(skill));

			skill_.push_back(new_skill);
		}
	}
}

void SkillData::LoadData()
{
	ReadFile("skill\\skill.txt");
	for (int i = 0; i < skill_.size(); i++)
	{
		if (skill_[i].size() != 4 || skill_name_[i].empty())
			cout << "[Error] Please check skill data integrity. Error skill code " << i << endl;
		else if (i != skill_[i][0])
		{
			cout << "[Error] Please check skill data integrity." << endl;
			cout << "Wrong skill code : " << skill_[i][0] << "| name : " << skill_name_[i] << endl;
		}
	}

	/*
	//show loaded data
	cout << "Loaded skill data" << endl;
	for (int i = 0; i < skill_.size(); i++)
	{
		cout << "[" << skill_[i][0] << "] " << skill_name_[i] << " | type : " << skill_[i][1] << " | value : " << skill_[i][2] << skill_[i][1] << " | cost : " << skill_[i][3] << endl;
	}
	*/
}

string SkillData::GetName(int code)
{
	string skill_name;
	skill_name = skill_name_[code];
	return skill_name;
}
