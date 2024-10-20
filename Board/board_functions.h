#ifndef BOARD_H
#define BOARD_H

float gaussian(int x, int y, int size_x, int size_y);
float perlin_gen(int x, int y, int size_x, int size_y, int seed_input);

void generate_board();
void update_board();

#endif
