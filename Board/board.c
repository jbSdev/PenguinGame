#include <stdio.h>
#include "perlin_gen.h"

int main()
{
    int x, y, size_x, size_y;
    int SEED;
    float out;
    printf("Input board size X and Y: ");
    scanf("%d %d", &size_x, &size_y);
    printf("Input the seed for board generation: ");
    scanf("%d", &SEED);

    for (y = 0; y < size_y; y++)
    {
        for (x = 0; x < size_x; x++)
        {
            out = perlin_gen(x, y, size_x, size_y, SEED);
            /* printf("%f ", out); */
            if (out > 0.1)
                printf("\x1b[36m@ ");
            else
                printf("\x1b[31m@ ");
        }
        printf("\n");
    }
}
