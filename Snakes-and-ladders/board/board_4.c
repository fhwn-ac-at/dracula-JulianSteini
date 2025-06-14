#include "board.h"
#include <stdlib.h>

// no ladders, many snakes (very hard for small dice)

board_t *create_board4(void)
{
    board_t *board = malloc(sizeof(board_t));
    if (!board) return NULL;

    board->rows = 5;
    board->cols = 5;
    board->num_snakes = 8;
    board->num_ladders = 0;

    // Allocate memory for snakes
    board->snakes = malloc(sizeof(snake_t) * board->num_snakes);

    // Snake 1: 3 -> 1
    board->snakes[0].start = 3;
    board->snakes[0].end = 1;

    // Snake 2: 6 -> 2
    board->snakes[1].start = 6;
    board->snakes[1].end = 2;

    // Snake 3: 9 -> 4
    board->snakes[2].start = 9;
    board->snakes[2].end = 4;

    // Snake 4: 11 -> 5
    board->snakes[3].start = 11;
    board->snakes[3].end = 5;

    // Snake 5: 14 -> 7
    board->snakes[4].start = 14;
    board->snakes[4].end = 7;

    // Snake 6: 18 -> 10
    board->snakes[5].start = 18;
    board->snakes[5].end = 10;

    // Snake 7: 21 -> 13
    board->snakes[6].start = 21;
    board->snakes[6].end = 13;

    // Snake 8: 24 -> 16
    board->snakes[7].start = 24;
    board->snakes[7].end = 16;

    // No ladders
    board->ladders = NULL;

    return board;
}
