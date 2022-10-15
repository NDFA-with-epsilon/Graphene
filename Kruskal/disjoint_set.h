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
    - what will be stored in each set_t_t ? -> done 
    - how to represent an 'edge' and its weight ? -> done using adjacency list, "graph.h"
*/

#define V 5
#include "graph.h"

// typedef struct vertex_list
// {
//     set_t* head_set;
//     int vertex;
//     set_t* next;
// }vertex_t; /* 'list' earlier */

typedef struct set
{
    // vertex_t* head_ptr;
    // vertex_t* tail_ptr;

    adj_list* head_ptr;
    adj_list* tail_ptr;
    int list_len; /*for linked list impl's weighted-union heuristics */  
}set_t; /* 'node' earlier */

set_t* set_buf;

set_t* make_set(int vertex);
set_t* find_set(int vertex); /* Must be O(1). Also, make it inline or nah ? */

/* 
    sets themselves are not linked via list, its elements are. Sets can be stored together in an array 
*/

/* see if its possible to make a set_of(int vertex) macro to return the set object containing the given vertex, just like linux kernel's container_of() macro */

/* now implement union() with weighted-union heuristics: simply append shorter list at the end of longer list & not the opposite, by maintaining a list length in the set object*/

/* MAYBE (according to CLRS) kruskal's requires a disjoint-set-forest i.e disjoint set implemented via rooted trees with its own pair of heuristics. 
This was a good exercise nevertheless */
#endif