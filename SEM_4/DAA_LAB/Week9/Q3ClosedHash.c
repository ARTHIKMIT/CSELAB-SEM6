/*
3) Write a program to construct the closed hash table. 
Find the number of key comparisons in successful search and unsuccessful search.
*/

#include<stdio.h>

int opCount = 0;

void displayHash(int hash[], int m){
    for (int i=0; i<m; i++)
        printf("\n%d ", hash[i]);
}

void constructHash(int arr[], int n, int hash[], int m){
    for (int i=0; i<n; i++){
        int index = arr[i]%m;
        while (hash[index] != -1)
            index = (index+1)%m;    
        hash[index] = arr[i];
    }
}

int searchHashTable(int hash[], int key, int m) {
    int index = key % m;  // Calculate the hash index
    
    while (hash[index] != -1) {
        opCount++;
        if (hash[index] == key) {
            return 1;  // Key found
        }
        index = (index + 1) % m;  // Linear probing
    }
    
    return 0; 
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
    int arr[] = {1, 2, 3, 4, 5, 6, 21, 23};
    n = sizeof(arr)/sizeof(arr[0]);
    
    m = 10; //Hash Size

    int hash[m];
    for(int i=0; i<m; i++)
        hash[i] = -1;
    constructHash(arr, n, hash, m);
    
    displayHash(hash, m);

    opCount = 0;
    int successfulSearch = searchHashTable(hash, 23, m);  // Search for existing element (23)
    printf("\nSuccessful search comparisons: %d\n", opCount);
    
    opCount = 0;  // Reset opCount for unsuccessful search
    int unsuccessfulSearch = searchHashTable(hash, 11, m);  // Search for non-existing element (11)
    printf("Unsuccessful search comparisons: %d\n", opCount);
    
    return 0;
}