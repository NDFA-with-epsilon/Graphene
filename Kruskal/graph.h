#ifndef _GRAPH_DESC_H
#define _GRAPH_DESC_H

#define V 5
/* graph impl using adjacency list */
typedef struct adj_list
{
	int vertex_index;
	int edge_count;
	struct list* head;
	struct list* tail;
}adj_list;

typedef struct list
{
	int vertex_index;
    int weight;
}list;

adj_list* init_adj_list(/* for now its a global variable V, but otherwise put vertex count here */);
int sort(adj_list* g_list, int vertex); /* --> stub function in sort.h */ 
#endif