#include "userdata.h"

UserData::UserData()
{
	getUserList();
}

User UserData::readFile(string name)
{
	string file_name = "user\\" + name + ".txt";
	ifstream read_file;
	read_file.open(file_name);
	if (read_file.is_open())
	{
		string read_line;
		string name;
		int level, exp, health, mana, money;
		vector<int> skill, item;
		getline(read_file, name); //name

		getline(read_file, read_line); //level
		level = stoi(read_line);

		getline(read_file, read_line); //exp
		exp = stoi(read_line);

		getline(read_file, read_line); //hp
		health = stoi(read_line);

		getline(read_file, read_line); //mp
		mana = stoi(read_line);

		getline(read_file, read_line); //money
		money = stoi(read_line);

		//user skill with slash
		getline(read_file, read_line);
		stringstream skill_stream(read_line);
		string new_skill;
		while (getline(skill_stream, new_skill, '/'))
		{
			skill.push_back(stoi(new_skill));
		}

		//user item with slash
		getline(read_file, read_line);
		stringstream item_stream(read_line);
		string new_item;
		while (getline(item_stream, new_item, '/'))
		{
			item.push_back(stoi(new_item));
		}
		return User(name, level, exp, health, mana, money, skill, item);
	}

	cout << "[Error] Can't open save file. Loaded basic data instead." << endl;
	return User(name, 1, 0, 100, 50, 0, { 0 }, { 0 });
}

void UserData::writeFile(User &user) const
{
	cout << "[Info] Writing save file..." << endl;
	string file_name = "user\\" + user.getName() + ".txt";
	ofstream write_file(file_name);

	if (write_file.is_open()) {
		string temp_string;
		write_file << user.getName() << endl;
		write_file << user.getLevel() << endl;
		write_file << user.getExperience() << endl;
		write_file << user.getHealth() << endl;
		write_file << user.getMana() << endl;
		write_file << user.getMoney() << endl;

		for (int i : user.getSkill())
			temp_string += to_string(i) + "/";
		if(!temp_string.empty()) temp_string.pop_back();
		temp_string += "\n";

		for (int i : user.getItem())
			temp_string += to_string(i) + "/";
		if (!temp_string.empty()) temp_string.pop_back();

		write_file << temp_string;
		write_file.close();
	}
}

void UserData::getUserList()
{
	const filesystem::path user_path("./user");
	for (auto& i : filesystem::recursive_directory_iterator(user_path))
	{
		string user = i.path().filename().string();
		user = user.substr(0, user.length() - 4);
		user_list_.push_back(user);
	}
}

string UserData::selectData()
{
	string user_name;
	cout << "-----------------------------" << endl;
	cout << "Saved Data" << endl;
	cout << "-----------------------------" << endl;
	for (auto& i : user_list_)
		cout << i << endl;
	cout << "-----------------------------" << endl;

	while (true)
	{
		fflush(stdin);
		cout << "Input user name :";
		cin >> user_name;

		if (checkUser(user_name))
		{
			cout << "[Success] Valid data name." << endl;
			return user_name;
		}
		else
			cout << "[Error] Please input valid data name." << endl;
	}
}

bool UserData::checkData(string user) const
{
	const filesystem::path user_data("./user/" + user + ".txt");
	if (filesystem::exists(user_data))
		return true;
	else
		return false;
}

bool UserData::checkUser(string user)
{
	if (find(user_list_.begin(), user_list_.end(), user) != user_list_.end())
		return true;
	else
		return false;
}

User UserData::newData()
{
	string user_name;
	while (true)
	{
		fflush(stdin);
		cout << "Please input your name : ";
		cin >> user_name;

		if (checkUser(user_name))
			cout << "[Error] User name already exists." << endl;
		else
			break;
	}
	User user(user_name, 1, 0, 100, 50, 0, { 0 }, { 0 });
	saveData(user);

	return user;
}

User UserData::loadData()
{
	return readFile(selectData());
}

void UserData::saveData(User &user)
{
	cout << "[Info] Saving data..." << endl;
	writeFile(user);
}