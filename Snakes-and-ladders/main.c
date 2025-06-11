#include <stdio.h>
#include <stdlib.h>
#include "board/board.h"

void print_board_info(const board_t *board)
{
    if (!board) return;

    printf("\n--- Board Info ---\n");
    printf("Size: %d x %d (%d fields)\n", board->rows, board->cols, get_board_size(board));
    printf("Snakes: %d\n", board->num_snakes);
    printf("Ladders: %d\n", board->num_ladders);
    printf("-------------------\n");
}


int main(void)
{
    int board_num;

    printf("Choose a board (1 - 3): ");
    if (scanf("%d", &board_num) < 1 || board_num > 3)
    {
        fprintf(stderr, "Invalid input. Exiting.\n");
        return EXIT_FAILURE;
    }

    board_t *board = load_board(board_num);
    if (!board)
    {
        fprintf(stderr, "Failed to load board.\n");
        return EXIT_FAILURE;
    }

    print_board_info(board);
    free_board(board);

    return EXIT_SUCCESS;
}
