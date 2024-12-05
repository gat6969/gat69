#include <stdio.h>
#include <stdlib.h>

struct node {
    int co, po; // Coefficient and power
    struct node *next;
};
typedef struct node *NODE;

// Function to create a new node
NODE createNode(int co, int po) {
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->co = co;
    temp->po = po;
    temp->next = NULL;
    return temp;
}

// Function to add a term to the polynomial
NODE addTerm(NODE head, int co, int po) {
    NODE temp = head, prev = NULL, newNode = createNode(co, po);
    while (temp && temp->po > po) { // Traverse to correct position
        prev = temp;
        temp = temp->next;
    }
    if (temp && temp->po == po) { // Combine like terms
        temp->co += co;
        free(newNode);
    } else { // Insert new term
        newNode->next = temp;
        if (prev) prev->next = newNode;
        else head = newNode;
    }
    return head;
}

// Function to display a polynomial
void display(NODE head) {
    while (head) {
        printf("%dx^%d", head->co, head->po);
        if (head->next) printf(" + ");
        head = head->next;
    }
    printf("\n");
}

// Multiply two polynomials
NODE multiply(NODE poly1, NODE poly2) {
    NODE res = NULL, p1, p2;
    for (p1 = poly1; p1; p1 = p1->next)
        for (p2 = poly2; p2; p2 = p2->next)
            res = addTerm(res, p1->co * p2->co, p1->po + p2->po);
    return res;
}

int main() {
    NODE poly1 = NULL, poly2 = NULL, result = NULL;
    int n, co, po;

    printf("Enter number of terms for the first polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and power: ");
        scanf("%d %d", &co, &po);
        poly1 = addTerm(poly1, co, po);
    }

    printf("Enter number of terms for the second polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and power: ");
        scanf("%d %d", &co, &po);
        poly2 = addTerm(poly2, co, po);
    }

    printf("First Polynomial: ");
    display(poly1);

    printf("Second Polynomial: ");
    display(poly2);

    result = multiply(poly1, poly2);
    printf("Resultant Polynomial: ");
    display(result);

    return 0;
}
