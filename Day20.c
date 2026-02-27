/*
Problem: Count the number of subarrays whose sum is zero.
*/

#include <stdio.h>

int main() {
    int n;
    printf("Enter the size of array");
    scanf("%d", &n);

    int arr[1000];
    printf("Enter the elements in the array :");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int count = 0;

    // Brute-force approach
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum == 0)
                count++;
        }
    }

    printf("%d", count);

    return 0;
}