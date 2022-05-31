#include "npcdata.h"

NpcData::NpcData()
{
	LoadData();
}

void NpcData::ReadFile(int code)
{
	ifstream read_file;
	string read_line;
	string name, item;
	vector<string> new_scripts;
	vector<int> new_items;
	vector<int> new_skills;

	read_file.open("npc\\" + to_string(code) + ".txt");
	if (read_file.is_open())
	{
		getline(read_file, read_line); //name
		name = read_line;
		getline(read_file, read_line); //script1
		new_scripts.push_back(read_line);
		getline(read_file, read_line); //script2
		new_scripts.push_back(read_line);
		getline(read_file, read_line); //script3
		new_scripts.push_back(read_line);

		//npc item with '/'
		getline(read_file, read_line);
		stringstream item_stream(read_line);
		while (getline(item_stream, item, '/'))
			new_items.push_back(stoi(item));

		//npc skill with '/'
		getline(read_file, read_line);
		stringstream skill_stream(read_line);
		while (getline(skill_stream, item, '/'))
			new_skills.push_back(stoi(item));

		Npc new_npc(name, new_scripts, new_items, new_skills);
		npcs_.push_back(new_npc);
	}
}

void NpcData::LoadData()
{
	int npc_number = 0;
	filesystem::path p("./npc");

	for (auto& p : filesystem::recursive_directory_iterator(p))
		npc_number++;

	for (int i =0; i < npc_number; ++i)
		ReadFile(i);
}

Npc NpcData::GetRandomNpc()
{
	srand((unsigned int)time(NULL));
	return npcs_[rand() % npcs_.size()];
}