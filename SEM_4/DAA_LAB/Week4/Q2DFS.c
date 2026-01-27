/*
2). Write a program for depth-first search of a graph. 
Identify the push and pop order of vertices.
*/
#include <stdio.h>
#include <stdlib.h>
#include "GraphFuns.h"

#define max 100


void dfs(Graph *graph, int vertex){
    printf("Push: %d \n", vertex);
    graph->visited[vertex] = 1;

    Node *temp = graph->adjLists[vertex];
    while (temp){
        int adjVertex = temp->vertex;
        if (graph->visited[adjVertex]==0)
            dfs(graph, adjVertex);
        temp = temp->next;
    }
    printf("Pop: %d\n", vertex); 
}

int main(){
    int vertices = 6;
    Graph *graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);

    printf("Depth First Traversal : \n");
    dfs(graph, 0);
    return 0;
}