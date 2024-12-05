#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

typedef struct {
    int top;
    int data[SIZE];
} STACK;

void push(STACK *s, int item) {
    if (s->top == SIZE - 1) 
        printf("Stack Overflow!\n");
    else 
        s->data[++s->top] = item, printf("%d pushed.\n", item);
}

void pop(STACK *s) {
    if (s->top == -1) 
        printf("Stack Underflow!\n");
    else 
        printf("%d popped.\n", s->data[s->top--]);
}

void display(STACK *s) {
    if (s->top == -1) 
        printf("Stack is empty.\n");
    else 
        for (int i = s->top; i >= 0; i--) 
            printf("%d\n", s->data[i]);
}

int main() {
    STACK s = { .top = -1 }; 
    int ch, item;
    while (1) {
        printf("\n1. Push  2. Pop  3. Display  4. Exit\nChoice: ");
        scanf("%d", &ch);
        if (ch == 1) printf("Enter element: "), scanf("%d", &item), push(&s, item);
        else if (ch == 2) pop(&s);
        else if (ch == 3) display(&s);
        else if (ch == 4) break;
        else printf("Invalid choice!\n");
    }
    return 0;
}
 