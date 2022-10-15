#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "m_sort.h"
#include "disjoint_set.h"

mat_adj[V] = {0};

int main(void)
{
    init_adj_list(mat_adj);
    SORT(mat_adj);
    
    set_t* set[V] = {0};
    for(int i = 0; i < V; i++)
    {
        set[i] = make_set(i+1); /* disjoint sets */
    }

    /* 
        make_set_tmp() and make_vertex() require extra space for storing vertex_t* and also involves unnecessary indirections i think
     */


}