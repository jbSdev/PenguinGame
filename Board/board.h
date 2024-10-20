#include <stdio.h>
#include "perlin_gen.h"

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
                ? fprintf(file_out, "1 ")
                : fprintf(file_out, "0 ");

        fputs("\n", file_out);
    }
    printf("Board generated!\n");
}

void update_board()
{
    FILE* file_in;
    file_in = fopen("board.txt", "r");
    // Input size of the board
    int size_x, size_y;
    fscanf(file_in, "%d %d", &size_x, &size_y);
}
