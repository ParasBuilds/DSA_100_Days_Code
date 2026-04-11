#include <stdio.h>

#define MAX 100
#define INF 99999999

// ───── Edge Structure (store all edges directly) ─────
// Bellman-Ford works on edge LIST, not adjacency list
typedef struct {
    int u, v, w;
} Edge;

Edge edges[MAX * MAX];   // store all edges
int  dist[MAX];
int  n, m;

// ───── Bellman-Ford Algorithm ─────
void bellmanFord(int src) {

    // Step 1: Initialize all distances as infinity
    for (int i = 0; i < n; i++)
        dist[i] = INF;
    dist[src] = 0;   // source to itself = 0

    // ── Step 2: Relax ALL edges exactly (n-1) times ──
    for (int pass = 1; pass <= n - 1; pass++) {

        int updated = 0;   // optimization: stop early if no update

        for (int i = 0; i < m; i++) {
            int u = edges[i].u;
            int v = edges[i].v;
            int w = edges[i].w;

            // Only relax if u is reachable
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v]  = dist[u] + w;
                updated  = 1;
            }
        }

        if (!updated) break;   // converged early → no more relaxations needed
    }

    // ── Step 3: nth relaxation → check for negative cycle ──
    for (int i = 0; i < m; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        if (dist[u] != INF && dist[u] + w < dist[v]) {
            // Distance still decreasing → negative cycle!
            printf("NEGATIVE CYCLE DETECTED\n");
            return;
        }
    }

    // ── Step 4: Print shortest distances ──
    printf("Shortest distances from source %d:\n", src);
    printf("Node\tDistance\n");
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF)
            printf("  %d\t  INF (unreachable)\n", i);
        else
            printf("  %d\t  %d\n", i, dist[i]);
    }
}

// ───── Main ─────
int main() {
    int src;

    printf("Enter vertices and edges (n m): ");
    scanf("%d %d", &n, &m);

    printf("Enter %d edges (u v w):\n", m);
    for (int i = 0; i < m; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);

    printf("Enter source vertex: ");
    scanf("%d", &src);

    bellmanFord(src);
    return 0;
}