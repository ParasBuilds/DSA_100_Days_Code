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
int n, m;

struct Node* newNode(int v) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->vertex = v;
    node->next   = NULL;
    return node;
}

void addEdge(int u, int v) {
    struct Node* node = newNode(v);   // u → v
    node->next  = adjList[u];
    adjList[u]  = node;

    node        = newNode(u);         // v → u (undirected)
    node->next  = adjList[v];
    adjList[v]  = node;
}

// ───── DFS ─────
void dfs(int curr) {
    visited[curr] = 1;

    struct Node* temp = adjList[curr];
    while (temp != NULL) {
        if (!visited[temp->vertex])
            dfs(temp->vertex);
        temp = temp->next;
    }
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        adjList[i] = NULL;
        visited[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    // Start DFS from node 1
    dfs(1);

    // Count visited nodes
    int count = 0;
    for (int i = 1; i <= n; i++)
        if (visited[i])
            count++;

    if (count == n)
        printf("CONNECTED\n");
    else
        printf("NOT CONNECTED\n");

    return 0;
}