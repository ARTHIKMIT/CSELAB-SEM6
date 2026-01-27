#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char st[20][20];
    int tos;
} Stack;

void push(Stack *s,char *ch) {
    strcpy(s->st[++(s->tos)],ch);
}

char * pop(Stack *s) {
    int i=0;
    char * ch = (char *) malloc (20*sizeof(char));
    strcpy(ch,s->st[(s->tos)--]);
    int len = (int) strlen(ch);
    return ch;
}

int isOp(char ch) {
    switch (ch) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^': return 1;
        default: return 0;
    }
}

int main() {
    int i,ind=0;
    char expr[20],ch,*temp;
    printf("Enter the prefix expression ");
    scanf("%s",expr);
    
    Stack s;
    s.tos=-1;
    
    char op1[20],op2[20];

    i = strlen(expr)-1;

    do {

        if (expr[i] == ')')
            continue;
            
        else if (expr[i] == '(')
            continue;
        
        else if (isOp(expr[i])) {
        strcpy(op1, pop(&s));
        strcpy(op2, pop(&s));
        int len = strlen(op1) + strlen(op2) + 2;  // +2 for operator and null terminator
        char temp[len];
        temp[0] = '\0';  // Initialize as an empty string
        strcpy(temp, op1);
        strcat(temp, op2);
        temp[len-2] = expr[i];
        temp[len-1] = '\0';
        push(&s, temp);
    }
        else {
        char temp[2];
        temp[0] = expr[i];
        temp[1] = '\0';
        push(&s, temp);
    }
        i--;
    } while( i >= 0 );

    printf("Postfix expression is: ");
    printf("%s",s.st[0]);

}
