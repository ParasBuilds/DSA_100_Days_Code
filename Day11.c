/*
Problem: Write a program to perform addition of two matrices
having the same dimensions.
*/

#include <stdio.h>

int main() {
    int m, n;

    // Read dimensions
    printf("Enter rows and columns:  ");
    scanf("%d %d", &m, &n);

    int a[100][100], b[100][100], sum[100][100];

    // Read first matrix
    printf("Enter first matrix:\n");
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            scanf("%d", &a[i][j]);
        }
    }

    // Read second matrix
    printf("Enter second matrix:\n");
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            scanf("%d", &b[i][j]);
        }
    }

    // Add matrices
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }

    // Print result matrix
    printf("Result of addition:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    return 0;
}
