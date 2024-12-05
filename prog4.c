#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define SIZE 20

typedef struct {
    int top;
    float data[SIZE];
} STACK;

void push(STACK *s, float item) {
    if (s->top == SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    s->data[++(s->top)] = item;
}

float pop(STACK *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->data[(s->top)--];
}

float evalPostfix(char *postfix) {
    STACK s = { .top = -1 };
    for (int i = 0; postfix[i] != '\0'; i++) {
        char symbol = postfix[i];
        if (isdigit(symbol)) {
            push(&s, symbol - '0');  // Convert char to float
        } else {
            float op2 = pop(&s), op1 = pop(&s);
            push(&s, (symbol == '+') ? op1 + op2 : 
                     (symbol == '-') ? op1 - op2 : 
                     (symbol == '*') ? op1 * op2 : 
                     (symbol == '/') ? (op2 ? op1 / op2 : (printf("Division by zero\n"), exit(1), 0)) : 
                     (symbol == '^') ? pow(op1, op2) : (printf("Invalid operator\n"), exit(1), 0));
        }
    }
    return pop(&s);
}

int main() {
    char postfix[SIZE];
    printf("Enter postfix expression: ");
    scanf("%s", postfix);
    printf("Final result: %.2f\n", evalPostfix(postfix));
    return 0;
}
