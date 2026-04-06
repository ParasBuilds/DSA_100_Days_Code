#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// ───── Adjacency List Node ─────
struct Node {
    int vertex;
    struct Node* next;
};

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

// ───── Add undirected edge ─────
void addEdge(int u, int v) {
    struct Node* node = newNode(v);
    node->next   = adjList[u];
    adjList[u]   = node;

    node         = newNode(u);
    node->next   = adjList[v];
    adjList[v]   = node;
}

// ───── DFS with parent tracking ─────
// Returns 1 if cycle found, 0 otherwise
int dfs(int curr, int parent) {
    visited[curr] = 1;   // mark current node visited

    struct Node* temp = adjList[curr];
    while (temp != NULL) {
        int neighbour = temp->vertex;

        if (!visited[neighbour]) {
            // Tree edge → go deeper, pass curr as parent
            if (dfs(neighbour, curr))
                return 1;               // cycle found deeper → bubble up

        } else if (neighbour != parent) {
            // Visited AND not our parent → BACK EDGE → cycle!
            return 1;
        }
        // If visited AND is parent → normal undirected edge, ignore

        temp = temp->next;
    }
    return 0;   // no cycle found from this node
}

// ───── Main ─────
int main() {
    printf("Enter number of vertices (n): ");
    scanf("%d", &n);

    printf("Enter number of edges   (m): ");
    scanf("%d", &m);

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

    int hasCycle = 0;

    // Check all components (graph may be disconnected)
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1)) {   // -1 = no parent for source node
                hasCycle = 1;
                break;
            }
        }
    }

    printf("%s\n", hasCycle ? "YES" : "NO");

    return 0;
}