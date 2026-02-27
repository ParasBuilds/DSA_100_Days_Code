/*
Problem: Check whether a given square matrix is an Identity Matrix.
*/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int matrix[100][100];
    int isIdentity = 1;

    // Read matrix
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Check identity condition
    printf("Checking if the matrix is an Identity Matrix...\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                if (matrix[i][j] != 1) {
                    isIdentity = 0;
                    break;
                }
            } else {
                if (matrix[i][j] != 0) {
                    isIdentity = 0;
                    break;
                }
            }
        }
        if (!isIdentity)
            break;
    }
printf("Result: ");
    if (isIdentity)
        printf("Identity Matrix");
    else
        printf("Not an Identity Matrix");

    return 0;
}
