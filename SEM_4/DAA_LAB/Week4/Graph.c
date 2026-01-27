/*
2). Write a program for depth-first search of a graph. 
Identify the push and pop order of vertices.
*/

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

typedef struct queue{
    int items[max];
    int r, f;
} Queue;

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

void dfs(Graph *graph, int vertex){
    printf("%d ", vertex);
    graph->visited[vertex] = 1;

    Node *temp = graph->adjLists[vertex];
    while (temp){
        int adjVertex = temp->vertex;
        if (graph->visited[adjVertex]==0)
            dfs(graph, adjVertex);
        temp = temp->next;
    }
}


Queue *createQueue(){
    Queue *q = (Queue *) calloc(1, sizeof(Queue));
    q->f = q->r = -1;
    return q;
}

int isEmpty(Queue *q){
    return (q->r==-1);
}

void enqueue(Queue *q, int value){
    if (q->r == max -1) return;
    if (q->f==-1) q->f = -1;
    q->items[++q->r] = value;
}

int dequeue(Queue *q){
    if (isEmpty(q)) return -1;
    int item = q->items[q->f++];
    if(q->f>q->r) q->f=q->r=-1;
    return item;
}

void bfs(Graph *graph, int startVertex){
    Queue *q = createQueue();
    int visited[max] = {0};

    printf("%d ",startVertex);
    visited[startVertex] = 1;
    enqueue(q, startVertex);
    while (!isEmpty(q)){
        int vertex = dequeue(q);
        Node *temp = graph->adjLists[vertex];
        while (temp){
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]){
                printf("%d ",adjVertex);
                visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
        temp = temp->next;
        }
    }
    free(q);
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

    for (int i=0; i<vertices; i++)
        graph->visited[i]=0;

    printf("Breadth First Traversal : \n");
    bfs(graph, 0);
    return 0;
}