#include <stdio.h>
#include <stdlib.h>
#include "dsds.h"

adj_list* init_adj_list(/* vertex count */)
{
    adj_list* graph = malloc(sizeof(adj_list) * V);

    for(int i = 0; i < V; i++) /* initializes the adj list */
    {
        graph[i].vertex_index = i+1; //V_1, V_2, ...
        graph[i].edge_count = V - (i+1);
        if(i == V - 1)
            {
                graph[i].head = NULL;
                graph[i].tail = NULL;
                break;
            }
        graph[i].head = malloc(sizeof(list) * graph[i].edge_count);
        graph[i].tail = graph[i].head;
    }

    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < graph[i].edge_count; j++)
        {
            graph[i].head[j].vertex = graph[i].vertex_index + j + 1;
            graph[i].head[j].weight = 1 + rand() % 10;
            graph[i].head[j].primary_vertex = &graph[i];

            if(j == graph[i].edge_count - 1)
                {
                    graph[i].tail = &graph[i].head[j];
                }
        }
    }
    return graph;
}