#include "Board/board_functions.h"
#include "Placement/placement.h"
#include <stdio.h>

int main()
{
    generate_board();
    /* char move[2] = "AU"; */
    /* move_player(move[0], move[1]); */
    print_board();
    struct BestPlace bestPlace = heat_placement();
    printf("%d %d\n", bestPlace.x, bestPlace.y);
    return 0;
}
