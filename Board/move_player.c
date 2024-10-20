#include "board_functions.h"
#include <stdbool.h>
#include <stdio.h>

void move_player(char player, char direction)
{
    FILE* file;
    file = fopen("board.txt", "r");

    int size_x, size_y;
    fscanf(file, "%d %d", &size_x, &size_y);

    struct Player p;
    p.ID = player;

    // Moving on - AU, AD, AL, AR
  }
