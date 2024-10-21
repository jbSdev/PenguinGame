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

    // Input a board into the 2D array
    char board[size_x][size_y];
    char newline;
    fscanf(file, "%c", &newline);
    for (int y = 0; y < size_y; y++)
    {
        for (int x = 0; x < size_x; x++)
        {
            board[x][y] = fgetc(file);
            if (board[x][y] == p.ID)
            {
                p.x = x;
                p.y = y;
            }
        }
        fscanf(file, "%c", &newline);
    }
    fclose(file);
    printf("%d %d\n", p.x, p.y);

    // Moving the player
    switch (direction)
    {
        case 'U':
            if (p.y == 0)
            {
                printf("Player %c tried to move out of the map.", p.ID);
                break;
            }
            else if (board[p.x][p.y - 1] == '0')
            {
                printf("Player %c tried to move into the sea.", p.ID);
                break;
            }
            
            board[p.x][p.y - 1] = p.ID;
            board[p.x][p.y] = '0';
            break;
        case 'D':
            if (p.y == size_y - 1)
            {
                printf("Player %c tried to move out of the map.", p.ID);
                break;
            }
            else if (board[p.x][p.y + 1] == '0')
            {
                printf("Player %c tried to move into the sea.", p.ID);
                break;
            }
            
            board[p.x][p.y + 1] = p.ID;
            board[p.x][p.y] = '0';
            break;
        case 'L':
            if (p.x == 0)
            {
                printf("Player %c tried to move out of the map.", p.ID);
                break;
            }
            else if (board[p.x - 1][p.y] == '0')
            {
                printf("Player %c tried to move into the sea.", p.ID);
                break;
            }
            
            board[p.x - 1][p.y] = p.ID;
            board[p.x][p.y] = '0';
            break;       
        case 'R':
            if (p.y == size_x - 1)
            {
                printf("Player %c tried to move out of the map.", p.ID);
                break;
            }
            else if (board[p.x + 1][p.y] == '0')
            {
                printf("Player %c tried to move into the sea.", p.ID);
                break;
            }
            
            board[p.x + 1][p.y] = p.ID;
            board[p.x][p.y] = '0';
            break;
    }

    save_board(&board[0][0], size_x, size_y); 
}
