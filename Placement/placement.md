# Placement

The placement is based on the tactic used by the SI.

### BestPlace struct

The structure has two values - x and y, in which we can save the coordinates of the best spawn point.

##### **`place_player()`**

Function that places player on a board, with the input:
 - char Player
 - int X, Y - coordinates to place the player

##### **Heat based**

Finds the place on the board with the highest amount of fish around.

The function needs tinkering, to find the best values for it's most optimal (logical) functionality

