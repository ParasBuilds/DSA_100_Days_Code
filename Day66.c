#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// ───── Adjacency List ─────
struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adjList[MAX];
int visited[MAX];
int recStack[MAX];   // tracks current DFS path
int n, m;

struct Node* newNode(int v) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->vertex = v;
    node->next   = NULL;
    return node;
}

// ───── DIRECTED edge only (u → v, not v → u) ─────
void addEdge(int u, int v) {
    struct Node* node = newNode(v);
    node->next  = adjList[u];
    adjList[u]  = node;
}

// ───── DFS with recursion stack ─────
int dfs(int curr) {
    visited[curr]  = 1;
    recStack[curr] = 1;   // add to current path

    struct Node* temp = adjList[curr];
    while (temp != NULL) {
        int nb = temp->vertex;

        if (!visited[nb]) {
            // Not visited → go deeper
            if (dfs(nb))
                return 1;

        } else if (recStack[nb]) {
            // Visited + in current path → BACK EDGE → cycle!
            return 1;
        }
        temp = temp->next;
    }

    recStack[curr] = 0;   // remove from path (backtrack)
    return 0;
}

int main() {
    printf("Enter vertices and edges (n m): ");
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        adjList[i]  = NULL;
        visited[i]  = 0;
        recStack[i] = 0;
    }

    printf("Enter %d directed edges (u v):\n", m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    int found = 0;
    for (int i = 0; i < n; i++)
        if (!visited[i])
            if (dfs(i)) { found = 1; break; }

    printf("%s\n", found ? "YES" : "NO");
    return 0;
}