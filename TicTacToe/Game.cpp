#include "Game.h"
#include <Windows.h>

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

void Game::playerInput(Player& player)
{
    int selectedSpot;
    //get the player's selected space
    cout << "\n\t\t" << player.getName() << "'s Turn: \n";
    cout << "\t\tSelect an open position on the board " << endl;
    cin >> selectedSpot;
    //get the selected space's index number
    selectedSpot -= 1;
    //check if the space is open
    if (emptyIndex[selectedSpot] == 1) {
        cout << "\n-----That spot is not empty. Try Again-------" << endl;
        playerInput(player);
    }
    else {
        //mark the spot as occuppied
        emptyIndex[selectedSpot] = 1;
        emptyCount -= 1;
        player.getName().compare(player1) == 0 ? board[selectedSpot] = 'X' : board[selectedSpot] = 'O';
    }

}

void Game::computerInput()
{
    Sleep(200);
    //randomly select a position on the board
    int selectedSpot;
    int n;
    srand(time(NULL));
    selectedSpot = rand() % 10;

    //check if the space is taken
    if (emptyIndex[selectedSpot] == 1) {
        if (emptyCount < 0)
            return;
        computerInput();
    }
    else { //if spot is open, mark it as taken by the computer
        cout << "\nComputer chose: " << selectedSpot + 1 << endl;
        emptyIndex[selectedSpot] = 1;
        emptyCount -= 1;
        board[selectedSpot] = 'O';
    }
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
    //show the game board
    displayBoard();

    //set the game flags
    gameOver = false;
    int playerTurn = 1;
    
    //start the game
    while (!gameOver)
    {
        //check player's turn
        if (againstComputer) {
            playerTurn == 1 ? playerInput(p1) : computerInput();
        }
        else
        {
            playerTurn == 1 ? playerInput(p1) : playerInput(p2);
        }

        displayBoard();

        //change the current player's turn
        playerTurn = !playerTurn;
    }
}
