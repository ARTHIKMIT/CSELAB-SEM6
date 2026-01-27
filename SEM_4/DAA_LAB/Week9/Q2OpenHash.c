/*
2) Write a program to construct the Open hash table. 
Find the number of key comparisons in successful search and unsuccessful search. 
This should be done by varying the load factor of the hash table. 
You may consider varying the number of keys for a fixed value of hash table size say m=10 and n=50, 100, and 200. 
This should be repeated for at least four different hash table sizes say m= 20, m=50. 
*/

#include<stdio.h>
#include<stdlib.h>

//Linked List
typedef struct node {
    int data;
    struct node *next;
} node;

int opCount = 0;

node * createNode(int data){
    node * newNode = calloc(1, sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
}

void displayHash(node *hash[], int m){
    for (int i=0; i<m; i++){
        printf("\n%d : ", i);
        if (hash[i] != NULL){
            node * temp = hash[i];
            while(temp != NULL){
                printf(" %d ", temp->data);
                temp = temp->next;
            }
        }
    }
}

void constructHash(int arr[], int n, node* hash[], int m){
    for (int i=0; i<n; i++){
        node * new = createNode(arr[i]);
        if (hash[arr[i]%m] == NULL)
            hash[arr[i]%m] = new;
        else {
            node * temp = hash[arr[i]%m];
            while(temp->next != NULL)
                temp = temp->next;          
            temp->next = new;
        }
    }
}

int searchHashTable(node* hash[], int key, int m) {
    int index = key % m; // Hash index
    node* temp = hash[index];
    int comparisons = 0;
    
    while (temp != NULL) {
        opCount++;
        if (temp->data == key) {
            return 1; // Successful search
        }
        temp = temp->next;
    }
    
    return 0;  // Unsuccessful search
}


int main(){
    int n, m;
    /*
    printf("Enter the number of Elements : ");
    scanf("%d",&n);

    char arr[n];
    printf("Enter the Elements : ");
    for(int i = 0; i < n; i++)
      scanf("%d",&arr[i]);

    printf("Hash Size : ");    
    scanf("%d",&m);

    */
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    n = sizeof(arr)/sizeof(arr[0]);
    
    m = 10; //Hash Size
    node **hash = calloc(m, sizeof(node*));
    constructHash(arr, n, hash, m);
    
    displayHash(hash, m);

    opCount = 0;
    int successfulSearch = searchHashTable(hash, 11, m);  // Search for existing element (7)
    printf("\nSuccessful search comparisons: %d\n", opCount);
    
    opCount = 0;  // Reset opCount for unsuccessful search
    int unsuccessfulSearch = searchHashTable(hash, 100, m);  // Search for non-existing element (100)
    printf("Unsuccessful search comparisons: %d\n", opCount);
    
    // Free the allocated memory for the hash table
    for (int j = 0; j < m; j++) {
        node* temp = hash[j];
        while (temp != NULL) {
            node* next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(hash);
    return 0;
}