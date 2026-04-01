#include <stdio.h>

int arr[100];

// ───── Check Min-Heap Property ─────
// For node at index i:
//   left  child → 2*i + 1
//   right child → 2*i + 2
// All internal nodes have index 0 to (n/2 - 1)

int isMinHeap(int n) {
    // Check all internal nodes (nodes that have at least one child)
    for (int i = 0; i <= (n / 2) - 1; i++) {

        // Check left child (always exists for internal node)
        if (arr[i] > arr[2 * i + 1])
            return 0;   // parent > left child → NOT a min-heap

        // Check right child only if it exists
        if (2 * i + 2 < n) {
            if (arr[i] > arr[2 * i + 2])
                return 0;   // parent > right child → NOT a min-heap
        }
    }
    return 1;   // all checks passed
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    if (isMinHeap(n))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}