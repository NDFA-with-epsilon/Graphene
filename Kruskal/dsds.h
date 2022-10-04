#ifndef _DSDS_H
#define _DSDS_H

/* Disjoint set data structure for ease of cycle detection */
/* set of
    - disjoint & 
    - dynamic 
    sets
*/

/* first attempt: linked list implementation  */
/* 
    - what will be stored in each node ? -> done 
    - how to represent an 'edge' and its weight ? -> done using adjacency list, "graph.h"
*/

#define V 5
#include "graph.h"

typedef struct vertex_list
{
    node* head_node;
    int vertex;
    node* next;
}vertex_t;

typedef struct _node
{
    vertex_t* head_ptr;
    vertex_t* tail_ptr;

    int list_length; /*for linked list impl's weighted-union heuristics */  
}node;

node* make_set(int vertex)
{
    node* ptr;
    ptr = (node*)malloc(sizeof(node));

    ptr->head_ptr = (vertex_t*) malloc(sizeof(vertex_t));
    ptr->tail_ptr = ptr->head_ptr;
    
    ptr->head_ptr->head_node = ptr;
    ptr->head_ptr->vertex = vertex;
    ptr->head_ptr->next = NULL;

    ptr->list_length = 1;
    printf("\nSet initialized");
    return ptr;
}

node* make_set_tmp(vertex_t* obj)
{
    node* ptr;
    ptr = (node*)malloc(sizeof(node));

    ptr->head_ptr = obj;
    ptr->tail_ptr = ptr->head_ptr;

    ptr->head_ptr->head_node = ptr;
    ptr->list_length = 1;
    printf("\nSet initialized");
    return ptr;
}

vertex_t* make_vertex(int vertex)
{
    vertex_t* tmp = (vertex_t*)malloc(sizeof(vertex_t));
    tmp->vertex = vertex;
    tmp->head_node = NULL;
    tmp->next = NULL;

    return tmp;
}
/* 
    sets themselves are not linked via list, its elements are. Sets can be stored together in an array 
*/

vertex_t* find_set(vertex_t* obj)
{
    /* Kindly check that obj is not null before shooting it over here or suffer from segfault */
    return obj->head_node->head_ptr;
}

/* see if its possible to make a set_of(int vertex) macro to return the set object containing the given vertex, just like linux kernel's container_of() macro */

/* now implement union() with weighted-union heuristics: simply append shorter list at the end of longer list & not the opposite, by maintaining a list length in the set object*/

/* MAYBE (according to CLRS) kruskal's requires a disjoint-set-forest i.e disjoint set implemented via rooted trees with its own pair of heuristics. 
This was a good exercise nevertheless */
#endif