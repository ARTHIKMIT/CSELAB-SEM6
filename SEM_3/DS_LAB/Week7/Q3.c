/*
Vignesh and his wife Lata are facing a cash crisis. They go to the nearby ATM to get 
some cash. There are 3 ATMs inside the same room. People are standing in queue 
outside, and go inside the room in groups of 3 to the ATMs, fetch their money and 
come out. Lata has an irrational fear in getting money from ATM that her ATM pin 
will somehow be stolen and her money will be lost. So she will always like to go into 
room with Vignesh. Vignesh is standing at position K in line, immediately followed 
by lata (at position K+1). Can you tell whether Vignesh and Lata both will be able to 
get money in such a way that Lata does not feel insecure? Using queue, find whether 
they can get money for the given set of N and K. Input: the first line contains an 
integer T denoting the number of test cases. T test cases follow. The only line of each 
test case contains two spaces separated integers N and K , Where N denotes number 
of people in the queue. And K denotes the position of Vignesh . Constraints 
1<=T<=100 3<=N<=100 1<=K<=N-1, N is divisible by 3.
Sample Input
2
3 1
6 3
Output
Yes 
No
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int * items;
    int front,rear,size;
} Queue;

void insert(Queue * q,int x) {
    if (q->front == -1)
        q->front = 0;
    q->rear = q->rear + 1;
    q->items[q->rear] = x;
}

int delete(Queue * q) {
    int item = q->items[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    }
    else q->front = q->front + 1;
    return item;
}
bool search(Queue *q, int N, int K) {
    // Iterate through the queue in groups of 3
    for (int i = q->front; i <= q->rear; i += 3) 
        if ((K >= q->items[i] && K < q->items[i + 2]) && ((K + 1) >= q->items[i] && (K + 1) < q->items[i + 2])) 
            return true;
    return false; 
}

int main() {
    int T;
    printf("Enter the number of test cases: ");
    scanf("%d", &T);

    while (T--) {
        int N, K;
        printf("Enter N (number of people) and K (Vignesh's position): ");
        scanf("%d", &N);
        scanf("%d", &K);

        Queue q;
        q.size = N;
        q.items = (int *)malloc(q.size * sizeof(int));
        q.front = -1;
        q.rear = -1;

        for (int i = 0; i < N; i++)
            insert(&q, i + 1);

        if (search(&q, N, K))
            printf("Yes\n");
        else printf("No\n");

        free(q.items);
    }

    return 0;
}
