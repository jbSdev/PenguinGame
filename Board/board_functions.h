#ifndef BOARD_H
#define BOARD_H

float gaussian(int x, int y, int size_x, int size_y);
float perlin_gen(int x, int y, int size_x, int size_y, int seed_input);

void move_player(char player, char direction);

void generate_board();
void print_board();
void save_board(char *board, int size_x, int size_y);

struct Player
{
    char ID;
    int x;
    int y;
};

#endif
