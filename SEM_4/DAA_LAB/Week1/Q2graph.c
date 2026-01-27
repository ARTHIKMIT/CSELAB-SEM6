/*
2) Write a program to implement the following graph representations and display them.
i. Adjacency list
ii. Adjacency matrix
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char name;
    int ind;
    struct node *next;
} node;

node * createNode(char d){
    node *newNode = calloc(1, sizeof(node));
    newNode->next = NULL;
    newNode->name = d;
    return newNode;
}

void dispAdjList(node** l, int n){
    printf("Adjacency List : \n");
    for (int i = 0; i<n; i++){
        node *head = l[i];
        printf("%c",head->name);
        head = head->next;
        while(head != NULL){
            printf("->%c", head->name);
            head = head->next;
        }
        printf("\n");
    }
}

int getIndex(node **l, char ch, int n){
    for (int i=0; i<n; i++)
        if (l[i]->name == ch)
            return i;
    return -1;
}

void makeAdjMat(int n, int mat[n][n], node **l){
    for (int i = 0; i<n; i++){
        node *head = l[i];
        mat[i][i] = 0;
        head = head->next;
        while(head != NULL){
            int temp = getIndex(l, head->name, n);
            mat[i][temp] = 1;
            head = head->next;
        }
    }
}

void dispAdjMat(int n, int mat[n][n]){
    printf("Adjacency Matrix : \n");
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

int main(){
    int n;
    printf("Number of vertices : ");
    scanf("%d", &n);
    
    node **adjList = calloc(n, sizeof(node*));
    int adjMat[n][n];

    //Initalising the Matrix to 0
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            adjMat[i][j] = 0;

    for (int i = 0; i<n; i++){
        char name;
        int temp, ind;
        printf("Node %d :\n",i+1);
        printf("Name : ");
        getchar();
        scanf("%c", &name);

        adjList[i] = createNode(name);
        node *head = adjList[i];

        printf("Number of neighbours : ");
        scanf("%d", &temp);

        for (int j = 0; j<temp; j++){
            printf("Neighbour %d :\n",j+1);
            printf("Name : ");
            getchar();
            scanf("%c", &name);
            
            //printf("TEST %c TEST", name);
            head->next = createNode(name);
            head = head->next;
        }
    }

    dispAdjList(adjList, n);
    makeAdjMat(n, adjMat, adjList);
    dispAdjMat(n, adjMat);
}