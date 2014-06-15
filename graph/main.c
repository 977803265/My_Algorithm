#include "graph.h"

const int vertice = 9;
int main() {
	struct Graph* g = create_graph(vertice);

	add_edge(g, 0, 7);

	add_edge(g, 0, 1);
	add_edge(g, 1, 2);
	add_edge(g, 2, 3);

	add_edge(g, 0, 4);
	add_edge(g, 4, 5);

	add_edge(g, 5, 6);

	add_edge(g, 8, 7);
//	add_edge(g, 3, 4);

	print_graph(g);

	RDFS(g, 8);

	destroy_graph(g);
}
