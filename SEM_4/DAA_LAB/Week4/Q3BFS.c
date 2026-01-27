/*
3). Write a program for breadth-first search of a graph. 
*/

#include "GraphFuns.h"

typedef struct queue{
    int items[max];
    int r, f;
} Queue;

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

    printf("Breadth First Traversal : \n");
    bfs(graph, 0);
    return 0;
}
