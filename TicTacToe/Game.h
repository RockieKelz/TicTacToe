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
    int emptyIndex[9];
    int emptyCount = 9;
    string player1 = "PLAYER 1", player2 = "PLAYER 2";
    bool againstComputer, gameOver;
    void displayBoard();
    void playerInput(Player& player);
    void computerInput();

public:
    void init();
    void onePlayerGame();
    void twoPlayerGame();
    void playGame(Player& p1, Player& p2);
};

