#include <stdio.h>
#include <stdbool.h>

#define MAX_V 1005 // Simple max limits for student tasks
#define INF 99999999

int graph[MAX_V][MAX_V];
int key[MAX_V];
bool inMST[MAX_V];

int main() {
    int n, m;
    
    // Read number of vertices and edges
    if (scanf("%d %d", &n, &m) != 2) return 0;

    // Initialize graph distances to Infinity
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = INF;
        }
        key[i] = INF;       // Infinite distance initially
        inMST[i] = false;   // No node is in MST yet
    }

    // Read edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        
        // As the graph is undirected, mark both ways
        // (In case of multiple edges between same vertices, keep the minimum)
        if(w < graph[u][v]) {
            graph[u][v] = w;
            graph[v][u] = w;
        }
    }

    // Always start Prim's algorithm from vertex 1
    key[1] = 0;
    long long totalWeight = 0;

    // A Minimum Spanning Tree will have exactly n vertices
    for (int count = 1; count <= n; count++) {
        
        // Step 1: Pick the minimum key vertex not yet included in the MST
        int minKey = INF;
        int u = -1;

        for (int i = 1; i <= n; i++) {
            if (inMST[i] == false && key[i] < minKey) {
                minKey = key[i];
                u = i;
            }
        }

        // If graph is disconnected and we can't find another node
        if (u == -1) break; 

        // Step 2: Include the chosen vertex in the MST
        inMST[u] = true;
        totalWeight += key[u];

        // Step 3: Update key values of adjacent vertices
        for (int v = 1; v <= n; v++) {
            // Update the key only if:
            // 1) There is an edge from u to v (not INF)
            // 2) v is not yet in the MST
            // 3) weight of edge u-v is smaller than the current key of v
            if (graph[u][v] != INF && inMST[v] == false && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    // Output the total weight of the Minimal Spanning Tree
    printf("%lld\n", totalWeight);

    return 0;
}