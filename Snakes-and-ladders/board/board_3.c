#include "board.h"
#include <stdlib.h>

// (small) Impossible board for dice < 4

board_t *create_board3(void)
{
    board_t *board = malloc(sizeof(board_t));
    if (!board) return NULL;

    board->rows = 5;
    board->cols = 5;
    board->num_snakes = 3;
    board->num_ladders = 1;

    // Allocate memory for snakes
    board->snakes = malloc(sizeof(snake_t) * board->num_snakes);

    // Snake 1: 11 -> 4
    board->snakes[0].start = 11;
    board->snakes[0].end = 4;

    // Snake 2: 12 -> 6
    board->snakes[1].start = 12;
    board->snakes[1].end = 6;

    // Snake 3: 13 -> 2
    board->snakes[2].start = 13;
    board->snakes[2].end = 2;

    // Allocate Memory for ladders
    board->ladders = malloc(sizeof(ladder_t) * board->num_ladders);

    // Ladder 1: 3 -> 9
    board->ladders[0].start = 3;
    board->ladders[0].end = 9;

    return board;
}
