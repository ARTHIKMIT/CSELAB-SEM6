// Circular Queue
#include <stdio.h>
#define MAX 5

typedef struct{
    int element;
}Q;

Q cq[MAX];

int isEmpty(int f, int r)
{
    if (f==r)
        return 1;
    else return 0;
}

int isFull(int f, int r)
{
    if ((r+1)%MAX == f)
        return 1;
    else return 0;
}

void Add(int *rear, int item)
{
    cq[(++(*rear))%MAX].element = item;
}   
//front points to -1th element (last deleted)
//rear points to last element thats added

int Del(int *front)
{
    return cq[++(*front)].element;
}
int main() {
    int rear = 0, front = 0;
    int ch, item, del;
    do{
        printf("1. Add, 2. Del, 3.Display, 4.Exit\n");
        scanf("%d", &ch);
        switch(ch){
            case 1: 
                if (isFull(front, rear)==1)
                    printf("Nuh, Full. No can do.");
                else {
                    printf("Enter element to be Added : ");
                    scanf("%d",&item);
                    Add(&rear, item);
                }
                break;
            case 2:
                if (isEmpty(front, rear)==1)
                    printf("Nuh, Empty. No can do.");
                else {
                    item = Del(&front);
                    printf("Element deleted : %d",item);
                }
                break;
            case 3:
                printf("The elements in Circular queue are : \n");
                for (int i = (front+1)%MAX; i!= (rear+1)%MAX; i=(i+1)%MAX){
                    printf("%d ",cq[i]);
                }
                printf("\n")
                break;
        }
    }while(ch!=4);
    return 0;
}
