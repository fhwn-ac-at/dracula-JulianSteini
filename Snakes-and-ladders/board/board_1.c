#include "board.h"
#include <stdlib.h>

// First small test board

board_t *create_board1(void)
{
    board_t *board = malloc(sizeof(board_t));
    if (!board) return NULL;

    board->rows = 5;
    board->cols = 5;
    board->num_snakes = 1;
    board->num_ladders = 1;

    // Snake: 23 -> 7
    board->snakes = malloc(sizeof(snake_t) * board->num_snakes);
    board->snakes[0].start = 23;
    board->snakes[0].end = 7;

    // Ladder: 3 -> 17
    board->ladders = malloc(sizeof(ladder_t) * board->num_ladders);
    board->ladders[0].start = 3;
    board->ladders[0].end = 17;

    return board;
}
