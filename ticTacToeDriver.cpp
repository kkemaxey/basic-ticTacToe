#include <iostream>
#include "ticTacToeHeader.h"
using namespace std;

//------------------------------------------------------------------------------
// The main function will hold the primary game logic using the functions given
//------------------------------------------------------------------------------

int main()
{
    Player P1, P2;
    Board gameBoard;

    P1.getName(1);
    P2.getName(2);

    bool start = gameStart();
    bool restart = false;
    // char p[] = {'x', 'o'};

    do
    {
        gameBoard.printBoard();
        char o = 'o';
        char x = 'x';

        if (start)
        {
            while (!gameBoard.checkWin(x) && !gameBoard.checkWin(o) && !gameBoard.isFull())
            {
                gameBoard.setPiece(P1.printName(), x);

                if (gameBoard.checkWin(x) || gameBoard.isFull())
                {
                    break;
                }

                gameBoard.setPiece(P2.printName(), o);

                if (gameBoard.checkWin(o) || gameBoard.isFull())
                {
                    break;
                }
            }
        }
        else
        {
            while (!gameBoard.checkWin(x) && !gameBoard.checkWin(o) && !gameBoard.isFull())
            {
                gameBoard.setPiece(P2.printName(), o);

                if (gameBoard.checkWin(o) || gameBoard.isFull())
                {
                    break;
                }

                gameBoard.setPiece(P1.printName(), x);

                if (gameBoard.checkWin(x) || gameBoard.isFull())
                {
                    break;
                }
            }
        }

        if (gameBoard.checkWin(x))
        {
            cout << "Congratulations, " << P1.printName() << "! You won!" << endl;

            P1.setStats(1, 0, 0);
            P2.setStats(0, 1, 0);
        }
        else if (gameBoard.checkWin(o))
        {
            cout << "Congratulations, " << P2.printName() << "! You won!" << endl;

            P2.setStats(1, 0, 0);
            P1.setStats(0, 1, 0);
        }
        else
        {
            cout << "The board is full! That's a draw!" << endl;
            P1.setStats(0, 0, 1);
            P2.setStats(0, 0, 1);
        }

        cout << endl << "Total number of games: " << P1.totalGames() << endl;
        P1.printStats();
        P2.printStats();

        restart = retry();
        start = !start;
        gameBoard.~Board();
    } while (restart);

    return 0;
}