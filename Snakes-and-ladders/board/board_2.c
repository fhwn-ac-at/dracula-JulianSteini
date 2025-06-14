#include "board.h"
#include <stdlib.h>

// Large Board (10x10)

board_t *create_board2(void)
{
    board_t *board = malloc(sizeof(board_t));
    if (!board) return NULL;

    board->rows = 10;
    board->cols = 10;
    board->num_snakes = 6;
    board->num_ladders = 6;

    // Allocate memory for snakes
    board->snakes = malloc(sizeof(snake_t) * board->num_snakes);

    // Snake 1: 45 -> 7
    board->snakes[0].start = 45;
    board->snakes[0].end = 7;

    // Snake 2: 51 -> 10
    board->snakes[1].start = 51;
    board->snakes[1].end = 10;

    // Snake 3: 38 -> 20
    board->snakes[2].start = 38;
    board->snakes[2].end = 20;

    // Snake 4: 65 -> 54
    board->snakes[3].start = 65;
    board->snakes[3].end = 54;

    // Snake 5: 97 -> 61
    board->snakes[4].start = 97;
    board->snakes[4].end = 61;

    // Snake 6: 91 -> 73
    board->snakes[5].start = 91;
    board->snakes[5].end = 73;

    // Allocate Memory for ladders
    board->ladders = malloc(sizeof(ladder_t) * board->num_ladders);

    // Ladder 1: 5 -> 58
    board->ladders[0].start = 5;
    board->ladders[0].end = 58;

    // Ladder 2: 14 -> 49
    board->ladders[1].start = 14;
    board->ladders[1].end = 49;

    // Ladder 3: 42 -> 60
    board->ladders[2].start = 42;
    board->ladders[2].end = 60;

    // Ladder 4: 53 -> 72
    board->ladders[3].start = 53;
    board->ladders[3].end = 72;

    // Ladder 5: 64 -> 83
    board->ladders[4].start = 64;
    board->ladders[4].end = 83;

    // Ladder 6: 75 -> 94
    board->ladders[5].start = 75;
    board->ladders[5].end = 94;

    return board;
}
