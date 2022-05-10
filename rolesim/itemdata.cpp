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
			while (getline(sstream, item, '/'))
			{
				item_.push_back(item);
			}
		}
	}
}