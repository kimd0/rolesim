#include <iostream>
#include "datamanager.h"
#include "menumanager.h"
#include "stagemanager.h"

using namespace std;

int main()
{
    int input;
    DataManager *data_manager = new DataManager();
    StageManager *stage_manager = new StageManager(*data_manager);
    MenuManager *menu_manager = new MenuManager();

    while (true)
    {
        menu_manager->showMenu();
        input = menu_manager->getInput();

        if (input == 1)
        {
            data_manager->newGame();
        }
        else if (input == 2)
        {
            data_manager->loadGame();
        }
        else if (input == 3)
        {
            data_manager->showData();
            continue;
        }
        else if (input == 4)
        {
            cout << "Thanks for playing!" << endl;
            break;
        }

        data_manager->showInfo();

        //actual game play (combat)
        cout << "[Info] You have entered the dungeon." << endl;
        while (true)
        {
            if (!stage_manager->newStage())
                break;
        }

        cout << "[Info] Your adventure is over." << endl;
        data_manager->saveGame();
    }

    return 0;
}