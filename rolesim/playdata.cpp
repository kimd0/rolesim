#include "playdata.h"

PlayData::PlayData()
{
	name_ = "";
	level_ = 1;
	health_ = 100;
	mana_ = 50;
	money_ = 1000;
	skill_ = {};
	item_ = {};
	GetPlayerList();
}

void PlayData::ReadFile(string file_name)
{
	ifstream read_file;
	string read_line;
	read_file.open(file_name);
	if (read_file.is_open())
	{
		getline(read_file, name_); //player name
		getline(read_file, read_line);
		level_ = stoi(read_line);
		getline(read_file, read_line);
		health_ = stoi(read_line);
		getline(read_file, read_line);
		mana_ = stoi(read_line);
		getline(read_file, read_line);
		money_ = stoi(read_line);

		//player skill with comma
		getline(read_file, read_line);
		stringstream kstream(read_line);
		string skill;
		while (getline(kstream, skill, '/'))
		{
			skill_.push_back(stoi(skill));
		}

		//player item with comma
		getline(read_file, read_line);
		stringstream istream(read_line);
		string item;
		while (getline(istream, item, '/'))
		{
			item_.push_back(stoi(item));
		}
	}
}

void PlayData::WriteFile(string file_name)
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

void PlayData::GetPlayerList()
{
	string player;
	filesystem::path p("./player");
	for (auto& p : filesystem::recursive_directory_iterator(p))
	{
		player = p.path().filename().string();
		player = player.substr(0, player.length() - 4);
		player_list_.push_back(player);
	}
}

void PlayData::SelectData()
{
	string player;
	cout << "-----------------------------" << endl;
	cout << "Saved Data" << endl;
	cout << "-----------------------------" << endl;
	for (int i = 1; i < player_list_.size(); i++)
		cout << player_list_[i] << endl;
	cout << "-----------------------------" << endl;

	while (true)
	{
		cout << "Input player name :";
		cin >> player;

		if (CheckPlayer(player))
		{
			cout << "[Success] Valid data name." << endl;
			ReadFile("player\\" + player + ".txt");
			return;
		}
		else
		{
			cout << "[Error] Please input valid data name." << endl;
			fflush(stdin);
		}
	}
}

bool PlayData::CheckData(string player)
{
	filesystem::path p("./player/" + player + ".txt");
	if (filesystem::exists(p))
		return true;
	else
		return false;
}

bool PlayData::CheckPlayer(string player)
{
	if (find(player_list_.begin(), player_list_.end(), player) != player_list_.end())
		return true;
	else
		return false;
}

void PlayData::NewData()
{
	string player;
	while (true)
	{
		cout << "Please input your name : ";
		cin >> player;

		if (CheckPlayer(player))
		{
			cout << "[Error] Player name already exists." << endl;
			fflush(stdin);
		}
		else break;
	}
	name_ = player;
	// Add basic item and skills to new player
	AddItem(0);
	AddSkill(0);
	SaveData();
}

void PlayData::LoadData()
{
	SelectData();
}

void PlayData::SaveData()
{
	WriteFile("player\\" + name_ + ".txt");
}

void PlayData::RemoveData()
{

}

void PlayData::ShowData(ItemData &itemdata)
{
	cout << "-----------------------------" << endl;
	cout << "[Character Status]" << endl;
	cout << "-----------------------------" << endl;
	cout << "[LV." << level_ << "] " << name_ << endl;
	cout << "Health : " << health_ << endl;
	cout << "Mana : " << mana_ << endl;
	cout << "Money : " << money_ << endl;
	cout << "-----------------------------" << endl;
	cout << "[Skills]" << endl;
	cout << "-----------------------------" << endl;
	//add after skilldata class implementation
	cout << "-----------------------------" << endl;
	cout << "[Inventory]" << endl;
	cout << "-----------------------------" << endl;
	for (int i = 0; i < item_.size(); ++i)
		cout << itemdata.GetName(item_[i]) << endl;
}

void PlayData::AddSkill(int code)
{
	if (find(skill_.begin(), skill_.end(), code) == skill_.end())
		skill_.push_back(code);
}

void PlayData::AddItem(int code)
{
	item_.push_back(code);
}