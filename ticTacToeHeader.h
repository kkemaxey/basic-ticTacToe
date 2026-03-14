#ifndef TICTACTOEHEADER_H
#define TICTACTOEHEADER_H
using namespace std;

class Board
{
    private:
        static const int SIZE = 9;
        char board[SIZE];

    public:
        Board();
        ~Board();
        void setPiece(string, char);
        void printBoard();
        bool checkWin(char);
        bool isFull();
};

class Player
{
    private:
        string firstName, lastName;
        char piece;
        int wins, losses, draws;

    public:
        Player();
        ~Player();
        void getName(int);
        void setStats(int, int, int);
        string printName();
        void printStats();
        int totalGames();
};

bool isValidName(string);
bool gameStart();
bool retry();
string format(string);
string substring(string, int, int);
bool isAlpha(char);
char toUpper(char);
char toLower(char);

#endif