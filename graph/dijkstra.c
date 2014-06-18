#include "../lib/priority_queue.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

/*
 * dijkstra algorithm implementation
 * using priority queue
 *
 */
const int infinite = 55535;

void 
Dijkstra(int** adj_matrix, int num, int start, int dist[]) {
	int i, u, v;
	int id, key;
	bool* access = malloc(sizeof(bool) * num);
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

	for(i = 0; i < num; i++) {
		extract_min(pq, &u, &key);
		access[u] = true;
		for (v = 0; v < num; v++) {
			if (!access[v] && adj_matrix[u][v] && dist[v] > dist[u] + adj_matrix[u][v]) {
				dist[v] = dist[u] + adj_matrix[u][v];
				decrease_key(pq, v, dist[v]);
			}
		}
	}

	destroy_pqueue(pq);
	free(access);

}

void
Dijkstra_print(int start, int dist[], int num) {
	int i;
	printf("source: %d\n", start);
	for (i = 0; i < num; i++) {
		printf("%d\t", dist[i]);
	}
	printf("\n");
}
