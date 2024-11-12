#include <stdio.h>
#include <stdlib.h>
#include "board_functions.h"

void print_board()
{
    FILE* file_in;
    file_in = fopen("board.txt", "r");

    int size_x, size_y;
    char input;
    fscanf(file_in, "%d %d", &size_x, &size_y);
    fgetc(file_in);

    // Board printing
    // First line with the coordinates of x
    printf("   ");
    for (int x = 0; x < size_x; x++)
        printf("%-3d", x+1);
    printf("\n");
    
    for (int y = 0; y < size_y; y++)
    {
        // Coordinates of y
        printf("%-3d", y+1);
        for (int x = 0; x < size_x; x++)
        {
            input = fgetc(file_in);
            if (input == '\n')
            {
                x--;
                continue;
            }
            if (input == '0')       // Print sea with cyan background and bold 0's
                printf("\033[46;1m%-3c\033[0m", input);
            else if (input >= 'A')  // Print players as red bold text
                printf("\033[31;1m%-3c\033[0m", input);
            else                    // Print land as green text
                printf("\033[32m%-3c\033[0m", input);
            /* printf("%-3c", input); */
        }
        printf("\n");
    }
}

void save_board(char *board, int size_x, int size_y)
{
    FILE* file;
    file = fopen("board.txt", "w");
    fprintf(file, "%d %d\n", size_x, size_y);
    for (int y = 0; y < size_y; y++)
    {
        for (int x = 0; x < size_x; x++)
            fprintf(file, "%c", *((board + x * size_y) + y));
        if (y != size_y)
            fprintf(file, "\n");
    } 
    fclose(file);
}

void generate_board()
{
    // Input board size and generation seed
    int x, y, size_x, size_y;
    int SEED;
    printf("Input board size X and Y: ");
    scanf("%d %d", &size_x, &size_y);
    printf("Input the seed for board generation: ");
    scanf("%d", &SEED);

    // File pointer
    FILE* file_out;
    file_out =  fopen("board.txt", "w");    // Opening the 'board.txt' file with write permissions. Overwrites the existing file;

    if (ferror(file_out))
    {
        printf("Error while opening the file.\nExiting...");
        return;
    }

    fprintf(file_out, "%d %d\n", size_x, size_y);

    for (y = 0; y < size_y; y++)
    {
        for (x = 0; x < size_x; x++)
            perlin_gen(x, y, size_x, size_y, SEED) > 0.1
                ? fprintf(file_out, "%d", rand() % 3 + 1)      // Number of fish - from 1 to 3
                : fprintf(file_out, "0");

        if (y != size_y - 1)
            fputs("\n", file_out);
    }
    printf("Board generated!\n");
    fclose(file_out);
}
