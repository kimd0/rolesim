#include "npcdata.h"

NpcData::NpcData()
{
	loadData();
}

void NpcData::readFile(int code)
{
	ifstream read_file;

	read_file.open("npc\\" + to_string(code) + ".txt");
	if (read_file.is_open())
	{
		vector<int> new_skills;
		vector<int> new_items;
		vector<string> new_scripts;
		string name;
		string item;
		string read_line;
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

void NpcData::loadData()
{
	int npc_number = 0;
	const filesystem::path npc_path("./npc");

	for (auto& i : filesystem::recursive_directory_iterator(npc_path))
		npc_number++;

	for (int i =0; i < npc_number; ++i)
		readFile(i);
}

Npc NpcData::getRandomNpc()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, npcs_.size() - 1);

	return npcs_[dist(gen)];
}