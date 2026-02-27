/* 
Implement linear search to find key k in an array. Count and display the number of comparisons 
performed.
*/

#include <stdio.h>

int main() {
    int n, k;
    int comparisons = 0;
    int found = -1;

    // Input size
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];

    // Input array elements
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input key to search
    printf("Enter key to search: ");
    scanf("%d", &k);

    // Linear search
    for (int i = 0; i < n; i++) {
        comparisons++;               // count comparison
        if (arr[i] == k) {
            found = i;
            break;
        }
    }

    // Output result
    if (found != -1) {
        printf("Found at index %d\n", found);
    } else {
        printf("Not Found\n");
    }

    printf("Comparisons = %d", comparisons);

    return 0;
}
