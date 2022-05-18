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
			//skill.txt: code/name/type/value/usedmp
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
			//usedmp
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
		if (i != skill_[i][0])
		{
			cout << "[Error] Please check skill data integrity." << endl;
			cout << "Wrong skill code : " << skill_[i][0] << "| name : " << skill_name_[i] << endl;
		}
	}
}

	string SkillData::GetName(int code)
	{
		string skill_name;
		skill_name = skill_name_[code];
		return skill_name;
	}
