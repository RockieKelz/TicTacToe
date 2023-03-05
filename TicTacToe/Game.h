#pragma once

#include<stdio.h>
#include <string>
#include<iostream>
using namespace std;
class Game
{
private:
    char board[9] = { '1', '2',
    '3', '4', '5',
    '6', '7', '8', '9' };
    string player1 = "PLAYER 1", player2 = "PLAYER 2";

    void displayBoard();
public:
   
    void init();
    void onePlayerGame();
    void twoPlayerGame();
};

