#pragma once

#include<iostream>
#include<stdio.h>
#include <string>
#include "Player.h"

using namespace std;
class Game
{
private:
    char board[9] = { '1', '2',
    '3', '4', '5',
    '6', '7', '8', '9' };
    string player1 = "PLAYER 1", player2 = "PLAYER 2";
    bool againstComputer;
    void displayBoard();
public:
   
    void init();
    void onePlayerGame();
    void twoPlayerGame();
    void playGame(Player& p1, Player& p2);
};

