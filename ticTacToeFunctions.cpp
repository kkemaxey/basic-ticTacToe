#include <iostream>
#include "ticTacToeHeader.h"
using namespace std;

//----------------------------------
// Basic constructor for the player
//----------------------------------

Player::Player()
{
    firstName = ' ';
    lastName = ' ';
    wins = losses = draws = 0;
}


//---------------------------
// Erases all of data stored
//---------------------------

Player::~Player()
{
    firstName = ' ';
    lastName = ' ';
    wins = losses = draws = 0;
}


//------------------------------------------------------------------------------------------------------------
// This function makes use of the isValidName and substring function to validate a player's name and set them
//------------------------------------------------------------------------------------------------------------

void Player::getName(int playerNum)
{
    bool finished = false;

    do
    {
        string nameCheck;
        cout << "Player " << playerNum << ", Please enter your name -> ";
        getline(cin, nameCheck);

        int space = 0;
        while (nameCheck[space] != ' ')
        {
            space++;
        }

        string tempFirst, tempLast;
        tempFirst = substring(nameCheck, 0, space);
        tempLast = substring(nameCheck, space + 1, nameCheck.length());

        if (isValidName(tempFirst) && isValidName(tempLast))
        {
            firstName = format(tempFirst);
            lastName = format(tempLast);
            finished = true;
        }
        else
        {
            cout << "Please enter a valid name." << endl;
        }
    } while (!finished);
}


//------------------------------------
// This updates the stats of a player
//------------------------------------

void Player::setStats(int w, int l, int d)
{
    wins += w;
    losses += l;
    draws += d;
}


//---------------------------------
// This just prints the first name
//---------------------------------

string Player::printName()
{
    return firstName;
}


//--------------------------------------------------
// This prints the player's wins, losses, and draws
//--------------------------------------------------

void Player::printStats()
{
    cout << "---------------------------" << endl; 
    cout << firstName << " " << lastName << ":" << endl;
    cout << "Wins: " << wins << " Losses: " << losses << " Draws: " << draws << endl;
    cout << "---------------------------" << endl; 
}


//----------------------------------------------------------
// This adds all the stats to keep track of the total games
//----------------------------------------------------------

int Player::totalGames()
{
    return (wins + losses + draws);
}


//------------------------------------------------------
// This just sets everything in array to an empty space
//------------------------------------------------------

Board::Board()
{
    board[0] = '7';
    board[1] = '8';
    board[2] = '9';
    board[3] = '6';
    board[4] = '1';
    board[5] = '2';
    board[6] = '5';
    board[7] = '4';
    board[8] = '3';
}


//------------------------------------------
// This clears the array to reset the board
//------------------------------------------

Board::~Board()
{
    board[0] = '7';
    board[1] = '8';
    board[2] = '9';
    board[3] = '6';
    board[4] = '1';
    board[5] = '2';
    board[6] = '5';
    board[7] = '4';
    board[8] = '3';
}


//-----------------------------------------------------------------------------------------------------------------
// This function validates that the position is a valid position and inserts the player's piece into the gameboard
//-----------------------------------------------------------------------------------------------------------------

void Board::setPiece(string name, char piece)
{
    string userInput;
    bool set = false;

    while (!set)
    {
        cout << name << ", where would you like to place your piece? -> ";
        getline(cin, userInput);

        while (userInput[0] > '9' || userInput[0] < '1' || userInput.length() != 1)
        {
            cout << "Please insert a valid input -> ";
            getline(cin, userInput);
        }
        
        bool full = true;
        for (int i = 0; i < 9; i++)
        {
            if (userInput[0] == board[i])
            {
                board[i] = piece;
                full = false;
                set = true;
                break;
            } 
        }

        if (full)
        {
            cout << "That spot is full." << endl;
            cout << "Please insert a valid input." << endl;
        }
    }
    printBoard();
}


//-----------------------------------------------------------
// This will print the board according to the specifications
//-----------------------------------------------------------

