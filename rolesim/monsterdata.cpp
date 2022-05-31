#include "monsterdata.h"
#include <iostream>

using namespace std;

void Monster::SetInfo(string n, int Level, int HitPoint, int Damage, int Exp, string i)
{
	name = n;
	level = Level;
	HP = HitPoint;
	damage = Damage;
	exp = Exp;
	item = i;
}
void Monster::ShowInfo()const
{
	cout << "Name: " << name << endl;
	cout << "Level: " << level << endl;
	cout << "HP: " << HP << endl;
	cout << "Damage: " << damage << endl;
	cout << "EXP:" << exp << endl;
	cout << "Item: " << item << endl;
}
//´ÞÆØÀÌ
Monster monsterArr[5];
monsterArr[0].SetInfo = { "Snail", 1, 5, 2, 20, "shell"};
monsterArr[1].SetInfo = { "Pig", 5, 40, 8, 100, "leather"};
monsterArr[2].SetInfo = { "Goblin", 10, 100, 30, 250, "sword"};
monsterArr[3].SetInfo = { "Dragon", 30, 300, 100, 1000, "protectivegear"};
monsterArr[4].SetInfo = { "Boss", 60, 1000, 400, 10000, "alcohol" };
