#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 20

typedef struct {
    int top;
    char data[SIZE];
} STACK;

void push(STACK *s, char item) {
    if (s->top == SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    s->data[++(s->top)] = item;
}

char pop(STACK *s) {
    return (s->top == -1) ? (printf("Stack Underflow\n"), exit(1), 0) : s->data[(s->top)--];
}

int precedence(char c) {
    return (c == '^') ? 3 : (c == '*' || c == '/') ? 2 : (c == '+' || c == '-') ? 1 : 0;
}

void infixToPostfix(STACK *s, char *infix) {
    char postfix[SIZE], temp;
    int i = 0, j = 0;

    while (infix[i]) {
        if (isalnum(infix[i])) 
            postfix[j++] = infix[i];
        else if (infix[i] == '(') 
            push(s, infix[i]);
        else if (infix[i] == ')') {
           while (s->top != -1 && precedence(s->data[s->top]) >= precedence(infix[i])) 
                postfix[j++] = pop(s);
            push(s, infix[i]);
        }
        i++;
    }

    while (s->top != -1) 
        postfix[j++] = pop(s);

    postfix[j] = '\0';
    printf("Postfix: %s\n", postfix);
}

int main() {
    STACK s = { .top = -1 };
    char infix[SIZE];

    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixToPostfix(&s, infix);

    return 0;
}
