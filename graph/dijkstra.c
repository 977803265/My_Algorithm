#include "dijkstra.h"
#include "../lib/priority_queue.h"
#include <stdbool.h>
#include <stdlib.h>

/*
 * dijkstra algorithm implementation
 * using priority queue
 *
 */
const int infinite = 55536;
void Dijkstra(int** adj_matrix, int num, int s, int dist[]);

void 
Dijkstra(int** adj_matrix, int num, int start, int dist[]) {
	int i, u, v;
	int id, key;
	int* access = malloc(sizeof(bool) * num);
	struct PQueue* pq = create_pqueue(num);
	
	for (i = 0; i < num; i++) {
		if (i == start) {
			dist[i] = 0;
		}
		else {
			dist[i] = infinite;
		}
		access[i] = false;
		insert(pq, i, dist[i]);
	}

	while((i++) < num) {
		extract_min(pq, &u, &key);
		access[u] = true;
		for (v = 0; v < num; v++) {
			if (!access[v] && adj_matrix[u][v] && dist[v] > dist[u] + adj_matrix[u][v]) {
				dist[v] = dist[u] + adj_matrix[u][v];
				decrease_key(pq, v, dist[v]);
			}
		}
	}
}
