#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "board.h"

#define MAX_ROLLS_PER_GAME 1000

typedef struct
{
    int rolls_taken;
    int max_position;
    int reached_goal;

    int roll_sequence[MAX_ROLLS_PER_GAME];
    int roll_count;

    int *snake_hits;
    int *ladder_hits;
} simulation_result;

simulation_result simulate_game(const board_t *board, int dice_sides, int max_steps);

#endif
