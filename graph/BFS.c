/*
 * breadth first search
 * using array queue
 */
#include "../lib/graph.h"
#include "../lib/queue.h"
void
BFS(struct Graph* g, int start) {
	bool* V = malloc(sizeof(bool) * g->no);
	int i;
	for (i = 0; i < g->no; i++) {
		V[i] = false;
	}
	int id;
	struct Queue* q = create_queue(20);
	struct Node* node; 

	enqueue(q, start);
	V[start] = true;

	while (!is_empty(q)) {
		dequeue(q, &id);
		printf("->%d", id);
		node = g->head[id].next;
		for (node = g->head[id].next; node != NULL; node = node->next) {
			if (!V[node->id]) {
				enqueue(q, node->id);
				V[node->id] = true;
			}			
		}
	}

	printf("\n");
	free(V);
	destroy_queue(q);
}
