/*
Problem: Given a sorted array of n integers, remove duplicates in-place.
Print only the unique elements in order.
*/

#include <stdio.h>

int main() {
    int n;

    // Input size
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];

    // Input sorted array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // If array is empty
    if (n == 0) {
        return 0;
    }

    int k = 1;  // index for next unique element

    // Remove duplicates in-place
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[k - 1]) {
            arr[k] = arr[i];
            k++;
        }
    }

    // Print unique elements
    printf("Unique elements: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
