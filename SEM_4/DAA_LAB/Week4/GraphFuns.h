/* Basic functions for graphs */
#include <stdio.h>
#include <stdlib.h>

#define max 100

typedef struct node {
    int vertex;
    struct node *next;
} Node;

typedef struct graph {
    int numVertices;
    Node **adjLists;
    int *visited;
} Graph;

Graph * createGraph (int vertices){
    Graph* graph = calloc(1, sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjLists = (Node**) calloc(vertices, sizeof(Node *));
    graph->visited = (int *) calloc(vertices, sizeof(int));
    for (int i=0; i<vertices; i++){
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

//Create a new adj list node
Node * createNode(int v){
    Node *newNode = calloc(1, sizeof(Node));
    newNode->next = NULL;
    newNode->vertex = v;
    return newNode;
}

void addEdge(Graph *graph, int src, int dest){
    Node * newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    Node * newNode2 = createNode(src);
    newNode2->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode2;
}