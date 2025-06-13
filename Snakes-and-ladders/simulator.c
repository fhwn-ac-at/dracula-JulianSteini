#include "simulator.h"
#include <stdlib.h>

simulation_result simulate_game(const board_t *board, int dice_sides, int max_steps)
{
    int pos = 0;
    int steps = 0;
    int goal = get_board_size(board);

    simulation_result result = {
        .rolls_taken = 0,
        .max_position = 0,
        .reached_goal = 0,
        .roll_count = 0,
        .snake_hits = calloc(board->num_snakes, sizeof(int)),
        .ladder_hits = calloc(board->num_ladders, sizeof(int)),
    };

    while (steps < max_steps)
    {
        int roll = (rand() % dice_sides) + 1;

        if (pos + roll <= goal)
        {
            pos += roll;
            // Store current die roll in result sequence
            if (result.roll_count < MAX_ROLLS_PER_GAME)
            {
                result.roll_sequence[result.roll_count++] = roll;
            }
            // Check if player landed on ladder
            for (int i = 0; i < board->num_ladders; ++i)
            {
                if (board->ladders[i].start == pos)
                {
                    result.ladder_hits[i]++;
                    pos = board->ladders[i].end;
                    break;
                }
            }

            // Check if player landed on snake
            for (int i = 0; i < board->num_snakes; ++i)
            {
                if (board->snakes[i].start == pos)
                {
                    result.snake_hits[i]++;
                    pos = board->snakes[i].end;
                    break;
                }
            }
        }

        steps++;

        if (pos >= goal)
        {
            result.reached_goal = 1;
            break;
        }
    }

    result.rolls_taken = steps;
    result.max_position = pos;
    return result;
}
