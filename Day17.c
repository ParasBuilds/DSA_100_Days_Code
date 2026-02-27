/*
Problem: Find the maximum and minimum values in a given array.
*/

#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[100];

    // Read array elements
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Assume first element is both max and min
    int max = arr[0];
    int min = arr[0];

    // Traverse array
    printf("Finding the maximum and minimum values in the array...\n");
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];

        if (arr[i] < min)
            min = arr[i];
    }

    printf("Max: %d\n", max);
    printf("Min: %d", min);

    return 0;
}
