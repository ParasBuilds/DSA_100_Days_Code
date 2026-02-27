/*
Problem: Given an array of integers, find two elements whose sum
is closest to zero.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Comparison function for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    printf("Enter the size of array");
    scanf("%d", &n);

    int arr[100];

    // Read array
    printf("Enter the elements in the array :");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort array
    qsort(arr, n, sizeof(int), compare);

    int left = 0;
    int right = n - 1;
    int minSum = INT_MAX;
    int x = 0, y = 0;

    // Two-pointer approach
    while (left < right) {
        int sum = arr[left] + arr[right];

        if (abs(sum) < abs(minSum)) {
            minSum = sum;
            x = arr[left];
            y = arr[right];
        }

        if (sum < 0)
            left++;
        else
            right--;
    }

    printf("%d %d", x, y);

    return 0;
}