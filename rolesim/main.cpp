// main.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "playdata.h"
#include "itemdata.h"
#include "npcdata.h"

using namespace std;

int main()
{
    int input;
    ItemData item_data;
    PlayData play_data;
    NpcData npc_data;
    cout << "-----------------------------" << endl;
    cout << "Role playing game simulator" << endl;
    cout << "-----------------------------" << endl;
    cout << "1) New Game    2) Load Game" << endl;
    cout << "-----------------------------" << endl;
    while (true)
    {
        cout << "Input : ";
        cin >> input;
        if (input == 1)
        {
            play_data.NewData();
            break;
        }
        else if (input == 2)
        {
            play_data.LoadData();
            break;
        }
        else
        {
            cout << "Please enter valid input." << endl;
            fflush(stdin);
        }
    }
    play_data.ShowData(item_data);

}