#pragma once
#include <string>

using namespace std;

/*�̸�, ����, HP, ������, ����ġ, �����۵��*/
class Monster 
{
private:
	string name;
	int level;
	int HP;
	int damage;
	int exp;
	string item;
public:
	Monster(string n, int n1, int n2, int n3, int n4, string i)
		:name(n), level(n1), HP(n2), damage(n3), exp(n4), item(i) {
	}

	void SetInfo(string n, int Level, int HitPoint, int Damage, int Exp, string i);
	void ShowInfo()const;
	~Monster()
	{
	
	}
};