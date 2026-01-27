/*
1).Write a program to determine the Topological sort of a given graph using
i. Depth-First technique
ii. Source removal technique
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int arr[100];
    int tos;
} Stack;

typedef struct {
    int n;
    int **adjLists;
} Graph ;

void push(Stack *s, int n) {
    (s->arr)[++(s->tos)] = n;
}

void insertEnd(int * list, int n) {
    int i = 0;
    while (list[i] != -1)
        i++;
    list[i] = n;
    list[i+1] = -1;
}


Graph createDAG(int n) {
    Graph g;
    g.n = n;
    int i,x,j;
    g.adjLists = (int **) calloc(n,sizeof(int *));
    for (i = 0; i < n; i++) {
        g.adjLists[i] = (int *) calloc(n,sizeof(int));
        g.adjLists[i][0] = -1;
    }
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            if (i==j) 
                continue;
            else {
                printf("Is there an edge from vertex %d to vertex %d ? Type 1 if yes, 0 if no ", i, j);
                scanf("%d",&x);
                if (x == 1) 
                    insertEnd((g.adjLists[i]),j);
            }
        }
    }
    return g;
}

void topoDFS(Graph g, int *visited, Stack *s, int node) {
    visited[node] = 1;
    int *neighbors = g.adjLists[node];
    for (int i = 0; neighbors[i] != -1; i++) {
        int neighbor = neighbors[i];
        if (!visited[neighbor]) {
            topoDFS(g, visited, s, neighbor);
        }
    }
    push(s, node);
}

int isInArray(int arr[], int n, int value) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            return 1;
        }
    }
    return 0;
}

void topoSourceRem(Graph *g, int *removed, int *index) {
    int *degree = (int *)calloc(g->n, sizeof(int));
    
    // Compute in-degrees
    for (int i = 0; i < g->n; i++) {
        if (!isInArray(removed, *index, i)) {
            for (int j = 0; g->adjLists[i][j] != -1; j++) {
                degree[g->adjLists[i][j]]++;
            }
        }
    }
    
    // Find node with in-degree of 0 (source node)
    int minDegree = 1000;
    int node = -1;
    for (int i = 0; i < g->n; i++) {
        if (!isInArray(removed, *index, i) && degree[i] < minDegree) {
            minDegree = degree[i];
            node = i;
        }
    }
    
    if (node != -1) {
        removed[*index] = node;
        (*index)++;
        printf("%d ", node);
    }
    
    free(degree);
}

int main() {
    int n = 6;
    Graph g;
    g.n = n;
    g.adjLists = (int **)calloc(n, sizeof(int *));
    for (int i = 0; i < n; i++) {
        g.adjLists[i] = (int *)calloc(n, sizeof(int));
        g.adjLists[i][0] = -1; // Marks end of adjacency list
    }
    // printf("Enter number of nodes in graph ");
    // scanf("%d",&n);
    // int * visited = (int *) calloc(n,sizeof(int));
    // int * removed = (int *) calloc(n,sizeof(int));
    // int ind = 0;
    // Graph g = createDAG(n);

    // TO AVOID MANUAL INPUT : 
    // Manually inserting edges for the graph
    g.adjLists[2][0] = 3; g.adjLists[2][1] = -1;
    g.adjLists[3][0] = 1; g.adjLists[3][1] = -1;
    g.adjLists[4][0] = 0; g.adjLists[4][1] = 1; g.adjLists[4][2] = -1;
    g.adjLists[5][0] = 0; g.adjLists[5][1] = 2; g.adjLists[5][2] = -1;
    
    int visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    Stack s;
    s.tos = -1;
    
    printf("Topological sort using DFS: ");
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            topoDFS(g, visited, &s, i);
        }
    }
    while (s.tos != -1) {
        printf("%d ", s.arr[s.tos--]);
    }

    printf("\nTopological sort using source removal: ");
    int removed[n];
    int index = 0;
    for (int i = 0; i < n; i++) {
        topoSourceRem(&g, removed, &index);
    }

    printf("\n");

    // Free the memory allocated for adjacency lists
    for (int i = 0; i < n; i++) {
        free(g.adjLists[i]);
    }
    free(g.adjLists);

    return 0;
}
