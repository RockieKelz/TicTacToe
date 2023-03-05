#pragma once

#include<iostream>
#include<stdio.h>
#include <string>
#include "Player.h"

using namespace std;

typedef struct {
    int* row;
}WinningComboList;

class Game
{
private:
    char board[9] = { '1', '2',
    '3', '4', '5',
    '6', '7', '8', '9' };
    int emptyIndex[9];
    int emptyCount, playerTurn = 1;;
    string player1 = "PLAYER 1", player2 = "PLAYER 2";
    bool againstComputer, gameOver;
    WinningComboList winningCombinationsList[8];
    void displayBoard();
    void playerInput(Player& player);
    void computerInput();
    void checkForWinner(Player& p1, Player& p2);
    void displayResults(Player& p1, Player& p2);

public:
    Game() : emptyCount{ 0 }, gameOver{ false }, againstComputer{ false }{
        init();
        winningCombinationsList[0].row = new int[3]{ 0,1,2 };
        winningCombinationsList[1].row = new int[3]{ 3,4,5 };
        winningCombinationsList[2].row = new int[3]{ 6,7,8 };
        winningCombinationsList[3].row = new int[3]{ 0,3,6 };
        winningCombinationsList[4].row = new int[3]{ 1,4,7 };
        winningCombinationsList[5].row = new int[3]{ 2,5,8 };
        winningCombinationsList[6].row = new int[3]{ 0,4,8 };
        winningCombinationsList[7].row = new int[3]{ 2,4,6 };
    }
    void init();
    void onePlayerGame();
    void twoPlayerGame();
    void playGame(Player& p1, Player& p2);
};

