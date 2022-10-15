#include "graph.h"
#include "disjoint_set.h"

/* Assume fully-connected, static graph */
void init_adj_list(adj_list* mat_adj)
{   
    //total edge count of graph --> is a constant for the given graph
    int c_edge = (V * (V-1))/2;
    list* buf = malloc(c_edge * sizeof(list));
    
    mat_adj[0].vertex_index = 1;
    mat_adj[0].edge_count = V - 1;
    mat_adj[0].head = buf;
    mat_adj[0].tail = buf + (mat_adj[0].edge_count - 1);
    mat_adj[0].set_ptr = NULL;

    mat_adj[V-1].vertex_index = V;
    mat_adj[V-1].edge_count = 0;
    mat_adj[V-1].head = NULL;
    mat_adj[V-1].tail = NULL;
    mat_adj[V-1].set_ptr = NULL;


    for(int i = 1; i < V-1; i++)
    {
        mat_adj[i].vertex_index = i+1;
        mat_adj[i].edge_count = V-(i+1);
        mat_adj[i].head = mat_adj[i-1].tail + 1;
        mat_adj[i].tail = mat_adj[i].head + (mat_adj[i].edge_count - 1);
        mat_adj[i].set_ptr = NULL;
    }  
    
    for(int i = 0; i < V; i++)
    {   
        for(int j = 0; j < mat_adj[i].edge_count; j++)
        {   
            mat_adj[i].head[j].vertex_index = mat_adj[i].vertex_index + j + 1;
            mat_adj[i].head[j].weight = 1 + rand() % 10;
        }
    }
}


/* instead of calling malloc multiple times, allocate space at once*/
/* make_set will then simply do pointer assignments to the pre-allocated chunk */

set_t* make_set(int vertex)
{   
    if(vertex == 0) /* starting with first vertex */
    {
        set_buf = malloc(V * sizeof(set_t));
    }

    set_buf[vertex].head_ptr = &mat_adj[vertex];
    set_buf[vertex].tail_ptr = set_buf[vertex].head_ptr;
    set_buf[vertex].list_len = 1;
    mat_adj[vertex].set_ptr = &set_buf[vertex];
    
    return &set_buf[vertex];
    // set_t* ptr;
    // ptr = malloc(sizeof(set_t));

    // ptr->head_ptr = (vertex_t*) malloc(sizeof(vertex_t));
    // ptr->tail_ptr = ptr->head_ptr;
    
    // ptr->head_ptr->head_set = ptr;
    // ptr->head_ptr->vertex = vertex;
    // ptr->head_ptr->next = 0;

    // ptr->list_length = 1;
    // printf("\nSet initialized");
    // return ptr;
}

set_t* find_set(int vertex)
{
    return mat_adj[vertex-1].set_ptr;
}

// set_t* make_set_tmp(vertex_t* obj)
// {
//     set_t* ptr;
//     ptr = (set_t*)malloc(sizeof(set_t));

//     ptr->head_ptr = obj;
//     ptr->tail_ptr = ptr->head_ptr;

//     ptr->head_ptr->head_set = ptr;
//     ptr->list_length = 1;
//     printf("\nSet initialized");
//     return ptr;
// }

// vertex_t* make_vertex(int vertex)
// {
//     vertex_t* tmp = (vertex_t*)malloc(sizeof(vertex_t));
//     tmp->vertex = vertex;
//     tmp->head_set = 0;
//     tmp->next = 0;

//     return tmp;
// }
/* 
    sets themselves are not linked via list, its elements are. Sets can be stored together in an array 
*/

// vertex_t* find_set(vertex_t* obj)
// {
//     /* Kindly check that obj is not null before shooting it over here or suffer from segfault */
//     return obj->head_set->head_ptr;
// }
