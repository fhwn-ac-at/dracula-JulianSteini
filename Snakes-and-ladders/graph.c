#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

// Create a new edge and add it to the front of the list
static edge_t *add_edge(edge_t *head, int to)
{
    edge_t *new_edge = malloc(sizeof(edge_t));
    if (!new_edge) return NULL;

    new_edge->to = to;
    new_edge->next = head;
    return new_edge;
}

// Applies snakes and ladders to the position, returns new position
static int apply_snakes_ladders(const board_t *board, int pos)
{
    for (int i = 0; i < board->num_ladders; ++i)
    {
        if (board->ladders[i].start == pos)
        {
            return board->ladders[i].end;
        }
    }
    for (int i = 0; i < board->num_snakes; ++i)
    {
        if (board->snakes[i].start == pos)
        {
            return board->snakes[i].end;
        }
    }
    return pos;
}

graph_t *build_graph(const board_t *board, int dice_sides)
{
    int goal = get_board_size(board);
    graph_t *graph = malloc(sizeof(graph_t));
    if (!graph) return NULL;

    graph->num_nodes = goal + 1;
    graph->adj_list = calloc(graph->num_nodes, sizeof(edge_t*));
    if (!graph->adj_list)
    {
        free(graph);
        return NULL;
    }

    // For each field from 0 to goal - 1 (since goal node has no outgoing edges)
    for (int i = 0; i < goal; ++i)
    {
        for (int roll = 1; roll <= dice_sides; ++roll)
        {
            int next = i + roll;
            if (next > goal) continue;  // overshooting the goal is not allowed

            // Apply snake or ladder if needed
            next = apply_snakes_ladders(board, next);

            // Add edge from current field to resulting field
            graph->adj_list[i] = add_edge(graph->adj_list[i], next);
        }
    }

    return graph;
}

// Print the graph for debugging
void print_graph(const graph_t *graph)
{
    printf("\nGraph (Adjacency List):\n");
    for (int i = 0; i < graph->num_nodes; ++i)
    {
        printf("%2d: ", i);
        edge_t *e = graph->adj_list[i];
        while (e)
        {
            printf("-> %d ", e->to);
            e = e->next;
        }
        printf("\n");
    }
}

// free all memory for graph
void free_graph(graph_t *graph)
{
    if (!graph) return;
    for (int i = 0; i < graph->num_nodes; ++i)
    {
        edge_t *e = graph->adj_list[i];
        while (e)
        {
            edge_t *next = e->next;
            free(e);
            e = next;
        }
    }
    free(graph->adj_list);
    free(graph);
}
