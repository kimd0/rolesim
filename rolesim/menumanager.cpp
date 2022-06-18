#include "menumanager.h"

void MenuManager::showMenu() const
{
	cout << R"(
	    ____        __        ____  __            _                ______                   
	   / __ `____  / /__     / __ `/ /___ ___  __(_)___  ____ _   / ____/___ _____ ___  ___ 
	  / /_/ / __ `/ / _ `   / /_/ / / __ `/ / / / / __ `/ __ `/  / / __/ __ `/ __ `__  ` _ `
	 / _, _/ /_/ / /  __/  / ____/ / /_/ / /_/ / / / / / /_/ /  / /_/ / /_/ / / / / / /  __/
	/_/ |_|`____/_/`___/  /_/   /_/`__,_/`__, /_/_/ /_/`__, /   `____/`__,_/_/ /_/ /_/`___/ 
	                                    /____/        /____/                                
	)" << endl;
	cout << "\t1) New Game\t\t2) Load Game\t\t3) Show Data\t\t4) Exit" << endl;
	cout << "\t------------------------------------------------------------------------------------" << endl;
}

int MenuManager::getInput() const
{
    int input;

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

        switch(input)
        {
	        case 1:
	        case 2:
	        case 3:
	        case 4:
	            return input;
	        default:
	            cout << "[Info] Please enter valid input." << endl;
        }
    }
}
