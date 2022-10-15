/* Mergesort adaptation for our data adjacency list data structure */
#ifndef _MSORT_H
#define _MSORT_H

#include "graph.h"
#include <math.h>

#define INVALID_PARAM -1
#define SUCCESS 1

int sort_list(adj_list* g_list, int vertex /* 1,2,3... */, int l, int r); 
void merge(adj_list* g_list, int vertex, int l, int mid, int r);

#define SORT(mat_adj) for(int i = 0; i < V; i++) { int ret = sort_list(mat_adj, i+1, 0, mat_adj[i].edge_count - 1); \
assert(ret == SUCCESS);}

#endif