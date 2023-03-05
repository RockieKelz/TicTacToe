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
    //Create Players
    cout << "Enter Player's Name: ";
    cin >> player1;
    Player p1(player1);

    player2 = "COMP";
    Player p2(player2);
    //set game type
    againstComputer = true;

    //iniatate game
    playGame(p1, p2);
}

void Game::twoPlayerGame()
{
    //Create Players
    cout << "Enter First Player's Name: ";
    cin >> player1;
    Player p1(player1);

    cout << "\nEnter Second Player's Name: ";
    cin >> player2;
    Player p2(player2);

    //set game type
    againstComputer = false;

    //iniatate game
    playGame(p1, p2);
}

void Game::playGame(Player &p1, Player &p2) {
    system("cls");
    displayBoard();
}
