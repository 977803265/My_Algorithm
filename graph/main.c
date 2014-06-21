#include <stdlib.h>
#include "../lib/graph.h"

#include "graph_alg.h"

const int V = 5;
int main() {
	int* adj_mat;
	int parent[V];
	int i, j;


	int** graph = malloc(sizeof(int*) * V);
	for (i = 0; i < V; i++) {
		graph[i] = malloc(sizeof(int) * V);
	}
	int g[V][V] = {{0, 2, 0, 6, 0},
		{2, 0, 3, 8, 5},
		{0, 3, 0, 0, 7},
		{6, 8, 0, 0, 9},
		{0, 5, 7, 9, 0},
	};
	for (i = 0; i < V; i++) {
		for (j = 0; j < V; j++) {
			graph[i][j] = g[i][j];
		}
	}
 
	Prim(graph, V, parent);
	print_MST(parent, V, graph);
}
