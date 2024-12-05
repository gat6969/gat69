#include <stdio.h> 
#include <stdlib.h>

void heapify(int a[], int n) {
    for (int i = n / 2; i >= 1; i--) {
        int k = i, v = a[k], j;
        while (2 * k <= n) {
            j = 2 * k;
            if (j < n && a[j] < a[j + 1]) j++;
            if (v >= a[j]) break;
            a[k] = a[j];
            k = j;
        }
        a[k] = v;
    }
}

int main() {
    int n, a[10], ch;
    while (1) {
        printf("\n1. Create Heap\n2. Extractmax\n3. Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter number of elements: ");
                scanf("%d", &n);
                printf("Enter elements:\n");
                for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
                heapify(a, n);
                printf("Heap: ");
                for (int i = 1; i <= n; i++) printf("%d ", a[i]);
                break;
            case 2:
                if (n >= 1) {
                    printf("Deleted element: %d\n", a[1]);
                    a[1] = a[n--];
                    heapify(a, n);
                    printf("Heap after extraction: ");
                    for (int i = 1; i <= n; i++) printf("%d ", a[i]);             
                }
                break;
            default:
                exit(0);
        }
    }
    return 0;
}
