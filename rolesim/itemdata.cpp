#include "itemdata.h"

ItemData::ItemData()
{
	LoadData();
}

void ItemData::ReadFile(string file_name)
{
	ifstream read_file;
	string read_line;
	read_file.open(file_name);
	if (read_file.is_open())
	{
		while(getline(read_file, read_line))
		{
			stringstream sstream(read_line);
			string item;
			vector<int> new_item;
			//item.txt: code/name/type/value
			//code
			getline(sstream, item, '/');
			new_item.push_back(stoi(item));
			//name
			getline(sstream, item, '/');
			item_name_.push_back(item);
			//type
			getline(sstream, item, '/');
			new_item.push_back(stoi(item));
			//value
			getline(sstream, item, '/');
			new_item.push_back(stoi(item));

			item_.push_back(new_item);
		}
	}
}

void ItemData::LoadData()
{
	ReadFile("item\\item.txt");
	//check integrity by comparing item code and array index
	for (int i = 0; i < item_.size(); i++)
	{
		if (i != item_[i][0])
		{
			cout << "[Error] Please check item data integrity." << endl;
			cout << "Wrong item code : " << item_[i][0] << "| name : " << item_name_[i] << endl;
		}
	}

	/*
	//show loaded data
	cout << "Loaded item data" << endl;
	for (int i = 0; i < item_.size(); i++)
	{
		cout << "[" << item_[i][0] << "] " << itemname_[i] << " | type : " << item_[i][1] << " | value : " << item_[i][2] << endl;
	}
	*/
}

string ItemData::GetName(int code)
{
	string item_name;
	item_name = item_name_[code];
	return item_name;
}