#include <math.h>
#include <stdio.h>
#include "placement.h"

int size_x, size_y;

// Basicaly a duplicate of gaussian function from the `/Board/gaussian.c`, but with minor tweaks
float gaussian_point(int x, int y, int rel_x, int rel_y)
{
    float e  = 2.71828;
    float a  = 0.65;          // Tweakable
    float pi = 3.14159;
    float fraq_x = fabsf((float)x - (float)rel_x);
    float fraq_y = fabsf((float)y - (float)rel_y);

    float exponent = ( -1 * (pow(fraq_x, 2) + (pow(fraq_y, 2)) ) ) / (2 * a * a);

    return pow(e, exponent) / sqrt(pi * a * a);                             // Value between (0, 1)
}

float calculate_heat(int rel_x, int rel_y, char board[size_x][size_y])
{
    float weight, sum = 0, mean;
    char fish;
    for (int y = 0; y < size_y; y++)
    {
        for (int x = 0; x < size_x; x++)
        {
            // For every point on the board
            // Calculate gaussian value of every other point on the board
            // relative to the original one
            // multiplied by the weight (number of fish) which is
            // fish / 3 -> this way 3 fish have weight of 1, 2 = 0.67 and 1 =  0.33
            // And get the mean of them all
            fish = board[x][y];
            if (board[rel_x][rel_y] != '1')         // Penguin has to be placed on a tile with 1 fish
                return 0;
            switch (fish)
            {
                case '1': weight = 0.33; break;
                case '2': weight = 0.67; break;
                case '3': weight = 1;    break;
                default:  weight = 0;           // Sea or player
            }
            sum += gaussian_point(x, y, rel_x, rel_y) * weight;
        }
    }
    mean = sum / ((float)size_x * (float)size_y);
    return mean;
}

struct BestPlace heat_placement()
{
    struct BestPlace bestPlace;

    // Input board
    FILE* file_in;
    file_in = fopen("board.txt", "r");
    fscanf(file_in, "%d %d", &size_x, &size_y);
    char board[size_x][size_y];
    float heatmap[size_x][size_y];
    float max_heat = 0.0;
    int h_x, h_y;
    fgetc(file_in);             // Skip newline character after board sizes
    for (int y = 0; y < size_y; y++)
    {
        for (int x = 0; x < size_x; x++)
            board[x][y] = fgetc(file_in);
        fgetc(file_in);         // Skip newline after a board row
    }

    // Generate heatmap
    for (int y = 0; y < size_y; y++)
    {
        for (int x = 0; x < size_x; x++)
        {
            heatmap[x][y] = calculate_heat(x, y, board);
            if (heatmap[x][y] > max_heat)
            {
                max_heat = heatmap[x][y];
                h_x = x;
                h_y = y;
            }
        }
    }
    // Get heatmap highest values
    bestPlace.x = h_x;
    bestPlace.y = h_y;
    
    // Print out the heatmap, with the highest value marked in red
    /*
     * for (int y = 0; y < size_y; y++)
     * {
     *     for (int x = 0; x < size_x; x++)
     *     {
     *         if (x == h_x && y == h_y)
     *             printf("\033[0;31m%.1f\033[0m ", heatmap[x][y] * 1500);
     *         else
     *             printf("%.1f ", heatmap[x][y] * 1500);
     *     }
     *     printf("\n");
     * }
     * printf("\n%d %d\n", h_x + 1, h_y + 1);
     * printf("%d %d", bestPlace.x, bestPlace.y);
     */
    fclose(file_in);

    return bestPlace;
}
