#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

typedef struct node *NODE;

// Function to create and insert a node
NODE insert(NODE root, int item) {
    if (!root) {
        root = (NODE)malloc(sizeof(struct node));
        root->data = item;
        root->left = root->right = NULL;
        return root;
    }
    if (item < root->data) 
        root->left = insert(root->left, item);
    else if (item > root->data) 
        root->right = insert(root->right, item);
    else 
        printf("Value %d already exists in the tree.\n", item); // Handle duplicates
    return root;
}

// Function for traversal (combined for Preorder, Inorder, Postorder)
void traverse(NODE root, int type) {
    if (!root) return;
    if (type == 0) printf("%d ", root->data); // Preorder
    traverse(root->left, type);
    if (type == 1) printf("%d ", root->data); // Inorder
    traverse(root->right, type);
    if (type == 2) printf("%d ", root->data); // Postorder
}

int main() {
    NODE root = NULL;
    int ch, item;
    while (1) {
        printf("\n1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n5. Exit\nChoice: ");
        scanf("%d", &ch);

        if (ch == 5) break;

        switch (ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &item);
                root = insert(root, item);
                break;
            case 2:
                printf("Preorder Traversal: ");
                traverse(root, 0); // Preorder
                printf("\n");
                break;
            case 3:
                printf("Inorder Traversal: ");
                traverse(root, 1); // Inorder
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal: ");
                traverse(root, 2); // Postorder
                printf("\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
