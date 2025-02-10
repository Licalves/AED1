#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 300

typedef struct {
    char items[MAX];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, char c) {
    if (s->top < MAX - 1) {
        s->items[++s->top] = c;
    }
}

char pop(Stack *s) {
    return isEmpty(s) ? '\0' : s->items[s->top--];
}

char peek(Stack *s) {
    return isEmpty(s) ? '\0' : s->items[s->top];
}

int precedence(char op) {
    switch (op) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

int isLeftAssociative(char op) {
    return op != '^';
}

void infixToPostfix(char *expr) {
    Stack s;
    init(&s);
    char output[MAX];
    int k = 0;
    
    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];
        
        if (isalnum(c)) {
            output[k++] = c;
        } else if (c == '(') {
            push(&s, c);
        } else if (c == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                output[k++] = pop(&s);
            }
            pop(&s);
        } else {
            while (!isEmpty(&s) && precedence(peek(&s)) > precedence(c) ||
                   (!isEmpty(&s) && precedence(peek(&s)) == precedence(c) && isLeftAssociative(c))) {
                output[k++] = pop(&s);
            }
            push(&s, c);
        }
    }
    
    while (!isEmpty(&s)) {
        output[k++] = pop(&s);
    }
    
    output[k] = '\0';
    printf("%s\n", output);
}

int main() {
    int N;
    scanf("%d", &N);
    getchar();
    
    while (N--) {
        char expr[MAX];
        fgets(expr, MAX, stdin);
        expr[strcspn(expr, "\n")] = '\0';
        infixToPostfix(expr);
    }
    
    return 0;
}
