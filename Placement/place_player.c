#include "placement.h"
#include <stdio.h>

int place_player(char Player, int player_x, int player_y)
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

    // The penguins can be only placed on a tile with 1 fish
    if (board[player_x][player_y] != '1')
    {
        printf("The penguin has to be placed on a tile with only 1 fish. Please retry.\n");
        return 0;
    }
    
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
    return 1;
}
