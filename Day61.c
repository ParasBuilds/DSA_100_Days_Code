#include <stdio.h>

#define MAX 100

int matrix[MAX][MAX];   // adjacency matrix (global → auto-initialized to 0)

// ───── Add edge to matrix ─────
void addEdge(int u, int v, int directed) {
    matrix[u][v] = 1;

    if (!directed)
        matrix[v][u] = 1;   // undirected → both directions
}

// ───── Print the adjacency matrix ─────
void printMatrix(int n) {
    printf("\nAdjacency Matrix:\n");

    // Print column headers
    printf("   ");
    for (int i = 1; i <= n; i++)
        printf("%3d", i);
    printf("\n");

    // Print each row
    for (int i = 1; i <= n; i++) {
        printf("%2d ", i);               // row label
        for (int j = 1; j <= n; j++)
            printf("%3d", matrix[i][j]);
        printf("\n");
    }
}

int main() {
    int n, m, directed;

    printf("Enter number of vertices (n): ");
    scanf("%d", &n);

    printf("Enter number of edges   (m): ");
    scanf("%d", &m);

    printf("Directed graph? (1 = Yes, 0 = No): ");
    scanf("%d", &directed);

    printf("Enter %d edges (u v):\n", m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v, directed);
    }

    printMatrix(n);

    return 0;
}