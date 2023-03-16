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
    //validate that the player chose a number from a valid range
    if (selectedSpot > 9 || selectedSpot < 1)
    {
        cout << "\n-----That is not a valid number. Try Again-------" << endl;
        playerInput(player);
    }

    //check if the space is open
    if (emptyIndex[selectedSpot - 1] == 1) {
        cout << "\n-----That spot is not empty. Try Again-------" << endl;
        playerInput(player);
    }
    else {
        //mark the spot as occuppied
        emptyIndex[selectedSpot - 1] = 1;
        emptyCount -= 1;
        player.getName().compare(player1) == 0 ? board[selectedSpot - 1] = 'X' : board[selectedSpot - 1] = 'O';
    }

}

void Game::computerInput()
{
    Sleep(75);
    //randomly select a position on the board
    int selectedSpot;
    srand(time(NULL));
    selectedSpot = rand() % 9;

    //check if the space is taken
    if (emptyIndex[selectedSpot] == 1) {
        if (emptyCount < 0)
            return;
        computerInput();
    }
    else { //if spot is open, mark it as taken by the computer
        system("cls");
        cout << "\nComputer chose: " << selectedSpot + 1 << endl;
        emptyIndex[selectedSpot] = 1;
        emptyCount -= 1;
        board[selectedSpot] = 'O';
    }
}

void Game::checkForWinner(Player& p1, Player& p2)
{
    int i, j;
    bool match = false;
    bool tie = false;
    char firstSymbol;
    for (i = 0; i < 8; i++) {
        //get the first char from the list of winning combinations list
        //and check if the position is occupied by a player
        firstSymbol = board[winningCombinationsList[i].row[0]];
        if ((firstSymbol != 'X') && (firstSymbol != 'O')) {
            match = false;
            continue;
        }
        //trigger the match flag 
        match = true;
        //compare the first char symbol with each char within the current winning list combo row index 
        for (j = 0; j < 3; j++) {
            //if it doesn't match, the game has not been won
            if (firstSymbol != board[winningCombinationsList[i].row[j]]) {
                //if there aren't any remaining empty spaces, it's a tie game
                if (emptyCount < 0) {
                    tie = true;
                    break;
                }
                //untrigger the flag
                match = false;
                break;
            }
        }
        //if the flag is still triggered
        if (match) {
            //game is over
            gameOver = true;
            //if the tie flag isn't triggered, reward the correct player points
            if (!tie) {
                if (firstSymbol == 'X') {
                    p1.won();
                }
                else {
                    p2.won();
                }
            }
            displayResults(p1, p2);
        }
    }
}

void Game::displayResults(Player &p1, Player &p2)
{
    cout << "\t\t\t-----------------------" << endl;
    if (emptyCount <= 0) {
        cout << "\t\t\t\tTIE GAME" << endl;
    }
    else if (playerTurn == 1) {
        cout << "\t\t\t   " << p1.getName() << " WON" << endl;
    }
    else {
        
        if (againstComputer) {
            cout << "\t\t\t  COMPUTER WON" << endl;
        }
        else {
            cout << "\t\t\t\t   " << p2.getName() << " WON" << endl;
        }

    }
    cout << "\t\t\t-----------------------" << endl;

    
    cout << endl;
    cout << "\t SCORE: \t";
    if (againstComputer)
        cout << p1.getName() << ": " << p1.getScore() << " \t Computer: " << p2.getScore() << endl;
    else
        cout << p1.getName() << ": " << p1.getScore() << " \t " << p2.getName() << ": " << p2.getScore() << endl;

    cout << endl;
    std::string rematch;
    cout << "Rematch Y/N: ";
    cin >> rematch;
    if ((rematch == "Y") || (rematch == "y")) {
        system("cls");
        init();
        playGame(p1, p2);
    }
}

void Game::init()
{
    gameOver = false;
    emptyCount = 0;
    srand(time(0));
    for (int i = 0; i < 9; i++) {
        emptyIndex[i] = 0;
        board[i] = (i + 1) + '0';
        emptyCount++;
    }
    emptyCount--;
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
        checkForWinner(p1, p2);
        //change the current player's turn
        playerTurn = !playerTurn;
    }
}
