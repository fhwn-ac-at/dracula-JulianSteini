#ifndef GRAPH_H
#define GRAPH_H

#include "board.h"

// Single edge
typedef struct edge
{
    int to;                // Target node
    struct edge *next;     // Next edge
} edge_t;

// Full graph
typedef struct
{
    int num_nodes;         // Number of nodes
    edge_t **adj_list;     // Array of adjacency lists
} graph_t;

// Build graph based on user specifications
graph_t *build_graph(const board_t *board, int dice_sides);

// for debugging and visualization
void print_graph(const graph_t *graph);

void free_graph(graph_t *graph);

#endif
