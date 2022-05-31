#include <iostream>
#include "playdata.h"

using namespace std;

int main()
{
    int input;
    PlayData play_data;

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
            play_data.NewGame();
            break;
        }
        else if (input == 2)
        {
            play_data.LoadGame();
            break;
        }
        else
        {
            cout << "Please enter valid input." << endl;
            fflush(stdin);
        }
    }
    play_data.ShowInfo();

    //actual game play (combat)
    while (true)
    {

    }

    play_data.SaveGame();

    return 0;
}