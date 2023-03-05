#include "Game.h"

void Game::displayBoard()
{
    cout << endl;
    cout << "\n\n\t\t\t   T I C K -- T A C -- T O E\n\n\n";
    cout << "\t\t\t " << player1 << ": [X] \t" << player2 << ": [O]\n\n";
    cout << "\t\t\t\t   |   |   " << endl;
    cout << "\t\t\t\t " << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << "\t\t\t\t   |   |   " << endl;
    cout << "\t\t\t\t-----------" << endl;
    cout << "\t\t\t\t   |   |   " << endl;
    cout << "\t\t\t\t " << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << "\t\t\t\t   |   |   " << endl;
    cout << "\t\t\t\t-----------" << endl;
    cout << "\t\t\t\t   |   |   " << endl;
    cout << "\t\t\t\t " << board[6] << " | " << board[7] << " | " << board[8] << endl;
    cout << "\t\t\t\t   |   |   " << endl;
    cout << endl;
    
}

void Game::init()
{
    displayBoard();
}

void Game::onePlayerGame()
{
}

void Game::twoPlayerGame()
{
}
