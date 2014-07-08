/*
 * referred: http://www.geeksforgeeks.org/ford-fulkerson-algorithm-for-maximum-flow-problem/
 *
 * since we use BFS to find augmenting path,
 * then running time is O(mn(m+n))
 */
#include <stdbool.h>
#include "../../lib/queue.h"

const int V = 5;
const int INFINTE = 55535;

int
min(int a, int b ) {
	return a > b? a : b;
}
bool
BFS(int rGraph[V][V], int s, int t, int pi[]) {
	int i;
	int u, v;
	bool visited[V]; 
	struct Queue* q = create_queue(V);
	enqueue(q, s);
	pi[s] = -1;
	for (i = 0; i < V; i++) {
		visited[i] = false;
	}	

	while (!is_empty(q)) {
		dequeue(q, &u);
		visited[u] = true;

		for (v = 0; v < V; v++) {
			if (rGraph[u][v] > 0 && visited[v] == false) {
				enqueue(q, v);
				pi[v] = u;
			}
		}
	}
	// note we need to inform whether we find a augmenting path
	return (visited[t] == true);
}

int FordFulkerson(int graph[V][V], int s, int t) {
	int u, v;
	int parent[V];
	int rGraph[V][V];
	int max_flow, path_flow;

	for (u = 0; u < V; u++) {
		for (v = 0; v < V; v++) {
			rGraph[u][v] = graph[u][v];
		}
	}

	max_flow = 0;
	// find augmenting path P each time
	while (BFS(rGraph, s, t, parent)) {
		// find mininum residual capacity of the path P
		path_flow = INFINTE;
		for (v = t; v >= s; v = parent[v]) {
			u = parent[v];
			path_flow = min(path_flow, rGraph[u][v]);
		}

		for (v = t; v >= s ; v = parent[v]) {
			u = parent[v];
			rGraph[u][v] -= path_flow; 
			rGraph[v][u] += path_flow;
		}
		max_flow += path_flow;
	}

	return max_flow;
}
