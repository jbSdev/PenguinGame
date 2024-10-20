#ifndef BOARD_H
#define BOARD_H

float gaussian(int x, int y, int size_x, int size_y);
float perlin_gen(int x, int y, int size_x, int size_y, int seed_input);

void move_player(char player, char direction);

void generate_board();
void update_board(char move[2]);
void print_board();

struct Player
{
    char ID;
    int x;
    int y;
};

#endif
