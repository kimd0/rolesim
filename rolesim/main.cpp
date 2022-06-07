#include <iostream>
#include "playdata.h"
#include "stagemanager.h"

using namespace std;

int main()
{
    int input;
    PlayData *play_data = new PlayData();
    StageManager *stage_manager = new StageManager(*play_data);
    cout << R"(
	    ____        __        ____  __            _                ______                   
	   / __ `____  / /__     / __ `/ /___ ___  __(_)___  ____ _   / ____/___ _____ ___  ___ 
	  / /_/ / __ `/ / _ `   / /_/ / / __ `/ / / / / __ `/ __ `/  / / __/ __ `/ __ `__  ` _ `
	 / _, _/ /_/ / /  __/  / ____/ / /_/ / /_/ / / / / / /_/ /  / /_/ / /_/ / / / / / /  __/
	/_/ |_|`____/_/`___/  /_/   /_/`__,_/`__, /_/_/ /_/`__, /   `____/`__,_/_/ /_/ /_/`___/ 
	                                    /____/        /____/                                
	)" << endl;
    cout << "\t\t\t1) New Game\t\t 2) Load Game" << endl;
    while (true)
    {
        cout << "Input: ";
        cin >> input;
        
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "[Info] Please enter valid input." << endl;
            continue;
        }
        
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
            cout << "[Info] Please enter valid input." << endl;
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