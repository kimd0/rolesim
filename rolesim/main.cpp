﻿#include <iostream>
#include "playdata.h"
#include "stagemanager.h"

using namespace std;

int main()
{
    int input;
    PlayData *play_data = new PlayData();
    StageManager *stage_manager = new StageManager(*play_data);

    cout << "---------------------------------------------" << endl;
    cout << "\tRole playing game simulator\t" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "\t1) New Game\t 2) Load Game" << endl;
    cout << "---------------------------------------------" << endl;
    while (true)
    {
        cout << "Input: ";
        cin >> input;
        if (input == 1)
        {
            play_data->NewGame();
            break;
        }
        else if (input == 2)
        {
            play_data->LoadGame();
            break;
        }
        else
        {
            cout << "Please enter valid input." << endl;
            fflush(stdin);
        }
    }
    play_data->ShowInfo();

    //actual game play (combat)
    cout << "[Info] You have entered the dungeon." << endl;
    while (true)
    {
        if (!stage_manager->NewStage())
            break;
    }

    cout << "[Info] Your adventure is over." << endl;
    play_data->SaveGame();


    delete play_data;
    delete stage_manager;

    return 0;
}