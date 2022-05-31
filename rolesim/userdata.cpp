#include "userdata.h"

UserData::UserData()
{
	name_ = "";
	level_ = 1;
	health_ = 100;
	mana_ = 50;
	money_ = 1000;
	skill_ = {};
	item_ = {};
	getUserList();
}

void UserData::readFile(string file_name)
{
	ifstream read_file;
	read_file.open(file_name);
	if (read_file.is_open())
	{
		string read_line;
		getline(read_file, name_); //user name
		getline(read_file, read_line);
		level_ = stoi(read_line);
		getline(read_file, read_line);
		health_ = stoi(read_line);
		getline(read_file, read_line);
		mana_ = stoi(read_line);
		getline(read_file, read_line);
		money_ = stoi(read_line);

		//user skill with comma
		getline(read_file, read_line);
		stringstream skill_stream(read_line);
		string skill;
		while (getline(skill_stream, skill, '/'))
		{
			skill_.push_back(stoi(skill));
		}

		//user item with comma
		getline(read_file, read_line);
		stringstream item_stream(read_line);
		string item;
		while (getline(item_stream, item, '/'))
		{
			item_.push_back(stoi(item));
		}
	}
}

void UserData::writeFile(string file_name) const
{
	ofstream write_file(file_name);

	if (write_file.is_open()) {
		string temp_string;
		write_file << name_ << endl;
		write_file << level_ << endl;
		write_file << health_ << endl;
		write_file << mana_ << endl;
		write_file << money_ << endl;

		for (int i : skill_)
			temp_string += to_string(i) + "/";
		if(!temp_string.empty()) temp_string.pop_back();
		temp_string += "\n";

		for (int i : item_)
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

void UserData::selectData()
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
			readFile("user\\" + user_name + ".txt");
			return;
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

void UserData::newData()
{
	string user;
	while (true)
	{
		fflush(stdin);
		cout << "Please input your name : ";
		cin >> user;

		if (checkUser(user))
			cout << "[Error] User name already exists." << endl;
		else
			break;
	}
	name_ = user;
	// Add basic item and skills to new user
	addItem(0);
	addSkill(0);
	saveData();
}

void UserData::loadData()
{
	selectData();
}

void UserData::saveData() const
{
	writeFile("user\\" + name_ + ".txt");
}

void UserData::removeData()
{

}

void UserData::showData(ItemData& itemdata) const
{
	cout << "---------------------------------------------" << endl;
	cout << "\t[Inventory]" << endl;
	cout << "---------------------------------------------" << endl;
	for (vector<int>::size_type i = 0; i < item_.size(); i++)
		cout << "[ " << i << " ] " << itemdata.getName(i) << endl;
	cout << "---------------------------------------------" << endl;
}

void UserData::showData(SkillData& skilldata) const
{

	cout << "---------------------------------------------" << endl;
	cout << "\t[Skills]" << endl;
	cout << "---------------------------------------------" << endl;
	for (int i : skill_)
		cout << "[ " << i << " ] " << skilldata.getName(i) << endl;
	cout << "---------------------------------------------" << endl;
}

void UserData::showData(SkillData &skilldata, ItemData &itemdata) const
{
	cout << "\n---------------------------------------------" << endl;
	cout << "\t[Character Status]" << endl;
	cout << "---------------------------------------------" << endl;
	cout << "[LV." << level_ << "] " << name_ << endl;
	cout << "Health : " << health_ << endl;
	cout << "Mana : " << mana_ << endl;
	cout << "Money : " << money_ << endl;
	cout << "---------------------------------------------" << endl;
	cout << "\t[Skills]" << endl;
	cout << "---------------------------------------------" << endl;
	for (int i : skill_)
		cout << skilldata.getName(i) << endl;
	cout << "---------------------------------------------" << endl;
	cout << "\t[Inventory]" << endl;
	cout << "---------------------------------------------" << endl;
	for (int i : item_)
		cout << itemdata.getName(i) << endl;
	cout << "---------------------------------------------" << endl;
}

void UserData::addSkill(int code)
{
	if (find(skill_.begin(), skill_.end(), code) == skill_.end())
	{
		skill_.push_back(code);
		sort(skill_.begin(), skill_.end());
	}
	else
	{
		cout << "[Info] You already have the skill." << endl;
	}
}

void UserData::addItem(int code)
{
	item_.push_back(code);
	sort(item_.begin(), item_.end());
}

int UserData::useItem(ItemData& item_data, int index)
{
	if (item_.size() <= index)
	{
		cout << "[Info] Can't use that item. (Out of range)" << endl;
		return 0;
	}

	vector<int> item_effect = item_data.getEffect(item_[index]);
	item_.erase(item_.begin() + index);

	if(item_effect[1] == 0)//health
	{
		cout << "[Info] Recovered health +" << item_effect[2] << endl;
		addHealth(item_effect[2]);
		return 0;
	}
	else if (item_effect[1] == 1)//mana
	{
		cout << "[Info] Recovered Mana +" << item_effect[2] << endl;
		addMana(item_effect[2]);
		return 0;
	}
	else//granade.
	{
		cout << "BOOM!" << endl;
		return item_effect[2];
	}
}

void UserData::addHealth(int value)
{
	health_ += value;
}

void UserData::addMana(int value)
{
	mana_ += value;
}

void UserData::addMoney(int value)
{
	money_ += value;
}