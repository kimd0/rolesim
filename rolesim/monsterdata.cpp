#include "monsterdata.h"

MonsterData::MonsterData()
{
	loadData();
}

void MonsterData::readFile(int code)
{
	ifstream read_file;

	read_file.open("monster\\" + to_string(code) + ".txt");
	if (read_file.is_open())
	{
		string read_line;
		vector<int> new_items;
		string name;
		string appearence;
		int level, health;

		getline(read_file, read_line); //name
		name = read_line;
		getline(read_file, read_line); //level
		level = stoi(read_line);
		getline(read_file, read_line); //health
		health = stoi(read_line);

		//monster drop table with '/'
		getline(read_file, read_line);
		stringstream item_stream(read_line);
		string item;
		while (getline(item_stream, item, '/'))
			new_items.push_back(stoi(item));

		while (!read_file.eof())
		{
			getline(read_file, read_line);
			appearence += read_line;
			appearence += "\n";
		}

		Monster new_monster(name, level, health, new_items, appearence);
		monsters_.push_back(new_monster);
	}
}

void MonsterData::loadData()
{
	int monster_number = 0;
	const filesystem::path monster_path("./monster");

	for (auto& i : filesystem::recursive_directory_iterator(monster_path))
		monster_number++;

	for (int i = 0; i < monster_number; ++i)
		readFile(i);
}

Monster MonsterData::getRandomMonster()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, monsters_.size() - 1);

	return monsters_[dist(gen)];
}