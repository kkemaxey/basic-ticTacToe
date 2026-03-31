# ❌ Tic-Tac-Toe ⭕

> A clean, interactive version of the classic paper-and-pencil game.

## 🎮 How to Play
1. The game is played on a grid that's 3 squares by 3 squares.
2. You decide who plays **X** and **O**. 
3. Players take turns putting their marks in empty squares.
4. The first player to get 3 of their marks in a row (up, down, across, or diagonally) is the winner.
5. When all 9 squares are full, the game is over. If no player has 3 marks in a row, the game ends in a tie.

## ✨ Features
- **Local Multiplayer**: Play against a friend on the same machine.
- **Smart Reset**: Clear the board and start a new round with one input.
- **Win Detection**: Automatically highlights the winning row/column.
- **Win Tracking**: Keeps a scoreboard of your wins, losses, and draws.

## 🛠️ Tech Stack
- **Language**: C++
- **Dependencies**: Standard I/O and String handling libraries only (no external game engines).
- **Input Format**: 
    - **Names**: `First Last` (Full names required; alphabet characters only).
    - **Moves**: `1-9` (Corresponds to the specific grid layout below).

    ```
    +---+---+---+
    | 7 | 8 | 9 |
    +---+---+---+
    | 6 | 1 | 2 |
    +---+---+---+
    | 5 | 4 | 3 |
    +---+---+---+
    ```

## 🚀 Quick Start
If you have the files locally and the g++ compiler, first navigate to the file location and just run `g++ ticTacToeFunctions.cpp ticTacToeDriver.cpp -o [your_desired_file_name].exe`.

To clone and run locally:
```bash
git clone https://github.com
cd tic-tac-toe
