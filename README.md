# Tic-Tac-Toe Game (Console-based)

This is a simple **Tic-Tac-Toe** game implemented in **C++**. It allows two players to take turns and play the classic game on a 3x3 grid. The game supports input validation, player switching, and displays the winner or draw when the game ends.

## Features
- **Two-player mode**: Two players can play the game alternately.
- **Win condition**: The game checks for horizontal, vertical, and diagonal wins.
- **Draw condition**: The game ends in a draw if all spots on the board are filled without a winner.
- **Player names**: Players can input their names.
- **Play Again**: After the game ends, you have the option to play again.

## Requirements
- **C++ Compiler** (e.g., GCC or Clang)
- **C++11 or higher** for compatibility

## How to Play
1. Clone this repository or download the source files to your computer.
2. Compile the source code:
   ```bash
   g++ -o TicTacToe TicTacToe.cpp
   ```
3. Run the compiled program:
   ```bash
   ./TicTacToe
   ```

4. Follow the prompts to input your names and make your moves. The game will display the board after each move.
5. After the game ends (either by win or draw), you will be prompted to play again.

## Example of Gameplay

```
Enter name of Player 1: Alice
Enter name of Player 2: Bob

Player Alice
 | 1 | 2 | 3 |
 | 4 | 5 | 6 |
 | 7 | 8 | 9 |

Enter number where you want to put X: 1

Player Bob
 | X | 2 | 3 |
 | 4 | 5 | 6 |
 | 7 | 8 | 9 |

Enter number where you want to put O: 5

...

Player Alice has won!!!
Play Again?(Y/N): Y
```

## Code Explanation
- **Board Representation**: The board is a 3x3 grid represented as a 2D array (`board[3][3]`).
- **Player Management**: The game keeps track of the players' names using a `map<char, string> player` where `X` and `O` are the keys for the two players.
- **Input Handling**: Players input a number (1-9) to place their mark on the board. If the position is already occupied, the player is prompted to enter another number.
- **Win Check**: The game checks if either player has won after each move by checking rows, columns, and diagonals.
- **Reset Functionality**: After the game ends, you can reset the board and start a new game.
