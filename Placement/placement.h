#ifndef PLACE_H
#define PLACE_H

struct BestPlace
{
    int x;
    int y;
};

struct BestPlace heat_placement();

void place_player(char Player, int player_x, int player_y);

#endif
