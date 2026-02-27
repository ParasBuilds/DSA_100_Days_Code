/* 
A system receives two separate logs of user arrival times from two different servers. 
Each log is already sorted in ascending order. Your task is to create a single chronological log 
that preserves the correct order of arrivals.
*/



#include <stdio.h>

int main() {
    int p, q;
    int i = 0, j = 0, k = 0;

    // Input size of first log
    pritntf("Enter size of first log: ");
    scanf("%d", &p);
    int a[p];

    // Input first sorted log
    printf("Enter first sorted log: ");
    for (int i = 0; i < p; i++) {
        scanf("%d", &a[i]);
    }

    // Input size of second log
    printf("Enter size of second log: ");
    scanf("%d", &q);
    int b[q];

    // Input second sorted log
    printf("Enter second sorted log: ");
    for (int i = 0; i < q; i++) {
        scanf("%d", &b[i]);
    }
    
    int merged[p + q];

    // Merge both logs
    while (i < p && j < q) {
        if (a[i] <= b[j]) {
            merged[k++] = a[i++];
        } else {
            merged[k++] = b[j++];
        }
    }

    // Copy remaining elements of first log
    while (i < p) {
        merged[k++] = a[i++];
    }

    // Copy remaining elements of second log
    while (j < q) {
        merged[k++] = b[j++];
    }

    // Print merged log
    printf("Merged log: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", merged[i]);
    }

    return 0;
}
