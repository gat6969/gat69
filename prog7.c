#include <stdio.h>
#include <stdlib.h>

struct node {
    int row, col, data;
    struct node *next;
};
typedef struct node *NODE;

NODE insertend(NODE start, int row, int col, int item) {
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->row = row;
    temp->col = col;
    temp->data = item;
    temp->next = NULL;
    if (start == NULL) return temp;
    NODE cur = start;
    while (cur->next) cur = cur->next;
    cur->next = temp;
    return start;
}

void display(NODE start) {
    printf("\nROW\tCOL\tDATA\n");
    for (NODE temp = start; temp; temp = temp->next)
        printf("%d\t%d\t%d\n", temp->row, temp->col, temp->data);
}

void displaymatrix(NODE start, int m, int n) {
    NODE temp = start;
    printf("\nSparse Matrix:\n");
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (temp && temp->row == i && temp->col == j) {
                printf("%d\t", temp->data);
                temp = temp->next;
            } else {
                printf("0\t");
            }
        }
        printf("\n");
    }
}

int main() {
    NODE start = NULL;
    int m, n, item;
    printf("Enter the matrix dimensions (rows and columns): ");
    scanf("%d%d", &m, &n);

    printf("Enter the matrix elements:\n");
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &item);
            if (item != 0) start = insertend(start, i, j, item);
        }
    }

    display(start);
    displaymatrix(start, m, n);
    return 0;
}
