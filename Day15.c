/*
Problem: Given a matrix, calculate the sum of its primary diagonal elements.
The primary diagonal consists of elements where row index equals column index.
*/

#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int matrix[100][100];
    int sum = 0;

    // Read matrix
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculate primary diagonal sum
    printf("Calculating the sum of primary diagonal elements...\n");
    for (int i = 0; i < m && i < n; i++) {
        sum += matrix[i][i];
    }
printf("The sum of the primary diagonal elements is: ");
    printf("%d", sum);

    return 0;
}
