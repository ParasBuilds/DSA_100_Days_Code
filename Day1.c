/*

Write a C program to insert an element x at a given 1-based position pos in an array of n integers.
Shift existing elements to the right to make space.

*/

#include <stdio.h>

int main() {
    int n, pos, x;

    // Input size
    int arr[n];
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    // Input position
    printf("Enter position to insert (1-based index): ");
    scanf("%d", &pos);

    // Input element to insert
    printf("Enter element to insert: ");
    scanf("%d", &x);

    // Shift elements to the right
    for (int i = n; i >= pos; i--) 
    {
        arr[i] = arr[i - 1];
    }

    // Insert element
    arr[pos - 1] = x;

    // Print updated array
    printf("Updated array: ");
    for (int i = 0; i <= n; i++) 
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
