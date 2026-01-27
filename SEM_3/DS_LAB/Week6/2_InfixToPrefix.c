#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char st[MAX_SIZE];
    int tos;
} Stack;

void push(Stack *s, char ch) {
    if (s->tos < MAX_SIZE - 1) {
        s->st[++(s->tos)] = ch;
    }
}

char pop(Stack *s) {
    if (s->tos >= 0) {
        return s->st[(s->tos)--];
    }
    return '\0';
}

char viewTop(Stack *s) {
    if (s->tos >= 0) {
        return s->st[s->tos];
    }
    return '\0';
}

int getPrec(char ch) {
    switch(ch) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

int isOp(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int main() {
    char expr[MAX_SIZE], ans[MAX_SIZE], ch;
    printf("Enter the infix expression: ");
    scanf("%s", expr);
    
    Stack s;
    s.tos = -1;
    
    int i, ind = 0;
    int p1, p2;
    
    for (i = strlen(expr) - 1; i >= 0; i--) {
        if (expr[i] == ')') {
            push(&s, ')');
        }
        else if (expr[i] == '(') {
            while ((ch = pop(&s)) != ')') {
                ans[ind++] = ch;
            }
        }
        else if (isOp(expr[i])) {
            while (s.tos != -1 && getPrec(viewTop(&s)) > getPrec(expr[i])) {
                ans[ind++] = pop(&s);
            }
            push(&s, expr[i]);
        }
        else {
            ans[ind++] = expr[i];
        }
    }
    
    while (s.tos >= 0) {
        ans[ind++] = pop(&s);
    }
    
    ans[ind] = '\0';
    
    printf("Prefix expression is: ");
    for (i = ind - 1; i >= 0; i--) {
        printf("%c", ans[i]);
    }
    printf("\n");
    
    return 0;
}
