#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board/board.h"
#include "simulator.h"
#include "graph.h"

// show information about chosen board
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
    srand((unsigned int) time(NULL));   // random seed for dice rolls

    int board_num;

    printf("Choose a board (1 - 4): ");
    if (scanf("%d", &board_num) < 1 || board_num > 4)
    {
        fprintf(stderr, "Invalid input. Exiting.\n");
        return EXIT_FAILURE;
    }

    // load selected board
    board_t *board = load_board(board_num);
    if (!board)
    {
        fprintf(stderr, "Failed to load board.\n");
        return EXIT_FAILURE;
    }

    print_board_info(board);

    int dice_sides = 6;
    printf("Choose number of die sides (default = 6): ");
    scanf("%d", &dice_sides);
    if (dice_sides <= 0)
    {
        dice_sides = 6;
    }

    graph_t *graph = build_graph(board, dice_sides);
    // print_graph(graph); // show graph
    free_graph(graph);

    // simulation parameters
    int simulations = 1000;
    int max_steps = 500;

    printf("\nRunning %d simulations...\n", simulations);

    // tracking statistics
    int total_rolls = 0;
    int wins = 0;

    int *snake_total = calloc(board->num_snakes, sizeof(int));
    int *ladder_total = calloc(board->num_ladders, sizeof(int));

    int min_rolls = max_steps + 1;
    int *shortest_sequence = NULL;
    int shortest_count = 0;

    // run simulation multiple times
    for (int i = 0; i < simulations; i++)
    {
        simulation_result result = simulate_game(board, dice_sides, max_steps);
        if (result.reached_goal)
        {
            wins++;
            total_rolls += result.rolls_taken;

            // Store new shortest sequence
            if (result.rolls_taken < min_rolls)
            {
                free(shortest_sequence);  // free previous stored sequence
                shortest_count = result.roll_count;
                min_rolls = result.rolls_taken;
                shortest_sequence = malloc(sizeof(int) * shortest_count);
                for (int j = 0; j < shortest_count; ++j)
                {
                    shortest_sequence[j] = result.roll_sequence[j];
                }
            }

            // accumulate snake and ladder usage
            for (int j = 0; j < board->num_snakes; ++j)
            {
                snake_total[j] += result.snake_hits[j];
            }
            for (int j = 0; j < board->num_ladders; ++j)
            {
                ladder_total[j] += result.ladder_hits[j];
            }
        }
        free(result.snake_hits);
        free(result.ladder_hits);
    }

    printf("\n Simulation Results: \n");
    printf("--------------------------\n");

    printf("Successful games: %d / %d\n", wins, simulations);
    if (wins > 0)
    {
        printf("Average rolls to win: %.2f\n", (float)total_rolls / wins);
    }
    else
    {
        printf("No games reached the goal.\n");
    }
    printf("--------------------------\n");

    if (min_rolls < max_steps + 1)
    {
        printf("\nShortest successful game: %d rolls\nSequence: ", min_rolls);

        for (int i = 0; i < shortest_count; ++i)
        {
            printf("%d ", shortest_sequence[i]);
        }
        printf("\n");
        free(shortest_sequence);
    }

    printf("\nSnake usage:\n");
    for (int i = 0; i < board->num_snakes; ++i)
    {
        double freq = 100.0 * snake_total[i] / simulations;

        printf("Snake %d (%d -> %d): %d times (%.2f%%)\n", i + 1, board->snakes[i].start, board->snakes[i].end, snake_total[i], freq);
    }

    printf("\nLadder usage:\n");
    for (int i = 0; i < board->num_ladders; ++i)
    {
        double freq = 100.0 * ladder_total[i] / simulations;

        printf("Ladder %d (%d -> %d): %d times (%.2f%%)\n", i + 1, board->ladders[i].start, board->ladders[i].end, ladder_total[i], freq);
    }

    free_board(board);

    return EXIT_SUCCESS;
}
