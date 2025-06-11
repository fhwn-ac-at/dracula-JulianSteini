#ifndef BOARD_H
#define BOARD_H

// Struct for snakes / ladders
typedef struct
{
    int start;
    int end;
} snake_t, ladder_t;

// Struct for board
typedef struct
{
    int rows;
    int cols;
    int num_snakes;
    int num_ladders;
    snake_t *snakes;
    ladder_t *ladders;
} board_t;

board_t *load_board(int board_number);

void free_board(board_t *board);

int get_board_size(const board_t *board);

#endif
