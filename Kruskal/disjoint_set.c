#include "dsds.h"

node_t* make_set(int vertex)
{
    node_t* ptr;
    ptr = (node_t*)malloc(sizeof(node_t));

    ptr->head_ptr = (vertex_t*) malloc(sizeof(vertex_t));
    ptr->tail_ptr = ptr->head_ptr;
    
    ptr->head_ptr->head_node_t = ptr;
    ptr->head_ptr->vertex = vertex;
    ptr->head_ptr->next = NULL;

    ptr->list_length = 1;
    printf("\nSet initialized");
    return ptr;
}

node_t* make_set_tmp(vertex_t* obj)
{
    node_t* ptr;
    ptr = (node_t*)malloc(sizeof(node_t));

    ptr->head_ptr = obj;
    ptr->tail_ptr = ptr->head_ptr;

    ptr->head_ptr->head_node_t = ptr;
    ptr->list_length = 1;
    printf("\nSet initialized");
    return ptr;
}

vertex_t* make_vertex(int vertex)
{
    vertex_t* tmp = (vertex_t*)malloc(sizeof(vertex_t));
    tmp->vertex = vertex;
    tmp->head_node_t = NULL;
    tmp->next = NULL;

    return tmp;
}
/* 
    sets themselves are not linked via list, its elements are. Sets can be stored together in an array 
*/

vertex_t* find_set(vertex_t* obj)
{
    /* Kindly check that obj is not null before shooting it over here or suffer from segfault */
    return obj->head_node_t->head_ptr;
}