#ifndef _GRAPH_DESC_H
#define _GRAPH_DESC_H

#define V 5
typedef struct list
{
	int vertex_index;
    int weight;
}list;

/* graph impl using adjacency list */
typedef struct adj_list
{
	int 		 vertex_index;
	int 		 edge_count;
	struct list* head;
	struct list* tail; /* --> is it really needed ? */
	struct set*  set_ptr;
}adj_list;

typedef struct edge_info
{
    int v_1; //adjacency list (adj_list*) mat_adj[v_1 - 1]
    int v_2; //sub-list of v_1 (list*)	  mat_adj[v_1 - 1].head[v_2 - 1]
    int weight; 
}edge_info;

void init_adj_list(/* for now its a global variable V, but otherwise put vertex count here */);
int sort(adj_list* g_list, int vertex); /* --> stub function in sort.h */ 

adj_list mat_adj[V];
#endif