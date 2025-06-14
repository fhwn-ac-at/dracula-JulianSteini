#include "board.h"
#include <stdlib.h>
#include <stdio.h>

// prebuilt boards
board_t *create_board1(void);
board_t *create_board2(void);
board_t *create_board3(void);

board_t *load_board(int board_number)
{
    switch (board_number)
    {
        case 1: return create_board1();
        case 2: return create_board2();
        case 3: return create_board3();
        default:
            fprintf(stderr, "Invalid board number: %d\n", board_number);
            return NULL;
    }
}

void free_board(board_t *board)
{
    if (!board) return;
    free(board->snakes);
    free(board->ladders);
    free(board);
}

int get_board_size(const board_t *board)
{
    if (!board) return 0;
    return board->rows * board->cols;
}
