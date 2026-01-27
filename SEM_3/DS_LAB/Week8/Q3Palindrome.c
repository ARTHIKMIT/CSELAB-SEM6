/*
Q3 Write a program to check whether given string is a palindrome using a dequeue.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char *Data;
	int front;
	int rear;
	int size;
} Queue;

void insertr(Queue *q, char str){
	q->Data[++(q->rear)] = str;
	if(q->front==-1)
		q->front=0;
}
/*
void insertf(Queue *q, char str){
	q->Data[--(q->front)] = str;
}

char deletef(Queue *q){
	char str;
    str = q->Data[(q->front)];
	if(q->front==q->rear)
		q->front=q->rear=-1;
	else q->front++;
	return str;
}
*/
char deleter(Queue *q){
	char str;
    str = q->Data[(q->rear)];
	if(q->front==q->rear)
		q->front=q->rear=-1;
	else q->rear--;
	return str;
}

int isPalindrome(char * str){
    Queue q;
	q.front = q.rear = -1;
	int n = q.size = strlen(str);
	q.Data = (char *)malloc(n*sizeof(char));
    for(int i=0; i<n; i++){
        if (i<n/2)
            insertr(&q, str[i]);
        else if (n%2!=0 && i==n/2)
            continue;
        else if (deleter(&q) != str[i])
            return 0;
    }
    return 1;
}

int main(){
	char str[20];
	printf("Enter String : ");
	scanf("%s", str);
    if(isPalindrome(str))
        printf("Palindrome");
    else printf("Not a Palindrome.");
	return 0;
}
