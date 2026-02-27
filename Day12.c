/*
Problem: Check whether a given matrix is symmetric.
A matrix is symmetric if:
1. It is a square matrix (m == n)
2. matrix[i][j] == matrix[j][i] for all i and j
*/

#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int matrix[100][100];

    // Read matrix
    printf("Enter the matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Check if square matrix
    if (m != n) {
        printf("Not a Symmetric Matrix");
        return 0;
    }

    int isSymmetric = 1;

    // Check symmetry condition
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                isSymmetric = 0;
                break;
            }
        }
        if (!isSymmetric)
            break;
    }

    if (isSymmetric)
        printf("Symmetric Matrix");
    else
        printf("Not a Symmetric Matrix");

    return 0;
}
