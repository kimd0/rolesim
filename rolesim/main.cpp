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

    //actual game play (combat)
    while (true)
    {

    }

    play_data.SaveData();
}