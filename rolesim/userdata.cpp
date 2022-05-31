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
	string read_line;
	read_file.open(file_name);
	if (read_file.is_open())
	{
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
		stringstream kstream(read_line);
		string skill;
		while (getline(kstream, skill, '/'))
		{
			skill_.push_back(stoi(skill));
		}

		//user item with comma
		getline(read_file, read_line);
		stringstream istream(read_line);
		string item;
		while (getline(istream, item, '/'))
		{
			item_.push_back(stoi(item));
		}
	}
}

void UserData::writeFile(string file_name)
{
	ofstream write_file(file_name);
	string temp_string = "";
	if (write_file.is_open()) {
		write_file << name_ << endl;
		write_file << level_ << endl;
		write_file << health_ << endl;
		write_file << mana_ << endl;
		write_file << money_ << endl;

		for (int i = 0; i < skill_.size(); ++i)
			temp_string += to_string(skill_[i]) + "/";
		if(!temp_string.empty()) temp_string.pop_back();
		temp_string += "\n";

		for (int i = 0; i < item_.size(); ++i)
			temp_string += to_string(item_[i]) + "/";
		if (!temp_string.empty()) temp_string.pop_back();

		write_file << temp_string;
		write_file.close();
	}
}

void UserData::getUserList()
{
	string user;
	filesystem::path p("./user");
	for (auto& p : filesystem::recursive_directory_iterator(p))
	{
		user = p.path().filename().string();
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
	for (int i = 0; i < user_list_.size(); ++i)
		cout << user_list_[i] << endl;
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

bool UserData::checkData(string user)
{
	filesystem::path p("./user/" + user + ".txt");
	if (filesystem::exists(p))
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

void UserData::saveData()
{
	writeFile("user\\" + name_ + ".txt");
}

void UserData::removeData()
{

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
	for (int i = 0; i < skill_.size(); ++i)
		cout << skilldata.getName(skill_[i]) << endl;
	cout << "---------------------------------------------" << endl;
	cout << "\t[Inventory]" << endl;
	cout << "---------------------------------------------" << endl;
	for (int i = 0; i < item_.size(); ++i)
		cout << itemdata.getName(item_[i]) << endl;
	cout << endl;
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

void UserData::addMoney(int value)
{
	money_ += value;
}