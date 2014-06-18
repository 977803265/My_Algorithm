#include <stdlib.h>
#include "../lib/graph.h"
#include "../lib/priority_queue.h"
#include "graph_alg.h"

const int V = 9;
int main() {
	int** adj_mat;
	int* dist;
	int i, j;
	adj_mat = (int **) malloc(sizeof(int *) * V);
	for (i = 0; i < V; i++) {
		adj_mat[i] = (int *) malloc(sizeof(int) * V);
	}

	int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
	                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
	                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
	                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
	                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
	                      {0, 0, 4, 0, 10, 0, 2, 0, 0},
	                      {0, 0, 0, 14, 0, 2, 0, 1, 6},
	                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
	                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
	                     };

	for (i = 0; i < V; i++) {
		for (j = 0; j < V; j++) {
			adj_mat[i][j] = graph[i][j];
		}
	}
	dist = malloc(sizeof(int) * V);
	Dijkstra(adj_mat, V, 0, dist);
	Dijkstra_print(0, dist, V);
}
