#include <stdbool.h>
void RDFS(struct Graph* g, int start);
void NON_RDFS(struct Graph* g, int start);
void BFS(struct Graph* g, int start);
void Dijkstra(int** adj_matrix, int num, int s, int dist[]);
void Dijkstra_print(int start, int dist[], int num);

bool BellmanFord(int** graph, int num, int start, int* dist);
void BellmanFord_print(int start, int dist[], int num);

void Prim(int** graph, int num, int parent[]);
void print_MST(int parent[], int num, int** graph);


void kruskal(struct Graph* graph, int parent[], int num);
