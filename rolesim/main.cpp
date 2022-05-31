#include <iostream>
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
        fflush(stdin);
        cout << "Input: ";
        cin >> input;
        if (input == 1)
        {
            play_data->newGame();
            break;
        }
        else if (input == 2)
        {
            play_data->loadGame();
            break;
        }
        else
        {
            cout << "Please enter valid input." << endl;
        }
    }
    play_data->showInfo();

    //actual game play (combat)
    cout << "[Info] You have entered the dungeon." << endl;
    while (true)
    {
        if (!stage_manager->newStage())
            break;
    }

    cout << "[Info] Your adventure is over." << endl;
    play_data->saveGame();

    return 0;
}