/* 
Given an array of n integers, reverse the array in-place using two-pointer approach.
*/

#include <stdio.h>

int main() {
    int n;
    int left, right, temp;

    // Input size
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];

    // Input array elements
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Two-pointer approach
    left = 0;
    right = n - 1;

    // swapping elements using two-pointer approach
    while (left < right) {
        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }

    // Print reversed array
    printf("Reversed array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
