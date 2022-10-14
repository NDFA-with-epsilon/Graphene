#include <stdio.h>
#include <stdlib.h>
#include "disjoint_set.h"

int main(void)
{
    adj_list* g_list = init_adj_list();

    set_t* set_buf[V];
    for(int i = 0; i < V; i++)
    {
        set_buf[i] = make_set(i+1); /* disjoint sets */
    }

    /* 
        make_set_tmp() and make_vertex() require extra space for storing vertex_t* and also involves unnecessary indirections i think
     */


}