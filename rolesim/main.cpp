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
   / __ \____  / /__     / __ \/ /___ ___  __(_)___  ____ _   / ____/___ _____ ___  ___ 
  / /_/ / __ \/ / _ \   / /_/ / / __ `/ / / / / __ \/ __ `/  / / __/ __ `/ __ `__ \/ _ \
 / _, _/ /_/ / /  __/  / ____/ / /_/ / /_/ / / / / / /_/ /  / /_/ / /_/ / / / / / /  __/
/_/ |_|\____/_/\___/  /_/   /_/\__,_/\__, /_/_/ /_/\__, /   \____/\__,_/_/ /_/ /_/\___/ 
                                    /____/        /____/                                
)" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "\tRole playing game simulator\t" << endl;
    cout << "---------------------------------------------" << endl;
    cout << R"(
 
  ___    _  __             _____              
 <  /   / |/ /__ _    __  / ___/__ ___ _  ___ 
 / /   /    / -_) |/|/ / / (_ / _ `/  ' \/ -_)
/_(_) /_/|_/\__/|__,__/  \___/\_,_/_/_/_/\__/ 
                                              

        )" << "\t" <<
        R"(

   ___      __                __  _____              
  |_  |    / /  ___  ___ ____/ / / ___/__ ___ _  ___ 
 / __/_   / /__/ _ \/ _ `/ _  / / (_ / _ `/  ' \/ -_)
/____(_) /____/\___/\_,_/\_,_/  \___/\_,_/_/_/_/\__/ 
                                                     

                                            
)" << endl;
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