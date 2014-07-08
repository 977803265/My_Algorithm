/*
 * Prim MST algorithm
 * implementation using heap data structure
 * referred from: http://www.geeksforgeeks.org/greedy-algorithms-set-5-prims-minimum-spanning-tree-mst-2/
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../lib/priority_queue.h"

const int infinite = 55535;
/*
 * pseudocode
 *  -mstSet={s}
 *  -T={}
 *  -while mstSet != V
 *   -find minimun crossing edge (u,w) with u from mstSet and w from V-mstSet
 *   -add w to mstSet
 *   -add edge (u,w) to T
 *
 */

void
Prim(int** graph, int n, int parent[]) {
	int i, u, w, k;
	bool* mstSet = malloc(sizeof(bool) * n);
	int* key = malloc(sizeof(int) * n);
	struct PQueue* hp = create_pqueue(n);
	
	// init
	for (i = 0; i < n; i++) {
		mstSet[i] = false;
		insert(hp, i, infinite);
		key[i] = infinite;
	}

	decrease_key(hp, 0, 0);
	key[0] = 0;
	parent[0] = -1;

	// find MST
	for (i = 0; i < n; i++) {
		extract_min(hp, &u, &k);
		mstSet[u] = true;

		for (w = 0; w < n; w++) {
			if (!mstSet[w] && graph[u][w] != 0 && key[w] > graph[u][w]) {
				decrease_key(hp, w, graph[u][w]);
				key[w] = graph[u][w];
				parent[w] = u;
			}
		}
	}
}

void
print_MST(int parent[], int n, int** graph) {
	int i;
	printf("Edge   Weight\n");
	for (int i = 1; i < n; i++) {
		printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
	}
	printf("\n");
}
