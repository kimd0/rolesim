#include "npcdata.h"

NpcData::NpcData()
{
	loadData();
	cout << "[Info] Npc data loaded." << endl;
}

void NpcData::readFile(int code)
{
	ifstream read_file;

	read_file.open("npc\\" + to_string(code) + ".txt");
	if (read_file.is_open())
	{
		string read_line;
		vector<int> new_skills;
		vector<int> new_items;
		vector<string> new_scripts;
		string name;

		getline(read_file, read_line); //name
		name = read_line;
		getline(read_file, read_line); //script1
		new_scripts.push_back(read_line);
		getline(read_file, read_line); //script2
		new_scripts.push_back(read_line);
		getline(read_file, read_line); //script3
		new_scripts.push_back(read_line);

		//npc skill with '/'
		getline(read_file, read_line);
		stringstream skill_stream(read_line);
		string skill;
		while (getline(skill_stream, skill, '/'))
			new_skills.push_back(stoi(skill));

		//npc item with '/'
		getline(read_file, read_line);
		stringstream item_stream(read_line);
		string item;
		while (getline(item_stream, item, '/'))
			new_items.push_back(stoi(item));

		Npc new_npc(name, new_scripts, new_skills, new_items);
		npcs_.push_back(new_npc);
	}
}

void NpcData::loadData()
{
	int npc_number = 0;
	const filesystem::path npc_path("./npc");

	for (filesystem::recursive_directory_iterator next(npc_path), end; next != end; ++next)
		npc_number++;

	for (int i =0; i < npc_number; ++i)
		readFile(i);
}

void NpcData::showData() const
{
	cout << "------------------------------------------" << endl;
	cout << "Total " << npcs_.size() << " npcs loaded." << endl;
	cout << "------------------------------------------" << endl;
	for (vector<int>::size_type i = 0; i < npcs_.size(); i++)
	{
		cout << "[" << i << "] " << npcs_[i].getName() << " | items : ";
		for (vector<int>::size_type j = 0; j < npcs_[i].getItem().size(); j++)
			cout << npcs_[i].getItem()[j] << " ";
		cout << " | skills : ";
		for (vector<int>::size_type j = 0; j < npcs_[i].getSkill().size(); j++)
			cout << npcs_[i].getSkill()[j] << " ";
		cout << "\nscripts : ";
		for (vector<int>::size_type j = 0; j < npcs_[i].getScript().size(); j++)
			cout << npcs_[i].getScript()[j] << endl;
		cout << "------------------------------------------" << endl;
	}
}

NpcData::npc_list_t &NpcData::getNpc()
{
	return npcs_;
}