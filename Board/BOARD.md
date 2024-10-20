#Board

The main board generation file is `board.c`. It has three main functions:
 - `generate_board()`
 - `update_board()`
 - `print_board()`

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

##### Generate_board()

**`Generate_board()`** creates a new game board and inputs it into `board.txt` file.

Generation is based on configured implementation of Perlin Noise and Gaussian distribution, in order to create a island around the middle of the map.

The function does not take initial code input, but asks the user to input:
 - Size of the board (X and Y) 
 - Seed based on which the board will be created.

The size of the board is not advised to be over 50x50, because the lakes in the middle of the island become too big.

