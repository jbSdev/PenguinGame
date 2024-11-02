#include "placement.h"
#include <stdio.h>

void place_player(char Player, int player_x, int player_y)
{
    FILE* file;
    file = fopen("board.txt", "r");
    int size_x, size_y;
    fscanf(file, "%d %d", &size_x, &size_y);
    fgetc(file);
    char board[size_x][size_y];
    for (int y = 0; y < size_y; y++)
    {
        for (int x = 0; x < size_x; x++)
            board[x][y] = fgetc(file);
        fgetc(file);
    }
    fclose(file);
    
    file = fopen("board.txt", "w");
    fprintf(file, "%d %d\n", size_x, size_y);
    for (int y = 0; y < size_y; y++)
    {
        for (int x = 0; x < size_x; x++)
        {
            player_x == x && player_y == y
                ? fprintf(file, "%c", Player)
                : fprintf(file, "%c", board[x][y]);
        }
        if (y != size_y)
            fprintf(file, "\n");
    } 
    fclose(file);
}
