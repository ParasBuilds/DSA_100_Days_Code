#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// ───── Adjacency List Node ─────
struct Node {
    int vertex;
    struct Node* next;
};

// ───── Graph ─────
struct Node* adjList[MAX];
int visited[MAX];
int n, m;

// ───── Create new node ─────
struct Node* newNode(int v) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->vertex = v;
    node->next   = NULL;
    return node;
}

// ───── Add edge (undirected) ─────
void addEdge(int u, int v) {
    // Add v to u's list
    struct Node* node = newNode(v);
    node->next   = adjList[u];
    adjList[u]   = node;

    // Add u to v's list
    node         = newNode(u);
    node->next   = adjList[v];
    adjList[v]   = node;
}

// ───── DFS (Recursive) ─────
void dfs(int src) {
    visited[src] = 1;           // mark current node visited
    printf("%d ", src);         // print current node

    // Visit all unvisited neighbours (go deeper first)
    struct Node* temp = adjList[src];
    while (temp != NULL) {
        if (!visited[temp->vertex])
            dfs(temp->vertex);  // recurse → go deep
        temp = temp->next;
    }
    // When loop ends → all paths from src explored → backtrack
}

// ───── Main ─────
int main() {
    int s;

    printf("Enter number of vertices (n): ");
    scanf("%d", &n);

    printf("Enter number of edges   (m): ");
    scanf("%d", &m);

    // Initialize lists and visited
    for (int i = 1; i <= n; i++) {
        adjList[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter %d edges (u v):\n", m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    printf("Enter source vertex: ");
    scanf("%d", &s);

    printf("\nDFS Traversal: ");
    dfs(s);
    printf("\n");

    return 0;
}