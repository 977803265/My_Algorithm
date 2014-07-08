#include <stdlib.h>
#include <assert.h>
#include "../dac/binary_search.h"
#include "../lib/weighted_graph.h"
#include "../sort/sort.h"
#include "../lib/union_find.h"

/*
 * since edge array is a struct array,
 * we cannot directly use sort function on it.
 * thus, my way is to firstly extract weights of all edges
 * into a integer array and then sort it. After that, we use
 * binary search to find each weight correct position (assume
 * all edges weight are different.) and put each edge object
 * to the same entry in a new struct array. 
 */
void
kruskal(struct Graph* graph, int parent[], int num) {
	int i;
	int index;
	int t;

	struct Edge result[graph->V - 1];
	struct Edge* sorted_edge = malloc(sizeof(struct Edge) * graph->E);
	int* weight = malloc(sizeof(int) * graph->E);

	// extract weights 
	for (i = 0; i < graph->E; i++) {
		weight[i] = graph->edge[i].weight;
	}

	// sort it
	quick(weight, graph->E);

	// get correct position of each edge and put it into new array
	// running time: O(ElogE)
	for (i = 0; i < graph->E; i++) {
		index = binary_search(weight, graph->E, graph->edge[i].weight);
		assert(index != -1); // all edges should be successfully found
		sorted_edge[index] = graph->edge[i];
	}

	struct Unionfind* set = create_ufind(graph->V);
	for (i = 0; i < graph->V; i++) {
		make_set(set, i);
	}

	// construct MST
	for (i = 0, t = 0; i < graph->E && t < (graph->V - 1); i++) {
		if (find_set(set, sorted_edge[i].src) == find_set(set, sorted_edge[i].dest)) {
			// add this edge will lead to cycle
			continue;
		}

		union_set(set, sorted_edge[i].src, sorted_edge[i].dest);
		result[t] = sorted_edge[i];
		parent[t] = sorted_edge[i].src;
		t++;
	}
	printf("Following are the edges in the constructed MST\n");
	for (i = 0; i < t; ++i) {
		printf("%d -- %d == %d\n", result[i].src, result[i].dest,
				result[i].weight);
	}
}


