#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10

int h[TABLE_SIZE] = {NULL};

void insert() {
    int key, hkey, index;
    printf("\nEnter value to insert into hash table: ");
    scanf("%d", &key);
    hkey = key % TABLE_SIZE;

    for (int i = 0; i < TABLE_SIZE; i++) {
        index = (hkey + i) % TABLE_SIZE;
        if (h[index] == NULL) {
            h[index] = key;
            printf("\nValue inserted at index %d\n", index);
            return;
        }
    }
    printf("\nTable is full, value not inserted\n");
}

void search() {
    int key, hkey, index;
    printf("\nEnter value to search: ");
    scanf("%d", &key);
    hkey = key % TABLE_SIZE;

    for (int i = 0; i < TABLE_SIZE; i++) {
        index = (hkey + i) % TABLE_SIZE;
        if (h[index] == key) {
            printf("\nValue found at index %d\n", index);
            return;
        }
    }
    printf("\nValue not found\n");
}

void display() {
    printf("\nElements in the hash table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: %d\n", i, h[i]);
    }
}

int main() {
    int ch;
    while (1) {
        printf("\n1. Insert\n2. Display\n3. Search\n4. Exit\n");
        printf("\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: insert(); break;
            case 2: display(); break;
            case 3: search(); break;
            default: exit(0);
        }
    }
    return 0;
}
