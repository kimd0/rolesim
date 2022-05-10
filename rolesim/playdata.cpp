#include "playdata.h"

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
		while (getline(kstream, skill, ','))
		{
			skill_.push_back(stoi(skill));
		}

		//player item with comma
		getline(read_file, read_line);
		stringstream istream(read_line);
		string item;
		while (getline(istream, item, ','))
		{
			item_.push_back(stoi(item));
		}
	}
}

void PlayData::WriteFile(string file_name)
{

}

bool PlayData::SelectData()
{
	string player;
	string data;
	vector<string> data_list;
	filesystem::path p("./player");
	cout << "-----------------------------" << endl;
	cout << "Saved Data" << endl;
	cout << "-----------------------------" << endl;
	for (auto& p : filesystem::recursive_directory_iterator(p))
	{
		data = p.path().filename().string();
		data = data.substr(0, data.length() - 4);
		data_list.push_back(data);
		cout << data << endl; //결과: test.txt
	}
	cout << "-----------------------------" << endl;
	cout << "Input player name :";
	cin >> player;

	if (find(data_list.begin(), data_list.end(), player) != data_list.end())
	{
		cout << "[Success] Valid data name." << endl;
		ReadFile("player\\" + player + ".txt");
		return true;
	}
	else
	{
		cout << "[Error] Please input valid data name." << endl;
		return false;
	}
}

void PlayData::NewData()
{
	//정보 입력 받아서 저장
	//초기 아이템 지급
	SaveData();
}

void PlayData::LoadData()
{
	while (!SelectData());
}

void PlayData::SaveData()
{
	WriteFile(name_);
}

void PlayData::RemoveData()
{

}

void PlayData::ShowData()
{
	cout << "-----------------------------" << endl;
	cout << "[Character Status]" << endl;
	cout << "-----------------------------" << endl;
	cout << "[LV." << level_ << "] " << name_ << endl;
	cout << "Health : " << health_ << endl;
	cout << "Mana : " << mana_ << endl;
	cout << "Money : " << mana_ << endl;
	cout << "-----------------------------" << endl;
	cout << "[Skills]" << endl;
	cout << "-----------------------------" << endl;
	cout << "-----------------------------" << endl;
	cout << "[Inventory]" << endl;
	cout << "-----------------------------" << endl;
}