void Board::printBoard()
{
    for (int i = 0; i < 9; i = i+3)
    {
        cout << "+---+---+---+" << endl;
        cout << "| " << board[i] << " | " << board[i+1] << " | " << board[i+2] << " |" << endl;
    }

    cout << "+---+---+---+" << endl;
}


//---------------------------------------------------------
// This checks all of the winning positions for the player
//---------------------------------------------------------

bool Board::checkWin(char piece)
{
    for (int i = 0; i <= 2; i++)
    {
        if (board[i] == board[i+3] && board[i+3] == board[i+6] && board[i+6] == piece)
        {
            return true; 
        }
    }

    for (int i = 0; i <= 6; i = i+3)
    {
        if (board[i] == board[i+1] && board[i+1] == board[i+2] && board[i+2] == piece)
        {
            return true;
        }
    }

    if ((board[2] == board[4] && board[4] == board[6] && board[6] == piece)||
        (board[0] == board[4] && board[4] == board[8] && board[8] == piece))
    {
        return true;
    }
    else
    {
        return false;
    }
}


//----------------------------------
// This checks if the board is full
//----------------------------------
bool Board::isFull()
{
    int counter = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (board[i] == 'x' || board[i] == 'o')
        {
            counter++;
        }
    }

    return counter == 9;
}


//-----------------------------------------------------------------------------------------------------------------
// This function test for the most common combination of characters to a valid name and returns true if it's valid
//-----------------------------------------------------------------------------------------------------------------

bool isValidName(string str)
{
    if (str[0] == '\'' || str[0] == '-' || str.length() == 0)
    {
        return false;
    }

    for (int i = 0; i < str.length(); i++)
    {
        if (isAlpha(str[i]) || ((str[i] == '\'') || (str[i] == '-') && isAlpha(str[i+1])))
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}


//---------------------------------------------------------------
// This will determine who starts the very beginning of the game
//---------------------------------------------------------------

bool gameStart()
{
    string userInput;
    cout << "Who would you like to start the game first? 1 or 2? -> ";
    getline(cin, userInput);

    while ((userInput[0] != '1' && userInput[0] != '2') || userInput.length() != 1)
    {
        cout << "Please insert a valid input -> ";
        cin >> userInput;
    }

    return userInput == "1";
}


//---------------------------------------------------
// This determines if the user wants to retry or not
//---------------------------------------------------

bool retry()
{
    string userInput;
    cout << "Would you like to play again? Y/N -> ";
    getline(cin, userInput);

    while ((userInput[0] != 'Y') && (userInput[0] != 'N') || userInput.length() != 1)
    {
        cout << "Please insert a valid input -> ";
        getline(cin, userInput);
    }

    if (userInput[0] == 'Y')
    {
        return true;
    }
    else
    {
        cout << "Thanks for playing!" << endl;
        return false;
    }
} 


//------------------------------------------------------------------------------------
// This formats any name so that the first letter is uppercase and the rest are lower
//------------------------------------------------------------------------------------

string format(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        str[i] = toLower(str[i]);

        if(str[i] == '-')
        {
            str[i+1] = toUpper(str[i+1]);
            i++;
        }
    }

    str[0] = toUpper(str[0]);
    return str;
}


//------------------------------------------------------------------------------------------------
// This creates a substring if given the start position and end position of the desired substring
//------------------------------------------------------------------------------------------------

string substring(string str, int start, int end)
{
    string str2;

    for (int i = start; i < end; i++)
    {
        if (str[i] == '\'' || str[i] == '-')
        {
            str2 += str[i];
        }
        else
        {
            str2 += str[i];
        }
    }

    return str2;
}


//------------------------------------------------------------------------
// This returns true if the character is an uppercase or lowercase letter
//------------------------------------------------------------------------

bool isAlpha(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}


//------------------------------------------------------------
// This returns the capitalized letter if the input is valid
//------------------------------------------------------------

char toUpper(char c)
{
    return c & ~32;
}


//----------------------------------------------------------
// This returns the lowercased letter if the input is valid
//----------------------------------------------------------

char toLower(char c)
{
    return c | 32;
}