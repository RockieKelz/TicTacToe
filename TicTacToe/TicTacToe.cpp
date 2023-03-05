// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include "Game.h"

using namespace std;

int main()
{
    int ch;

    while (1) {
        cout << "\n\n\t\t\tT I C K -- T A C -- T O E -- G A M E\n\n\n";
        cout << "\t\t\t      ----------MENU----------" << endl;
        cout << "\n\n\t\t\t\t 1. 1 Player game" << endl;
        cout << "\t\t\t\t 2. 2 Player game" << endl;
        cout << "\t\t\t\t 3. Exit \n\n" << endl;
        cout << "\t\t\t      ------------------------" << endl;
        cout << endl;
        cout << "\t\t\t\t Please select an option" << endl;

        cin >> ch;
        switch (ch) {
        case 1: {
            Game* game = new Game;
            game->onePlayerGame();
        }
              break;
        case 2: {
            Game* game = new Game;
            game->twoPlayerGame();
        }
              break;
        case 3:
            return 0;
        default:
            cout << "OOPs Invalid Option! TRY AGAIN";
        }

    }
    return 0;
}
