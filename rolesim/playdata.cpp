#include "playdata.h"

PlayData::PlayData()
{
	LoadData();
}

PlayData::~PlayData()
{
	delete user_data_;
	delete item_data_;
	delete skill_data_;
}

void PlayData::LoadData()
{
	user_data_ = new UserData();
	item_data_ = new ItemData();
	skill_data_ = new SkillData();
}

void PlayData::NewGame()
{
	user_data_->NewData();
}

void PlayData::LoadGame()
{
	user_data_->LoadData();
}

void PlayData::SaveGame()
{
	user_data_->SaveData();
}

void PlayData::ShowInfo()
{
	user_data_->ShowData(*skill_data_, *item_data_);
}

void PlayData::GainItem(int code)
{
	user_data_->AddItem(code);
}

void PlayData::GainSkill(int code)
{
	user_data_->AddSkill(code);
}

string PlayData::GetItemInfo(int code)
{
	return item_data_->GetName(code);
}

string PlayData::GetSkillInfo(int code)
{
	return skill_data_->GetName(code);
}