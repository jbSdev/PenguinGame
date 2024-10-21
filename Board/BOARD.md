#Board

The main board generation file is `board.c`. It has three main functions:
 - `generate_board()`
 - `update_board()`
 - `print_board()`
 - `save_board()`

### `Board.txt` file

The file contains a current state of the gameboard. It's format is as follows:

```
X Y             // Size of the board

0000000000      // Board state
0001213210      // 0    - empty tile ("Sea")    [unmovable onto]
001A121300      // 1-3  - tiles containing fish [movable onto]
00013B2000      // A-Z  - players
0000000000
```

##### generate_board()

**`generate_board()`** creates a new game board and inputs it into `board.txt` file.

Generation is based on configured implementation of Perlin Noise and Gaussian distribution, in order to create a island around the middle of the map.

The function does not take initial code input, but asks the user to input:
 - Size of the board (X and Y) 
 - Seed based on which the board will be created.

The size of the board is not advised to be over 50x50, because the lakes in the middle of the island become too big.

##### update_board()

**`update_board()`** moves a player on the board and saves the status of the game into `board.txt`.

It takes input consisting of two characters (separately), and moves a player accordingly. First character corresponds to a player [A...Z], second character corresponds to a direction of the movement [U - up, D - down, L - left, R - right].

If the player is trying to move into the sea, the state of the game will not change and the message will appear: *Player X tried to move out of the map.*

The same will happen when the player tries to move out of the map, but this time the message will be: *Player X tried to move out of the map.* 

##### print_board()

**`print_board()`** prints out the state of the game from `board.txt` into the console.

##### save_board()

**`save_board()`** saves the state of the game from an array into the `board.txt` file.

The function takes three values as input:
 - address of the beggining of the board (&board[0][0])
 - width of the board
 - height of the board
