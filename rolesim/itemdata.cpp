#include "itemdata.h"

ItemData::ItemData()
{
	loadData();
	cout << "[Info] Item data loaded." << endl;
}

void ItemData::readFile(const string& file_name)
{
	ifstream read_file;
	read_file.open(file_name);
	if (read_file.is_open())
	{
		string read_line;
		while(getline(read_file, read_line))
		{
			stringstream sstream(read_line);
			vector<int> new_item;
			//item.txt: code/name/type/value
			//code
			getline(sstream, read_line, '/');
			new_item.push_back(stoi(read_line));
			//name
			getline(sstream, read_line, '/');
			item_name_.push_back(read_line);
			//type
			getline(sstream, read_line, '/');
			new_item.push_back(stoi(read_line));
			//value
			getline(sstream, read_line, '/');
			new_item.push_back(stoi(read_line));

			item_.push_back(new_item);
		}
	}
}

void ItemData::loadData()
{
	readFile("item\\item.txt");
	//check integrity by comparing item code and array index, size check
	for (vector<int>::size_type i = 0; i < item_.size(); ++i)
	{
		if (item_[i].size() != 3 || item_name_[i].empty())
			cout << "[Error] Please check item data integrity. Error item code " << i << endl;
		else if (i != item_[i][0])
		{
			cout << "[Error] Please check item data integrity." << endl;
			cout << "Wrong item code : " << item_[i][0] << "| name : " << item_name_[i] << endl;
		}
	}
}

void ItemData::showData() const
{
	cout << "Total " << item_.size() << " items loaded." << endl;
	for (vector<int>::size_type i = 0; i < item_.size(); i++)
		cout << "[" << item_[i][0] << "] " << item_name_[i] << " | type : " << item_[i][1] << " | value : " << item_[i][2] << endl;
}

string ItemData::getName(int code) const
{
	return item_name_[code];
}

vector<int> ItemData::getData(int code) const
{
	// return [code, type, value]
	// type 0 : health, 1: mana, 2: attack
	return item_[code];
}