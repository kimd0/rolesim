#include "npcdata.h"

NpcData::NpcData()
{
	LoadData();
}

void NpcData::ReadFile(int code)
{
	ifstream read_file;
	string read_line;
	string text, item;
	vector<string> new_text;
	vector<int> new_item;
	read_file.open("npc\\" + to_string(code) + ".txt");
	if (read_file.is_open())
	{
		getline(read_file, read_line); //name
		new_text.push_back(read_line);
		getline(read_file, read_line); //script1
		new_text.push_back(read_line);
		getline(read_file, read_line); //script2
		new_text.push_back(read_line);
		getline(read_file, read_line); //script3
		new_text.push_back(read_line);

		//npc item with '/'
		getline(read_file, read_line);
		stringstream istream(read_line);
		while (getline(istream, item, '/'))
			new_item.push_back(stoi(item));
		npc_text_.push_back(new_text);
		npc_item_.push_back(new_item);
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
	
	/*
	//show loaded data
	cout << "Loaded npc data :" << endl;
	for (int i = 0; i < npc_text_.size(); i++)
	{
		cout << "[" << i << "] " << GetName(i) << " says : " << GetScript(i) << endl;
		for (int j = 1; j < npc_text_[i].size(); j++)
			cout << j << ". " << npc_text_[i][j] << endl;
		cout << "Items : ";
		for (int j = 0; j < npc_item_[i].size(); j++)
			cout << npc_item_[i][j] << " ";
		cout << endl;
	}
	*/
}

string NpcData::GetName(int code)
{
	string npc_name;
	npc_name = npc_text_[code][0];
	return npc_name;
}

string NpcData::GetScript(int code)
{
	string npc_script;
	srand((unsigned int)time(NULL));
	npc_script = npc_text_[code][rand()%3 + 1];
	return npc_script;
}