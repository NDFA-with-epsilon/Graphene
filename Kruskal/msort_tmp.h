/* Mergesort adaptation for our data adjacency list data structure */
/* call mergesort on every list i.e V - 1  times */
#ifndef _MSORT_H
#define _MSORT_H

#include "graph.h"
#include <math.h>

#define INVALID_PARAM -1
#define SUCCESS 1

int merge_stub(adj_list* list, int vertex);
void sort_list(adj_list* list, int vertex /* 1,2,3... */, int l, int r); 
void merge(adj_list* list, int vertex, int l, int mid, int r);

#endif