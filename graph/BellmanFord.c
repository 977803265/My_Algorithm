/*
 * Bellman Ford single source shortest paths algorithm
 */
#include <stdio.h>
#include <stdbool.h>

const int infinite = 55535;
bool
BellmanFord(int** graph, int num, int start, int* dist) {
	int i, v, u;
	// init
	for (i = 0; i < num; i++) {
		if (i == start) {
			dist[i] = 0;
		}
		else {
			dist[i] = infinite;
		}
	}

	// bellman ford relax
	for (i = 0; i < num - 1; i++) {
		for (v = 0; v < num; v++ ) {
			for (u = 0; u < num; u++) {
				if (graph[v][u] != 0 && dist[v] > dist[u] + graph[v][u]) {
					dist[v] = dist[u] + graph[v][u];
				}
			}
		}
	}

	// check negative cycle
	for (v = 0; v < num; v++ ) {
		for (u = 0; u < num; u++) {
			if (graph[v][u] != 0 && dist[v] > dist[u] + graph[v][u]) {
				return false;
			}
		}
	}
	return true;
}


void
BellmanFord_print(int start, int dist[], int num) {
	int i;
	printf("source: %d\n", start);
	for (i = 0; i < num; i++) {
		printf("%d\t", dist[i]);
	}
	printf("\n");
}
