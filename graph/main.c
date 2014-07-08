#include <stdlib.h>
#include "../lib/weighted_graph.h"
#include "graph_alg.h"

const int V = 5;
int main() {
	int pi[V];
	struct Graph* g = create_graph(4, 5);

	g->edge[0].src = 0;
	g->edge[0].dest = 1;
	g->edge[0].weight = 10;


	g->edge[1].src = 0;
	g->edge[1].dest = 2;
	g->edge[1].weight = 6;

	g->edge[2].src = 0;
	g->edge[2].dest = 3;
	g->edge[2].weight = 5;

	g->edge[3].src = 1;
	g->edge[3].dest = 3;
	g->edge[3].weight = 15;
	
	g->edge[4].src = 2;
	g->edge[4].dest = 3;
	g->edge[4].weight = 4;

	kruskal(g, pi, V);
}
