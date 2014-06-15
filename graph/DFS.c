/*
 * deep first search implementation
 *
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "repre.h"
#include "../lib/stack.h"
//=================== recursive implementation using recursive call===================/
void help_DFS(struct Graph* g, int start, bool* V);
void 
RDFS(struct Graph* g, int start) {
	bool* V = malloc(sizeof(bool) * g->no);
	int i;

	for (i = 0; i < g->no; i++) {
		V[i] = false; // all vertice has not been accessed
	}
	help_DFS(g, start, V);
	printf("\n");
}

void
help_DFS(struct Graph* g, int start, bool* V) {
	V[start] = true; // set to being accessed
	printf("->%d", start);
	struct Node* node = g->head[start].next;
	while (node != NULL) {
		if (!V[node->id]) {
			help_DFS(g, node->id, V);
		}
		node = node->next;
	}
}

//=================== non-recursive implementation using stack ======================/
//void
//NON_RDFS(struct Graph* g, int start) {
//	int i;
//	struct Stack* stk = create_stack(10);
//	bool* V = malloc(sizeof(bool) * g->no);
//	i = start;
//	push(stk, i);
//	V[i] = true;
//	struct Node* node = g->head[i].next;
//	
//	while (!is_empty(stk)) {
//		while(node != NULL) {
//			if (!V[node->id]) {
//				push(stk, node->id);
//				V[node->id] = true;
//				node = g->head[node->id].next;
//			}
//			else {
//				node = node->next;
//			}
//		}
//		pop(stk, &i);
//		printf("->%d", i);
//		top(stk, &i);
//		node = g->head[i].next;
////		if (node !=NULL) {
////			node = g->head[node->id].next;
////		}
//	}
//	printf("\n");
//}
//----------------- new approach ---------------------//
void
NON_RDFS(struct Graph* g, int start) {
	int i;
	struct Node* node;
	struct Stack* stk = create_stack(10);
	bool* V = malloc(sizeof(bool) * g->no);
	for (i = 0; i < g->no; i++) {
		V[i] = false;
	}
	push(stk, start);

	while (!is_empty(stk)) {
		pop(stk, &i);
		if (!V[i]) {
			V[i] = true;
			printf("->%d", i);
			for (node = g->head[i].next; node != NULL; node = node->next) {
				push(stk, node->id);
			}
		}
	}
	printf("\n");
}
